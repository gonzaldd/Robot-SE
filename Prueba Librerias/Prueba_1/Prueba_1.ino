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



void setup()
{
  Serial.begin(115200);
  pinMode(25, INPUT);
  digitalWrite(25, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(5000);
  

}

void loop()
{
//4
est.escapar_y_frenar();
//    sen.prueba_sensores();
    /*
    while(!sen.test_blanco())
    {
      mov.avanzar_baja();
    }
    Serial.println("Test blanco izq");
    Serial.println(sen.test_blanco_izq());
    Serial.println("Test blanco der");
    Serial.println(sen.test_blanco_der());
    mov.frenar();
    delay(3000);*/
/*
Serial.println("Sensor Izq:");
Serial.println(sen.sensor_izq());
Serial.println("Sensor Der:");
Serial.println(sen.sensor_der());
Serial.println("Sensor Tras:");
Serial.println(sen.sensor_tras());
delay(1500);
*/
}
