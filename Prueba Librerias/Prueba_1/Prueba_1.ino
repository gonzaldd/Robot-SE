#include <DCMotor.h>
#include <Ping.h>
#include <IRremote.h>
#include <Movimiento.h>
#include <Sensores.h>
#include <Estrategias.h>
  

DCMotor motor0(M0_EN, M0_D0, M0_D1, false);
DCMotor motor1(M1_EN, M1_D0, M1_D1, false);

  


IRrecv irReceiver(A0); //S0 input
PingSensor ping(A1);
Movimiento mov = Movimiento(motor0, motor1);
Sensores sen = Sensores(irReceiver,ping);
Estrategias est = Estrategias(sen,mov);
int codigoActivo;


void setup()
{
  Serial.begin(115200);
  pinMode(25, INPUT);
  digitalWrite(25, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(1000); 

}

void loop()
{
  int code = irReceiver.getIRRemoteCode();
  
  if(code == 1 || code == 2 || code == 3 || code == 4 || code == 5 || code == 6 || code == 7 || code == 8 || code == 9){
    codigoActivo = code;
    digitalWrite(13, LOW);
    if(code == 2){
      digitalWrite(13, HIGH);
    }
  }
  
  if( codigoActivo == 1){
    est.recorrer();
  }else if(codigoActivo == 2){
    est.recorrerAtacar();
  }else if(codigoActivo == 3 ){
    mov.frenar();
  }else if(codigoActivo == 4){
    est.recorrer_random();
  }else if(codigoActivo == 5){
    est.recorrerEscapar();
  }
  
}
