#include <DCMotor.h>
#include <Ping.h>
#include <IRremote.h>
/*
#define minimoGris 100 //Valor menor a 100 NEGRO
                       // Gris Valores entre 100 y 400
#define maximoGris 400 //Valor mayor a 400 BLANCO*/
#define distancia 15

#define velocidad_full 90.0
#define velocidad_media 60.0
#define velocidad_baja 30.0
#define velocidad_giro 60


#define sensor_izq_blanco 800
                        //sensorIzqGris
#define sensor_izq_negro 100

#define sensor_der_blanco 900
                        //sensorDerGris
#define sensor_der_negro 90

#define sensor_tras_blanco 200
                            // sensorTrasGris entre 40 y 180
#define sensor_tras_negro 50


#define sensor_US_distancia 13

IRrecv irReceiver(A0); //S0 input
PingSensor ping(A1);
DCMotor motor0(M0_EN, M0_D0, M0_D1);
DCMotor motor1(M1_EN, M1_D0, M1_D1);

void setup()
{
  Serial.begin(115200);
  pinMode(25, INPUT);
  digitalWrite(25, HIGH);
  motor0.setClockwise(false);
  motor1.setClockwise(false);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(7000);
}

void loop()
{
   int code = irReceiver.getIRRemoteCode();
   int i = 0;
   while(i<=4200 && !sensor_US_cerca())
   {
     
     if(i<=1000)
     {
       while (i<=1000 && !test_blanco())
       {
         avanzar_media();
         delay(5);
         i++;
       }
       frenar();
     }
     //delay(2000);
     
     
     if(i <= 2000)
     {
       while (i<=2000 && !test_blanco_tras())
       {
         reversa_media();
         delay(5);
         i++;
       }
     }
     
     if(i<=2200)
     {
       while (i<=2200 && !test_blanco())
       {
         avanzar_media_der();
         delay(5);
         i++;
       }
     }
     frenar();
     if(i<=3200)
     {
       while(i<=3200 && !test_blanco() && !test_blanco_tras())
       {
         giro_der();
         delay(2);
         i++;
       }
     }
    
    if (i<=4200)
    {
      while(i<=4200 && !test_blanco() && !test_blanco_tras())
       {
         giro_izq();
         delay(2);
         i++;
       }
    }
    
     int j = 0;
     if(test_blanco_izq() && test_blanco_tras())
     {
       while(j<=200 && !test_blanco_der())
       {
         avanzar_media_der();
         delay(3);
         j++;
       }
     }
     
     
     j=0;
     if(test_blanco_der() && test_blanco_tras())
     {
       while(j<=200 && !test_blanco_izq())
       {
         avanzar_media_izq();
         delay(3);
         j++;
       }
     }
   }
   
   if(sensor_US_cerca())
   {
    while(sensor_US_cerca())
    {
     avanzar_full();
    }
   } 
   frenar();
}

void recorrer_pista()
{
  int i = 0;
   
   while (i<=1000 && !test_blanco()){
    avanzar_media();
    delay(5);
    i++;
   }
   frenar();
   //delay(2000);
   
   i = 0;
   while (i<=1000 && !test_blanco_tras()){
    reversa_media();
    delay(5);
    i++;
   }
   
   i = 0;
   while (i<=200 && !test_blanco()){
    avanzar_media_der();
    delay(5);
    i++;
   }
   
   /*if(test_blanco_izq()) reversa_media_der();
   else if (test_blanco_der()) reversa_media_izq();
   else reversa_media();
   
   delay(i*5);*/
   frenar();
   //delay(1000);   
   i=0;
   while(i<=1000 && !test_blanco() && !test_blanco_tras())
   {
     giro_der();
     delay(2);
     i++;
   }
//   delay(1000);
   i=0;
  while(i<=1000 && !test_blanco() && !test_blanco_tras())
   {
     giro_izq();
     delay(2);
     i++;
   }
   
   i=0;
   
   if(test_blanco_izq() && test_blanco_tras())
   {
     while(i<=200 && !test_blanco() && !test_blanco_tras())
     {
       avanzar_media_izq();
       delay(3);
       i++;
     }
   }
   
   i=0;
   
   if(test_blanco_der() && test_blanco_tras())
   {
     while(i<=200 && !test_blanco() && !test_blanco_tras())
     {
       avanzar_media_der();
       delay(3);
       i++;
     }
   }
  // delay(2000);
}

float sensor_US()
{
  return ping.measureCM();
}

float sensor_izq()
{
  return analogRead(2);
}

float sensor_der()
{
  return analogRead(3);
}

float sensor_tras()
{
  return analogRead(5);
}


void frenar()
{
  motor0.brake();
  motor1.brake();
}

void avanzar_full()
{
  motor0.setSpeed(velocidad_full);
  motor1.setSpeed(velocidad_full);
}

void avanzar_media()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_media);
}

void avanzar_baja()
{
  motor0.setSpeed(velocidad_baja);
  motor1.setSpeed(velocidad_baja);
}

