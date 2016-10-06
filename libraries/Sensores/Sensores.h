#ifndef Sensores__h
#define Sensores__h

#include <Ping.h>
#include <IRremote.h>

#define distancia_max 25
#define distancia_min 2


//Sensores en pista de cartulina:

#define sensor_izq_blanco 850
#define sensor_izq_negro 400

#define sensor_der_blanco 480
#define sensor_der_negro 300

#define sensor_tras_blanco 200
#define sensor_tras_negro 180


//Sensores en pista de madera:
/*
#define sensor_izq_blanco 700   //sensor_izq Blanco si mayor a
                                //sensor_izq Gris entre 100 y 800
#define sensor_izq_negro 100    //sensor_izq Negro si menor a

#define sensor_der_blanco 500   //sensor_der Blanco si mayor a
                                //sensor_der Gris entre 90 y 900
#define sensor_der_negro 90     //sensor_der Negro si menor a

#define sensor_tras_blanco 200  //sensor_tras Blanco si mayor a
                                //sensor_tras Gris entre 40 y 180
#define sensor_tras_negro 30    //sensor_tras Negro si menor a
*/





class Sensores
{
	private:
    IRrecv irReceiver; //S0 input
    PingSensor ping;

	public:
		 Sensores(IRrecv irReceiver,PingSensor ping): 	irReceiver(irReceiver),
																												ping(ping)
																												{

																												}
      /* Devuelve el valor que mide el sensor*/

      float sensor_US();

      float sensor_izq();

      float sensor_der();

      float sensor_tras();

      int sensor_IR();


      /*test_blanco revisa si los sensores de adelante estan en blanco*/
      boolean test_blanco();

      /*test_blanco_izq revisa si el sensor izquierdo está sobre blanco*/
      boolean test_blanco_izq();

      /*test_blanco_der revisa si el sensor derecho está sobre blanco*/
      boolean test_blanco_der();

      /*test_blanco_tras revisa si el sensor trasero está sobre blanco*/
      boolean test_blanco_tras();

      void prueba_sensores();
};

#endif
