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


//frenar: Detener los motores
void frenar();

//avanzar_full: Encender los motores a la velocidad_full
void avanzar_full();

//avanzar_media: Encender los motores a la velocidad_media
void avanzar_media();

//avanzar_baja: Encender los motores a la velocidad_baja
void avanzar_baja();

//reversa_full: Encender los motores a la -velocidad_full
void reversa_full();

//reversa_media: Encender los motores a la -velocidad_media
void reversa_media();

//reversa_baja: Encender los motores a la -velocidad_baja
void reversa_baja();

//avanzar_full_der: Encender el motor izquierdo a velocidad_full y el derecho a velocidad_media
void avanzar_full_der();

//avanzar_full_izq: Encender el motor derecho a velocidad_full y el derecho a velocidad_media
void avanzar_full_izq();

//avanzar_media_der: Encender el motor izquierdo a velocidad_media y el derecho a velocidad_baja
void avanzar_media_der();

//avanzar_media_izq: Encender el motor derecho a velocidad_media y el derecho a velocidad_baja
void avanzar_media_izq();

//reversa_full_der: Encender el motor izquierdo a -velocidad_full y el derecho a -velocidad_media
void reversa_full_der();

//reversa_full_izq: Encender el motor derecho a -velocidad_full y el izquierdo a -velocidad_media
void reversa_full_izq();

//reversa_media_der: Encneder el motor derecho a -velocidad_media y el izquierdo -velocidad_baja
void reversa_media_der();

//reversa_media_izq: Encneder el motor izquierdo a -velocidad_media y el derecho -velocidad_baja
void reversa_media_izq();

//Hacer un giro_der de 360 grados
void girar_360_der();

//TODO Hay que ajustar los delays, girar a la izquierda y a la dercha necesitan distinto delay
//Hacer un giro_izq de 360 grados
void girar_360_izq();

//Hacer un giro_der de 180 grados
void girar_180_der();

//TODO Hay que ajustar los delays, girar a la izquierda y a la dercha necesitan distinto delay
//Hacer un giro_izq de 180 grados
void girar_180_izq();

#endif
