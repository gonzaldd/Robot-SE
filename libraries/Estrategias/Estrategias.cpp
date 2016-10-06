#include "Estrategias.h"
#include "Arduino.h"


//Estrategias pasivas
void Estrategias::avanzar_media_hasta_blanco()
{
  while(!sen.test_blanco())
    mov.avanzar_media();
  mov.frenar();
}


void Estrategias::avanzar_media_der_hasta_blanco()
{
  while(!sen.test_blanco())
    mov.avanzar_media_der();
  mov.frenar();
}

void Estrategias::avanzar_media_izq_hasta_blanco()
{
  while(!sen.test_blanco())
    mov.avanzar_media_izq();
  mov.frenar();
}

void Estrategias::reversa_media_hasta_blanco()
{
  while(!sen.test_blanco_tras())
    mov.reversa_media();
  mov.frenar();
}

void Estrategias::reversa_media_der_hasta_blanco()
{
  while(!sen.test_blanco_tras())
    mov.reversa_media_der();
  mov.frenar();
}

void Estrategias::reversa_media_izq_hasta_blanco()
{
  while(!sen.test_blanco_tras())
    mov.reversa_media_izq();
  mov.frenar();
}

//TODO Delay de 1,5 seg, ver si hace falta generico o queda así
void Estrategias::giro_der_hasta_blanco()
{
  int i = 0;
  while(!sen.test_blanco() && !sen.test_blanco_tras() && i<=1500)
    mov.giro_der();
    i++;
    delay(1);
  mov.frenar();
}

//TODO Delay de 1,5 seg, ver si hace falta generico o queda así
void Estrategias::giro_izq_hasta_blanco()
{
  int i = 0;
  while(!sen.test_blanco() && !sen.test_blanco_tras() && i<=1500 )
    mov.giro_izq();
    i++;
    delay(1);
  mov.frenar();
}


//Aca probé los distintos moviemientos sin que salga de la pista, habria que ver si quieren que haga eso u otra cosa.
void Estrategias::recorrer()
{
  avanzar_media_hasta_blanco();
  reversa_media_izq_hasta_blanco();
  giro_izq_hasta_blanco();
  avanzar_media_der_hasta_blanco();
  reversa_media_der_hasta_blanco();
  giro_der_hasta_blanco();
}


/*
{
  int i =0;

   while (i<=1000 && !sen.test_blanco()){
    mov.avanzar_media();
    delay(5);
    i++;
    // Serial.println("Avanzar Media");
    // Serial.println(sen.test_blanco());
   }
   mov.frenar();
   delay(2000);

   i = 0;
   while (i<=1000 && !sen.test_blanco_tras()){
    mov.reversa_media();
    delay(5);
    i++;
    // Serial.println(sen.test_blanco());
   }

   i = 0;
   while (i<=200 && !sen.test_blanco()){
    mov.avanzar_media_der();
    delay(5);
    i++;
    // Serial.println(sen.test_blanco());
   }

   /*if(test_blanco_izq()) reversa_media_der();
   else if (test_blanco_der()) reversa_media_izq();
   else reversa_media();

   delay(i*5);
   mov.frenar();
   //delay(1000);
   i=0;
   while(i<=1000 && !sen.test_blanco() && !sen.test_blanco_tras())
   {
     mov.giro_der();
     delay(2);
     i++;
    //  Serial.println(sen.test_blanco());
   }
   i=0;
  while(i<=1000 && !sen.test_blanco() && !sen.test_blanco_tras())
   {
     mov.giro_izq();
     delay(2);
     i++;
    //  Serial.println(sen.test_blanco());
   }

   i=0;

   if(sen.test_blanco_izq() && sen.test_blanco_tras())
   {
     while(i<=200 && !sen.test_blanco() && !sen.test_blanco_tras())
     {
       mov.avanzar_media_izq();
       delay(3);
       i++;
      //  Serial.println(sen.test_blanco());
     }
   }

   i=0;

   if(sen.test_blanco_der() && sen.test_blanco_tras())
   {
     while(i<=200 && !sen.test_blanco() && !sen.test_blanco_tras())
     {
       mov.avanzar_media_der();
       delay(3);
       i++;
      //  Serial.println(sen.test_blanco());
     }
   }
}
*//*
void Estrategias::recorrer_y_atacar()
{
  int i = 0;
  while(!sensor_US_cerca())
  {

    while (i<=1000 && condicion_frenado_avanzar())
    {
        mov.avanzar_media();
        delay(5);
        i++;
    }
    //delay(2000);


    while(i <= 2000 && condicion_frenado_reversa())
    {
      mov.reversa_media();
      delay(5);
      i++;
    }

    while(i<=2600 && condicion_frenado_avanzar())
    {
      mov.avanzar_media_der();
      delay(5);
      i++;
    }

    while(i<=3000 && condicion_frenado())
    {
      mov.giro_der();
      delay(2);
      i++;
    }

   while (i<=3400 && condicion_frenado())
   {
     mov.giro_izq();
     delay(2);
     i++;
   }
   i=0;
    int j = 0;
    if(sen.test_blanco_izq() && sen.test_blanco_tras())
    {
      while(j<=200 && !sen.test_blanco_der())
      {
        mov.avanzar_media_der();
        delay(3);
        j++;
      }
    }

    if(sen.test_blanco_der() && sen.test_blanco_tras())
    {
      while(j<=200 && !sen.test_blanco_izq())
      {
        mov.avanzar_media_izq();
        delay(3);
        j++;
      }
    }

}
  mov.frenar();
  if(sensor_US_cerca())
  {
    while(sensor_US_cerca())
    {
      mov.avanzar_full();
    }
  }
  mov.frenar();
}
*/
//--------------------------------------------------------------------------------
//Estrategias Agresivas
void Estrategias::atacar()
{
  while((sensor_US_cerca() || sensor_US_pegado()) && !sen.test_blanco())
  {
    mov.avanzar_full();
    delay(60); //TODO Este delay es porque el sensor US a veces tira cualquier cosa. Ajustar a ver que onda
  }
}

