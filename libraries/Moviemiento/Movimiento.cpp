#include <Movimiento.h>
#include <DcMotor.h>
#include <Arduino.h>



void Movimiento::frenar()
{
  motor0.brake();
  motor1.brake();
}

void Movimiento::avanzar(int velocidad)
{
  motor0.setSpeed(velocidad);
  motor1.setSpeed(velocidad);
}

void Movimiento::reversa(int velocidad)
{
  motor0.setSpeed(-velocidad);
  motor1.setSpeed(-velocidad);
}

void Movimiento::avanzar_full()
{
  motor0.setSpeed(velocidad_full);
  motor1.setSpeed(velocidad_full);
}

void Movimiento::avanzar_media()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_media);
}

void Movimiento::avanzar_baja()
{
  motor0.setSpeed(velocidad_baja);
  motor1.setSpeed(velocidad_baja);
}

void Movimiento::reversa_full()
{
  motor0.setSpeed(-velocidad_full);
  motor1.setSpeed(-velocidad_full);
}

void Movimiento::reversa_media()
{
  motor0.setSpeed(-velocidad_media);
  motor1.setSpeed(-velocidad_media);
}

void Movimiento::reversa_baja()
{
  motor0.setSpeed(-velocidad_baja);
  motor1.setSpeed(-velocidad_baja);
}

void Movimiento::avanzar_full_der()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_full);
}

void Movimiento::avanzar_full_izq()
{
  motor0.setSpeed(velocidad_full);
  motor1.setSpeed(velocidad_media);
}

void Movimiento::avanzar_media_der()
{
  motor0.setSpeed(velocidad_baja);
  motor1.setSpeed(velocidad_media);
}

void Movimiento::avanzar_media_izq()
{
  motor0.setSpeed(velocidad_media);
  motor1.setSpeed(velocidad_baja);
}

void Movimiento::reversa_full_der()
{
 motor0.setSpeed(-velocidad_media);
 motor1.setSpeed(-velocidad_full);
}

void Movimiento::reversa_full_izq()
{
  motor0.setSpeed(-velocidad_full);
  motor1.setSpeed(-velocidad_media);
}
/*
void Movimiento::reversa_media_der()
{
  motor0.setSpeed(-velocidad_baja);
  motor1.setSpeed(-velocidad_media);
}

/*
void Movimiento::reversa_media_izq()
{
  motor0.setSpeed(-velocidad_media);
  motor1.setSpeed(-velocidad_baja);
}
*/
void Movimiento::reversa_media_izq()
{
    motor0.setSpeed(-80);
    motor1.setSpeed(-40);

}
void Movimiento::reversa_media_der()
{
    motor0.brake();
    motor1.setSpeed(-80);

}

void Movimiento::giro_der()
{
  motor0.setSpeed(-velocidad_giro);
  motor1.setSpeed(0);
}

void Movimiento::giro_izq()
{
  motor0.setSpeed(0);
  motor1.setSpeed(-velocidad_giro);
}

void Movimiento::girar_360_der()
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
void Movimiento::girar_360_izq()
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

void Movimiento::girar_180_der()
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
void Movimiento::girar_180_izq()
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

void Movimiento::giro_der_90gr()
{
    motor0.setSpeed(-100);
    motor1.setSpeed(100);
    delay(335);
    frenar();
}

void Movimiento::giro_izq_90gr()
{
    motor0.setSpeed(100);
    motor1.setSpeed(-100);
    delay(345);
    frenar();
}

void Movimiento::giro_der_trompo()
{
    motor0.setSpeed(-100);
    motor1.setSpeed(100);
}

void Movimiento::giro_izq_trompo()
{
    motor0.setSpeed(100);
    motor1.setSpeed(-100);
}
