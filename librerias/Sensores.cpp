#include "Sensores.h"

IRrecv irReceiver(A0); //S0 input

PingSensor ping(A1);

int sensor_IR()
{
  return irReceiver.getIRRemoteCode();
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
