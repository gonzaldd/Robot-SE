#include <Ping.h>
#include <IRremote.h>

#define sensor_izq_blanco 800   //sensor_izq Blanco si mayor a
                                //sensor_izq Gris entre 100 y 800
#define sensor_izq_negro 100    //sensor_izq Negro si menor a

#define sensor_der_blanco 900   //sensor_der Blanco si mayor a
                                //sensor_der Gris entre 90 y 900
#define sensor_der_negro 90     //sensor_der Negro si menor a

#define sensor_tras_blanco 200  //sensor_tras Blanco si mayor a
                                //sensor_tras Gris entre 40 y 180
#define sensor_tras_negro 50    //sensor_tras Negro si menor a

#define sensor_US_distancia 13  //Distancia en cm

float sensor_US();

float sensor_izq();

float sensor_der();

float sensor_tras();

int sensor_IR();

boolean test_blanco();

boolean test_blanco_izq();

boolean test_blanco_der();

boolean test_blanco_tras();
