#include <DCMotor.h>
#include <Ping.h>
#include <IRremote.h>
/*
  Si sensor<TRIGGER esta sobre algo negro
  analizando, si el sensor esta sobre algo blanco recibe un valor de 35 aprox
*/
#define TRIGGER		950
#define MOTOR_SPEED	45.0
#define ALCANCE_OBJETIVO  15

float s0, s1, medicion;
int izq = 1;
int der = -1;
long randomDireccion = 0;
int giro = -1;
int giroRandomIni = tiempoCientoOchentaGrados()/2;
int giraRandomFin = (tiempoCientoOchentaGrados()/2) + tiempoCientoOchentaGrados();
	
int tiempoEstrategia = 30000;
int codigoActivo = 0;

DCMotor motor0(M0_EN, M0_D0, M0_D1);
DCMotor motor1(M1_EN, M1_D0, M1_D1);
PingSensor ping(A1); //S1 input
IRrecv irReceiver(A4);
  
void setup()
{
  Serial.begin(115200);
  motor1.setClockwise(false);
  delay(2000);//ESPERA DOS SEGUNDOS!
  /*
  * Empieza a girar hasta encontrar al objetivo
  */
  //motor0.setSpeed(MOTOR_SPEED);
  //motor1.setSpeed(-1*MOTOR_SPEED);  
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);  
  
}

void loop()
{
  int code = irReceiver.getIRRemoteCode();  
  delay(200);
  
	if(code == 1 || code == 2 || code == 3 || code == 4 || code == 5){    
		codigoActivo = code;
	} 

	if (codigoActivo == 1)
	{
		atacar();
	}
	else if (codigoActivo == 2)
	{
		retirada();
	}
	else if (codigoActivo == 3)
	{
		estrategiaRandom();
	}
	else if (codigoActivo == 4)
	{
		esquivarYAtacar();
	}
	else 
	{
		motor0.brake();
		motor1.brake();
	}
     
   
   
  //esquivarYAtacar();
  //atacar();
  //emitirSonido();
  //retirada();
  //estrategiaRandom();  
}

int tiempoCientoOchentaGrados(){  
  return (int)(100/MOTOR_SPEED)*600;
}

boolean moverseSinSalirDelCampo(unsigned long intervalo, int dirMotor0, int dirMotor1){
    unsigned long inicial = millis();    

    s0 = analogRead(2);
    s1 = analogRead(3);    
    motor0.setSpeed(dirMotor0*MOTOR_SPEED);
    motor1.setSpeed(dirMotor1*MOTOR_SPEED);
    boolean verifica = true;

    while((millis() < inicial + intervalo) && verifica){ 
        delay(20);    
        if ((s0> TRIGGER) || (s1 >TRIGGER)){
          verifica = false;    
          reversaParasalirDelBorde(1000);         
        }
        s0 = analogRead(2);
        s1 = analogRead(3);
    }
    motor0.brake();
    motor1.brake();
    return verifica;
}

void reversaParasalirDelBorde(unsigned long intervalo){
    unsigned long inicial = millis(); 
    motor0.setSpeed(-1*MOTOR_SPEED);
    motor1.setSpeed(-1*MOTOR_SPEED);
    while((millis() < inicial + intervalo)){        
      //tendria q ver si el sensor esta atras
    }
    motor0.brake();
    motor1.brake();
}

void atacar(){
  delay(50);
  s0 = analogRead(2);
  s1 = analogRead(3);  
  
  if(( ping.measureCM() < ALCANCE_OBJETIVO ) && (s0<TRIGGER) && (s1<TRIGGER)){
    //si estoy apuntando a un objeto y no estoy pisando la linea negra
    delay(20);//delay para apuntar un poco mas al objeto
    motor0.setSpeed(MOTOR_SPEED);
    motor1.setSpeed(MOTOR_SPEED);
    giro = giro * -1;
  }
  if((s0>TRIGGER) || (s1>TRIGGER)){
    delay(20);
    reversaParasalirDelBorde(1200);
    randomDireccion = random(0,10)%2;
    if(randomDireccion == 0){
      izq = -1;
      der = 1;
    }else{
      izq = 1;
      der = -1;
    }    
    //moverseSinSalirDelCampo(random(1500,2000), izq, der);//aca esta el error, entre 1500 y 2000 es demasiado
	moverseSinSalirDelCampo(random(giroRandomIni,giroRandomFin), izq, der);
    moverseSinSalirDelCampo(1500, 1, 1);
  } 
  if (ping.measureCM() > ALCANCE_OBJETIVO){
    //si no pasa nada giro
    motor0.setSpeed(MOTOR_SPEED * giro);
    motor1.setSpeed(-1*MOTOR_SPEED * giro);
  }  
}

