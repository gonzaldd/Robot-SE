#include "Movimiento.h"

DCMotor motor0(M0_EN, M0_D0, M0_D1);
DCMotor motor1(M1_EN, M1_D0, M1_D1);

void frenar()
{
  motor0.brake();
  motor1.brake();
}

void avanzar_full()
{
  motor0.setSpeed(velocidad_full);
  motor1.setSpeed(velocidad_full);
}

void avanzar_media()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_media);
}

void avanzar_baja()
{
  motor0.setSpeed(velocidad_baja);
  motor1.setSpeed(velocidad_baja);
}

void reversa_full()
{
  motor0.setSpeed(-velocidad_full);
  motor1.setSpeed(-velocidad_full);
}

void reversa_media()
{
  motor0.setSpeed(-velocidad_media);
  motor1.setSpeed(-velocidad_media);
}

void reversa_baja()
{
  motor0.setSpeed(-velocidad_baja);
  motor1.setSpeed(-velocidad_baja);
}

void avanzar_full_der()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_full);
}

void avanzar_full_izq()
{
  motor0.setSpeed(velocidad_full);
  motor1.setSpeed(velocidad_media);
}

void avanzar_media_der()
{
  motor0.setSpeed(velocidad_baja);
  motor1.setSpeed(velocidad_media);
}

void avanzar_media_izq()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_baja);
}

void reversa_full_der()
{
 motor0.setSpeed(-velocidad_media);
 motor1.setSpeed(-velocidad_full);
}

void reversa_full_izq()
{
  motor0.setSpeed(-velocidad_full);
  motor1.setSpeed(-velocidad_media);
}

void reversa_media_der()
{
  motor0.setSpeed(-velocidad_baja);
  motor1.setSpeed(-velocidad_media);
}

void reversa_media_izq()
{
  motor0.setSpeed(-velocidad_media);
  motor1.setSpeed(-velocidad_baja);
}

void girar_360_der()
{
  int i=0;
  while(i<=delay_360_1)
   {

     giro_der();
     i++;
     delay(1);
   }
   frenar();
}

//Hay que ajustar los delays, girar a la izquierda y a la dercha necesitan distinto delay
void girar_360_izq()
{
  int i=0;
  while(i<=delay_360_1)
   {

     giro_izq();
     i++;
     delay(1);
   }
   frenar();
}

void girar_180_der()
{
  int i=0;
  while(i <= delay_180_1)
   {

     giro_der();
     i++;
     delay(1);
   }
   frenar();
}

//Hay que ajustar los delays, girar a la izquierda y a la dercha necesitan distinto delay
void girar_180_izq()
{
  int i=0;
  while(i <= delay_180_1)
   {

     giro_izq();
     i++;
     delay(1);
   }
   frenar();
}
