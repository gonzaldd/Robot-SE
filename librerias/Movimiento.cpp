#include <DCMotor.h>

#define velocidad_full 90.0
#define velocidad_media 60.0
#define velocidad_baja 30.0
#define velocidad_giro 60

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