void retirada(){//esto en realidad no iria, lo puse para ver si el programa final puede bancarselo
//Read sensors:
  delay(20);//delay para el ultrasonido
  s0 = analogRead(2);
  s1 = analogRead(3);
  if(( ping.measureCM() < ALCANCE_OBJETIVO )){
    //si estoy apuntando a un objeto o estoy pisando la linea negra
    if((s0>TRIGGER) || (s1>TRIGGER)){
      motor0.brake();
      motor1.brake();
      delay(20);
      reversaParasalirDelBorde(1200);
    }else{
      randomDireccion = random(0,10)%2; //Para elegir a donde giro de forma random; par izq, impar der
      if(randomDireccion == 0){
        izq = -1;
        der = 1;
      }else{
        izq = 1;
        der = -1;
      }
      //moverseSinSalirDelCampo(random(1500,2000), izq, der);//giro 180 grados mas o menos, puede variar segun la superficie y el nivel de bateria
	  moverseSinSalirDelCampo(random(giroRandomIni,giroRandomFin), izq, der);
      moverseSinSalirDelCampo(2000, 1, 1);//me voy hacia adelante
    }
  }else{
    //Serial.println("giro");
    motor0.setSpeed(MOTOR_SPEED);
    motor1.setSpeed(-1*MOTOR_SPEED);
  }
}

void esquivarYAtacar(){  
  
  delay(30);
  s0 = analogRead(2);
  s1 = analogRead(3);
  
  delay(30);
  medicion = ping.measureCM();
  
  if(( medicion < ALCANCE_OBJETIVO ) && (s0<TRIGGER) && (s1<TRIGGER)){
    //si estoy apuntando a un objeto y no estoy pisando la linea negra
    randomDireccion = random(0,10)%2; //Para elegir a donde giro de forma random; par izq, impar der
    if(randomDireccion == 0){
      izq = -1;
      der = 1;
    }else{
      izq = 1;
      der = -1;
    }
    //La idea es hacer una 'L'
    if (moverseSinSalirDelCampo(tiempoCientoOchentaGrados()/2, izq, der))//giro 90 grados mas o menos, puede variar segun la superficie y el nivel de bateria
      if (moverseSinSalirDelCampo(1000, 1, 1))//me voy hacia adelante
        if (moverseSinSalirDelCampo(tiempoCientoOchentaGrados()/2, -1*izq, -1*der))//giro 90 grados mas o menos, puede variar segun la superficie y el nivel de bateria
          if (moverseSinSalirDelCampo(1000, 1, 1))//me voy hacia adelante
            if (moverseSinSalirDelCampo(tiempoCientoOchentaGrados()/2, -1*izq, -1*der)){//giro 90 grados mas o menos, puede variar segun la superficie y el nivel de bateria
               moverseSinSalirDelCampo(1000, 1, 1);//me voy hacia adelante   
               contraatacar(5000);//esto es espartaaaaaaa!
            }
  }
  else if(s0>TRIGGER && s1>TRIGGER){
    delay(30);
    reversaParasalirDelBorde(750);   
    moverseSinSalirDelCampo(tiempoCientoOchentaGrados(), 1, -1);
    moverseSinSalirDelCampo(1200, 1, 1);
  }  
  else if(s0>TRIGGER){
    delay(30);
    reversaParasalirDelBorde(750);   
    moverseSinSalirDelCampo(tiempoCientoOchentaGrados()/2, 1, -1);
    moverseSinSalirDelCampo(1200, 1, 1);
  }else if(s1>TRIGGER){
    delay(30);
    reversaParasalirDelBorde(750);
    moverseSinSalirDelCampo(tiempoCientoOchentaGrados()/2, -1, 1);
    moverseSinSalirDelCampo(1200, 1, 1);
  }  
  else{
    //si no pasa nada giro
    //motor0.setSpeed(MOTOR_SPEED);
    //motor1.setSpeed(-1*MOTOR_SPEED);
  }  

}

void contraatacar(unsigned long intervalo){
    unsigned long inicial = millis(); 
    float medicion;
    boolean estado = false;
    int izq = 1;
    int der = -1;
    int alcance = 25;
    
    while((millis() < inicial + intervalo) || estado){      
      medicion = ping.measureCM();
      delay(20);
      
      if(medicion < alcance){
        atacar();
        estado = true;
      }else{
        delay(20);
        if (!rotar(680,izq,der)){          
          izq = izq * -1;
          der = der * -1;
          estado = false;
        }
      }      
    }  
}

boolean rotar(unsigned long intervalo, int dirMotor0, int dirMotor1){
    unsigned long inicial = millis();    
    s0 = analogRead(2);
    s1 = analogRead(3);    
    motor0.setSpeed(dirMotor0*MOTOR_SPEED);
    motor1.setSpeed(dirMotor1*MOTOR_SPEED);
    boolean verifica = false;

    while((millis() < inicial + intervalo) && !verifica){ 
        s0 = analogRead(2);
        s1 = analogRead(3);
        delay(20);    
        if (ALCANCE_OBJETIVO > ping.measureCM()){
          verifica = true;             
        }
    }
    motor0.brake();
    motor1.brake();
    return verifica;
}

void emitirSonido(){
  toneDelay(SPEAKER, 659, 2);
  toneDelay(SPEAKER, 659, 4);
  toneDelay(SPEAKER, 3520, 4); 
}

void estrategiaRandom(){
  int randomEstrategia = random(0,2);
  unsigned long inicial = millis();
      
      while((millis() < inicial + tiempoEstrategia )){        
            if(randomEstrategia == 0){
              atacar();
            }else{
              retirada();
            }
    }
}
