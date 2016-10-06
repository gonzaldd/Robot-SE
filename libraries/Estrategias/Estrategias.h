#ifndef Estrategias__h
#define Estrategias__h

#include "Movimiento.h"
#include "Sensores.h"
#define sensor_US_distancia_max 35  //Si el obstáculo está en ese rango
#define sensor_US_distancia_min 10
#define sensor_US_saturado 3000 //Tira valores mayores a 3000 cuando esta pegado
#define sensor_US_nada 150



class Estrategias
{
	private:
    Sensores sen;
    Movimiento mov;

	public:
		 Estrategias(Sensores sen, Movimiento mov): sen(sen),
                                                mov(mov)
                                                {

                                                }

      //Estrategias Pasivas



      void avanzar_media_hasta_blanco();
      void reversa_media_hasta_blanco();

      void giro_der_hasta_blanco();
      void giro_izq_hasta_blanco();

      void avanzar_media_der_hasta_blanco();
      void avanzar_media_izq_hasta_blanco();

      void reversa_media_der_hasta_blanco();
      void reversa_media_izq_hasta_blanco();

      void recorrer(); //Recorrer la pista

      //Estrategias Agresivas
      void atacar();

      void avanzar_media_y_atacar();
      void avanzar_media_izq_y_atacar();
      void avanzar_media_der_y_atacar();

      void reversa_media_y_atacar();
      void reversa_media_izq_y_atacar();
      void reversa_media_der_y_atacar();

      void giro_der_y_atacar();
      void giro_izq_y_atacar();

      void recorrer_y_atacar(); //Recorrer la pista, si detecta objetivo, atacar.

      //Estrategias Mariconas
      void escapar_y_frenar();
      void escapar_hasta_blanco();

      //Estrategias Pasivo Agresivas
      void escapar_y_atacar();


      boolean condicion_frenado_avanzar();
      boolean condicion_frenado_reversa();
      boolean condicion_frenado();
      boolean sensor_US_cerca();
      boolean sensor_US_pegado();


};

#endif
