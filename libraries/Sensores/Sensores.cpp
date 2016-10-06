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


boolean Sensores::test_blanco()
{
  boolean retorno = false;
  if(sensor_izq() > sensor_izq_blanco || sensor_der() > sensor_der_blanco)
  {
    delay(100);
    if(sensor_izq() > sensor_izq_blanco || sensor_der() > sensor_der_blanco)
    {
      retorno = true;
    }
  }
  return retorno;
}

boolean Sensores::test_blanco_izq()
{
  return (sensor_izq() > sensor_izq_blanco && sensor_der() < sensor_der_negro);
}

boolean Sensores::test_blanco_der()
{
  return (sensor_izq() < sensor_izq_negro && sensor_der() > sensor_der_blanco);
}

boolean Sensores::test_blanco_tras()
{
  boolean retorno = false;
  if(sensor_tras() > sensor_tras_blanco)
  {
    delay(50);
    if(sensor_tras() > sensor_tras_blanco)
    {
      retorno = true;
    }
  }
  return retorno;
}

void Sensores::prueba_sensores()
{
  Serial.println("Sensor Izq ");
  Serial.println(sensor_izq());
  Serial.println("Sensor Der ");
  Serial.println(sensor_der());
  Serial.println("Sensor US");
  Serial.println(sensor_US());
  delay(1500);

}
