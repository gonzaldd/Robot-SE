#ifndef DCMotor__h
#define DCMotor__h

#define velocidad_full 90.0
#define velocidad_media 60.0
#define velocidad_baja 30.0
#define velocidad_giro 60

#define delay_360_1 1820 //El delay corresponde con la velocidad de giro 60.
#define delay_180_1 1000 //TODO Hay que ajustar los delays, girar a la izquierda y a la dercha necesitan distinto delay
                         //Estos delays son para girar a la derecha

#include "DcMotor.h"

void frenar();

void avanzar_full();

void avanzar_media();

void avanzar_baja();

void reversa_full();

void reversa_media();

void reversa_baja();

void avanzar_full_der();

void avanzar_full_izq();

void avanzar_media_der();

void avanzar_media_izq();

void reversa_full_der();

void reversa_full_izq();

void reversa_media_der();

void reversa_media_izq();

void girar_360_der();

//Hay que ajustar los delays, girar a la izquierda y a la dercha necesitan distinto delay
void girar_360_izq();

void girar_180_der();
//Hay que ajustar los delays, girar a la izquierda y a la dercha necesitan distinto delay
void girar_180_izq();

#endif