void Estrategias::avanzar_media_y_atacar()
{
  while(!sensor_US_cerca() && !sen.test_blanco())
  {
    mov.avanzar_media();
  }
  atacar();
}

void Estrategias::avanzar_media_izq_y_atacar()
{
  while(!sensor_US_cerca() && !sen.test_blanco())
  {
    mov.avanzar_media_izq();
  }
  atacar();
}

void Estrategias::avanzar_media_der_y_atacar()
{
  while(!sensor_US_cerca() && !sen.test_blanco())
  {
    mov.avanzar_media_der();
  }
  atacar();
}

void Estrategias::reversa_media_y_atacar()
{
  while(!sensor_US_cerca() && !sen.test_blanco_tras())
  {
    mov.reversa_media();
  }
  atacar();
}

void Estrategias::reversa_media_der_y_atacar()
{
  while(!sensor_US_cerca() && !sen.test_blanco_tras())
  {
    mov.reversa_media_der();
  }
  atacar();
}

void Estrategias::reversa_media_izq_y_atacar()
{
  while(!sensor_US_cerca() && !sen.test_blanco_tras())
  {
    mov.reversa_media_izq();
  }
  atacar();
}

//TODO Delay de 2 seg, ver si hace falta generico o queda así
void Estrategias::giro_izq_y_atacar()
{
  int i=0;
  while(!sensor_US_cerca() && !sen.test_blanco() && !sen.test_blanco_tras() && i<=1000)
  {
    mov.giro_izq();
    i++;
    delay(2);
  }
  atacar();
}

//TODO Delay de 2 seg, ver si hace falta generico o queda así
void Estrategias::giro_der_y_atacar()
{
  int i=0;
  while(!sensor_US_cerca() && !sen.test_blanco() && !sen.test_blanco_tras() && i<=1000)
  {
    mov.giro_der();
    i++;
    delay(2);
  }
  atacar();
}

void Estrategias::recorrer_y_atacar()
{
  avanzar_media_y_atacar();
  reversa_media_izq_y_atacar();
  giro_izq_y_atacar();
  avanzar_media_der_y_atacar();
  reversa_media_der_y_atacar();
  giro_der_y_atacar();
}
//--------------------------------------------------------------------------------

//Estrategias Mariconas

void Estrategias::escapar_y_frenar()
{

    int direccion = random(0,3);
    if(direccion == 0)
    {
      while(sensor_US_cerca() && !sen.test_blanco_tras())
      {
        mov.reversa_media();
      }
    }

    if(direccion == 1)
    {
      while(sensor_US_cerca() && !sen.test_blanco_tras())
      {
        mov.reversa_media_der();
      }
    }

    if(direccion == 2)
    {
      while(sensor_US_cerca() && !sen.test_blanco_tras())
      {
        mov.reversa_media_izq();
      }
    }
    mov.frenar();
}

void Estrategias::escapar_hasta_blanco()
{
  if(sensor_US_cerca()){
    while(!sen.test_blanco_tras())
    {
      int direccion = random(0,3);
      if(direccion == 0)
      {
        mov.reversa_media();
      }

      if(direccion == 1)
      {
        mov.reversa_media_der();
      }

      if(direccion == 2)
      {
        mov.reversa_media_izq();
      }
    }
    mov.frenar();
  }

}

//Estrategias Pasivo Agresivas
void Estrategias::escapar_y_atacar()
{
  escapar_hasta_blanco();
  delay(300);
  if(sen.test_blanco_tras()) atacar();
  mov.frenar();
  delay(100);
}



//-------------------------------------------------
boolean Estrategias::condicion_frenado_avanzar()
{
  return !sen.test_blanco() && !sensor_US_cerca();
}

boolean Estrategias::condicion_frenado_reversa()
{
  return !sen.test_blanco_tras() && !sensor_US_cerca();
}

boolean Estrategias::condicion_frenado()
{
  return !sen.test_blanco() && !sen.test_blanco_tras() && !sensor_US_cerca();
}

boolean Estrategias::sensor_US_cerca()
{
  return sen.sensor_US() < sensor_US_distancia_max && sen.sensor_US() < sensor_US_nada;
}

boolean Estrategias::sensor_US_pegado()
{
  return sen.sensor_US() > sensor_US_saturado;
}