void reversa_full()
{
  motor0.setSpeed(-velocidad_full);
  motor1.setSpeed(-velocidad_full);
}

void reversa_media()
{
  motor0.setSpeed(-velocidad_media);
  motor1.setSpeed(-velocidad_media);
}

void reversa_baja()
{
  motor0.setSpeed(-velocidad_baja);
  motor1.setSpeed(-velocidad_baja);
}

void avanzar_full_der()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_full);
}

void avanzar_full_izq()
{
  motor0.setSpeed(velocidad_full);
  motor1.setSpeed(velocidad_media);
}

void avanzar_media_der()
{
  motor0.setSpeed(velocidad_baja);
  motor1.setSpeed(velocidad_media);
}

void avanzar_media_izq()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_baja);
}

void reversa_full_der()
{
 motor0.setSpeed(-velocidad_media);
 motor1.setSpeed(-velocidad_full); 
}

void reversa_full_izq()
{
  motor0.setSpeed(-velocidad_full);
  motor1.setSpeed(-velocidad_media);
}

void reversa_media_der()
{
  motor0.setSpeed(-velocidad_baja);
  motor1.setSpeed(-velocidad_media);
}

void reversa_media_izq()
{
  motor0.setSpeed(-velocidad_media);
  motor1.setSpeed(-velocidad_baja);
}

boolean test_blanco()
{
  return (sensor_izq() > sensor_izq_blanco || sensor_der() > sensor_der_blanco);
}

boolean test_blanco_izq()
{
  return (sensor_izq() > sensor_izq_blanco && sensor_der() < sensor_der_negro);
}

boolean test_blanco_der()
{
  return (sensor_izq() < sensor_izq_negro && sensor_der() > sensor_der_blanco);
}

boolean test_blanco_tras()
{
  return (sensor_tras() > sensor_tras_blanco);
}

void giro_izq()
{
  motor0.setSpeed(velocidad_giro);
  motor1.setSpeed(-velocidad_giro);
}

void giro_der()
{
  motor0.setSpeed(-velocidad_giro);
  motor1.setSpeed(velocidad_giro);
}

boolean sensor_US_cerca()
{
  return sensor_US() < sensor_US_distancia;
}


//void reversa_si_blanco()^

/*
void comenzarAtaque()
{
  motor0.setSpeed(-90.0);
  motor1.setSpeed(-90.0);
  delay(500);
  motor0.setSpeed(0.0);
  motor1.setSpeed(0.0);
  delay(500)
  dir = decidirDireccion();
  if (dir == 0)
  {
    giro(-1);
  }
  else if (dir == 1)
  {
    giro(1);    
  }  
  buscarEmbestir(dir);  
}

void irAlCentro()
{
  motor0.setSpeed(40.0);
  motor1.setSpeed(-95.0); //Revisar giro   
  if( (s2 >= minimoGris ) && ( s2 <= maximoGris) )
  {
    motor0.brake;
  }  
  else if ( (s3 >= minimoGris ) && ( s3 <= maximoGris) )
  {
    motor1.brake; //
    if ( (s2 < minimoGris ) && ( s2 > maximoGris) ) motor0.setSpeed(70.0);   
  }     
}  

void buscarAtacar();
{
  if (ping.measureCM()>distancia) 
  {
    motor0.setSpeed(70.0);
    motor1.setSpeed(-70.0);    
  }
  else
  {
    motor0.setSpeed(-95.0);
    motor1.setSpeed(-95.0);
    delay(3000);
    motor0.setSpeed(0.0);
    motor1.setSpeed(0.0);
  }
}

void marchaAtras()
{
  motor0.setSpeed(-95.0);
  motor1.setSpeed(-95.0);
  delay(800); 
  buscarAtacar();
}


int decidirDireccion()
{
  int valor = random(0, 2);
  return valor;
}

void giro(int sentido) // -1 para izquierda,1 para derecha
{
  float velocidad1=95.0, velocidad2 = 45.0;
  motor0.setSpeed(sentido * 75.0);
  motor1.setSpeed(sentido * -75.0);
  delay(300)
  if (sentido == -1)
  {
    motor0.setSpeed(velocidad1);
    motor1.setSpeed(veloidad2);
  }
  else //if(sentido == 1)
  {
    motor0.setSpeed(velocidad2);
    motor1.setSpeed(velocidad1);
  }
  delay(2000)
  motor0.setSpeed(0.0);
  motor1.setSpeed(0.0);  
}

void buscarEmbestir(int sentido)
{
    if (ping.measureCM()>distancia) 
  {
    if (sentido == 0)
    {
      motor0.setSpeed(70.0);
      motor1.setSpeed(-70.0);
    }
    else //if (sentido == 1)
    {
      motor0.setSpeed(-70.0);
      motor1.setSpeed(70.0);   
    }      
  }
  else
  {
    motor0.setSpeed(-95.0);
    motor1.setSpeed(-95.0);
    delay(2000);
    motor0.setSpeed(0.0);
    motor1.setSpeed(0.0);
  } 
}
*/
