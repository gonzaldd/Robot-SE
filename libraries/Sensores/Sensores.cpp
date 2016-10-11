#include <Sensores.h>
#include <Arduino.h>



int Sensores::sensor_IR()
{
  return irReceiver.getIRRemoteCode();
}
float Sensores::sensor_US()
{
  return ping.measureCM();
}
/*
float Sensores::Sensores::sensor_izq()
{
  return analogRead(2);
}

float Sensores::sensor_der()
{
  return analogRead(3);
}

float Sensores::sensor_tras()
{
  return analogRead(5);
}
*/

float Sensores::Sensores::sensor_izq()
{
  return map(analogRead(A2), 0, 1023, 0.0, 5.0);
}

float Sensores::sensor_der()
{
  return map(analogRead(A3), 0, 1023, 0.0, 5.0);
}

float Sensores::sensor_tras()
{
  return map(analogRead(A5), 0, 1023, 0.0, 5.0);
}

boolean Sensores::test_blanco()
{ /*
  boolean retorno = false;
  if(sensor_izq() >= sensor_izq_blanco || sensor_der() >= sensor_der_blanco)
  {
    delay(100);
    if(sensor_izq() >= sensor_izq_blanco || sensor_der() >= sensor_der_blanco)
    {
      retorno = true;
    }
  }*/
  return (sensor_der() >= 2 || sensor_izq() > 3);
}

boolean Sensores::test_blanco_izq()
{
  return (sensor_izq() >= sensor_izq_blanco && sensor_der() <= sensor_der_negro);
}

boolean Sensores::test_blanco_der()
{
  return (sensor_izq() <= sensor_izq_negro && sensor_der() >= sensor_der_blanco);
}

boolean Sensores::test_blanco_tras()
{
  return !(sensor_tras() < 1);
}

void Sensores::prueba_sensores()
{
  Serial.println("Sensor Izq ");
  Serial.println(sensor_izq());
  Serial.println("Sensor Der ");
  Serial.println(sensor_der());
  Serial.println("Sensor US");
  Serial.println(sensor_US());
  Serial.println("Sensor Trasero");
  Serial.println(sensor_tras());
  if(test_blanco())
    Serial.println("Está en blanco");
  else
    Serial.println("No está en blanco");
  delay(1500);

}
