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
  while(sen.sensor_tras() < 1 && !sen.test_blanco() < 1 && i<=1000)
    mov.giro_der();
    i++;
    //delay(1);
  mov.frenar();
}

//TODO Delay de 1,5 seg, ver si hace falta generico o queda así
void Estrategias::giro_izq_hasta_blanco()
{
  int i = 0;
  while(sen.sensor_tras() < 1 && !sen.test_blanco()< 1 && i<=1000)
    mov.giro_izq();
    i++;
   // delay(1);
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

void Estrategias::recorrer_random()
{
  int movim = random(0,6);
  if(movim==0)
    avanzar_media_hasta_blanco();
  else if(movim==1)
    reversa_media_izq_hasta_blanco();
  else if(movim==2)
    giro_izq_hasta_blanco();
  else if(movim==3)
    avanzar_media_der_hasta_blanco();
  else if(movim==4)
    reversa_media_der_hasta_blanco();
  else if(movim==5)
    giro_der_hasta_blanco();

}

//--------------------------------------------------------------------------------
//Estrategias Agresivas
void Estrategias::atacar()
{
    /*
  while((sensor_US_cerca() || sensor_US_pegado()) && !sen.test_blanco())
  {
    mov.avanzar_full();
    //delay(10); //TODO Este delay es porque el sensor US a veces tira cualquier cosa. Ajustar a ver que onda
  }
  mov.frenar();
  delay(800);
  while(!sen.test_blanco_tras())
  {
    mov.reversa_media_der();
  }
  */
  while((sensor_US_cerca() || sensor_US_pegado()) && !sen.test_blanco())
    mov.avanzar_full();

    mov.frenar();
    mov.reversa_full();
    delay(2000);
    mov.frenar();

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
    while(!sensor_US_cerca() && !sensor_US_pegado() && !sen.test_blanco())
    {
        mov.avanzar_media();
    }while(!sensor_US_cerca() && !sensor_US_pegado() && !sen.test_blanco_tras())
    {
        mov.reversa_media();
    }
    if(sensor_US_cerca() || sensor_US_pegado()) atacar();
}

void Estrategias::recorrerAtacar(){
  if(sen.sensor_izq() < 2 && sen.sensor_der() < 2){
    mov.avanzar(velocidad_media);
    if(sensor_US_cerca()){
      do{
        mov.avanzar(velocidad_full);
      }while((sensor_US_cerca() || sensor_US_pegado()) && (sen.sensor_izq() < 2 && sen.sensor_der() < 2));
    }
  }else{
    mov.frenar();
    if(sen.sensor_izq() < 2){
      //girarderecha
      do{
        mov.reversa_media_izq();
      }while(sen.sensor_tras() <= 1 && sen.sensor_der() <=1  /*&& !sensor_US_cerca() && !sensor_US_pegado()*/);

    }else{
      //giroIzquierda
      do{
        mov.reversa_media_der();
      }while(sen.sensor_tras() <= 1 && sen.sensor_izq() <= 1   /*&& !sensor_US_cerca() && !sensor_US_pegado()*/);
    }

  }
}

void Estrategias::recorrerEscapar(){
  if(sen.sensor_izq() < 2 && sen.sensor_der() < 2){
    mov.avanzar(velocidad_media);

    if(sensor_US_cerca()){
      while((sensor_US_cerca() || sensor_US_pegado()) && (sen.sensor_tras() <=1)){
        mov.reversa(velocidad_media);
      }


    }
    if ((sensor_US_cerca() || sensor_US_pegado()) && sen.sensor_tras() >1)
    {
       mov.frenar();
       cancion_mario();
       delay(2000);
    }
  }
  else{
    mov.frenar();
    if(sen.sensor_izq() < 2){
      //girarderecha
      do{
        mov.reversa_media_izq();
      }while(sen.sensor_tras() <= 1 && sen.sensor_der() <=1  /*&& !sensor_US_cerca() && !sensor_US_pegado()*/);

    }else{
      //giroIzquierda
      do{
        mov.reversa_media_der();
      }while(sen.sensor_tras() <= 1 && sen.sensor_izq() <= 1   /*&& !sensor_US_cerca() && !sensor_US_pegado()*/);
    }

  }
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

void Estrategias::cancion_starwars()
{
    int i = 0;
    while(i<= 69 && sensor_US_cerca())
    {

    if (i == 0) toneDelay(SPEAKER, a, 500);
    if (i == 1) toneDelay(SPEAKER, a, 500);
    if (i == 2) toneDelay(SPEAKER, a, 500);
    if (i == 3) toneDelay(SPEAKER, f, 350);
    if (i == 4) toneDelay(SPEAKER, cH, 150);
    if (i == 5) toneDelay(SPEAKER, a, 500);
    if (i == 6) toneDelay(SPEAKER, f, 350);
    if (i == 7) toneDelay(SPEAKER, cH, 150);
    if (i == 8) toneDelay(SPEAKER, a, 1000);
    if (i == 9) toneDelay(SPEAKER, eH, 500);
    if (i == 10) toneDelay(SPEAKER, eH, 500);
    if (i == 11) toneDelay(SPEAKER, eH, 500);
    if (i == 12) toneDelay(SPEAKER, fH, 350);
    if (i == 13) toneDelay(SPEAKER, cH, 150);

    if (i == 14) toneDelay(SPEAKER, gS, 500);
    if (i == 15) toneDelay(SPEAKER, f, 350);
    if (i == 16) toneDelay(SPEAKER, cH, 150);


      if(i==17) toneDelay(SPEAKER, a, 1000);
        //second bit...

        if(i==18) toneDelay(SPEAKER, aH, 500);
        if(i==19) toneDelay(SPEAKER, a, 350);
        if(i==20) toneDelay(SPEAKER, a, 150);
        if(i==21) toneDelay(SPEAKER, aH, 500);
        if(i==22) toneDelay(SPEAKER, gSH, 250);
        if(i==23) toneDelay(SPEAKER, gH, 250);

        if(i==24) toneDelay(SPEAKER, fSH, 125);
        if(i==25) toneDelay(SPEAKER, fH, 125);
        if(i==26) toneDelay(SPEAKER, fSH, 250);
        if(i==27) delay(250);
        if(i==28) toneDelay(SPEAKER, aS, 250);
        if(i==29) toneDelay(SPEAKER, dSH, 500);
        if(i==30) toneDelay(SPEAKER, dH, 250);
        if(i==31) toneDelay(SPEAKER, cSH, 250);
        //start of the interesti

        if(i==32) toneDelay(SPEAKER, cH, 125);
        if(i==33) toneDelay(SPEAKER, b, 125);
        if(i==34) toneDelay(SPEAKER, cH, 250);
        if(i==35) delay(250);
        if(i==36) toneDelay(SPEAKER, f, 125);
        if(i==37) toneDelay(SPEAKER, gS, 500);
        if(i==38) toneDelay(SPEAKER, f, 375);
        if(i==39) toneDelay(SPEAKER, a, 125);

        if(i==40) toneDelay(SPEAKER, cH, 500);
        if(i==41) toneDelay(SPEAKER, a, 375);
        if(i==42) toneDelay(SPEAKER, cH, 125);
        if(i==43) toneDelay(SPEAKER, eH, 1000);
        //more interesting stuff

        if(i==44) toneDelay(SPEAKER, aH, 500);
        if(i==45) toneDelay(SPEAKER, a, 350);
        if(i==46) toneDelay(SPEAKER, a, 150);
        if(i==47) toneDelay(SPEAKER, aH, 500);
        if(i==48) toneDelay(SPEAKER, gSH, 250);
        if(i==49) toneDelay(SPEAKER, gH, 250);

        if(i==50) toneDelay(SPEAKER, fSH, 125);
        if(i==51) toneDelay(SPEAKER, fH, 125);
        if(i==52) toneDelay(SPEAKER, fSH, 250);
        if(i==53) delay(250);
        if(i==54) toneDelay(SPEAKER, aS, 250);
        if(i==55) toneDelay(SPEAKER, dSH, 500);
        if(i==56) toneDelay(SPEAKER, dH, 250);
        if(i==57) toneDelay(SPEAKER, cSH, 250);
        //repeat... repeat

        if(i==58) toneDelay(SPEAKER, cH, 125);
        if(i==59) toneDelay(SPEAKER, b, 125);
        if(i==60) toneDelay(SPEAKER, cH, 250);
        if(i==61) delay(250);
        if(i==62) toneDelay(SPEAKER, f, 250);
        if(i==63) toneDelay(SPEAKER, gS, 500);
        if(i==64) toneDelay(SPEAKER, f, 375);
        if(i==65) toneDelay(SPEAKER, cH, 125);

        if(i==66) toneDelay(SPEAKER, a, 500);
        if(i==67) toneDelay(SPEAKER, f, 375);
        if(i==68) toneDelay(SPEAKER, c, 125);
        if(i==69) toneDelay(SPEAKER, a, 1000);
        i++;
        }
}

    void Estrategias::cancion_mario()
    {
        /*
        toneDelay(SPEAKER, g, 350);
        toneDelay(SPEAKER, fH, 200);
        toneDelay(SPEAKER, fH, 200);
        toneDelay(SPEAKER, fH, 200);
        toneDelay(SPEAKER, eH, 200);
        toneDelay(SPEAKER, dH, 200);
        toneDelay(SPEAKER, cH, 500);
        delay(3000);*/
        int i=0;
        while(i<=6 && (sensor_US_cerca() || sensor_US_pegado()) )
        {
            if(i==0)toneDelay(SPEAKER, g, 300 * 0.8);
            if(i==1)toneDelay(SPEAKER, fH, 200 * 0.8);
            if(i==2)toneDelay(SPEAKER, fH, 200 * 0.8);
            if(i==3)toneDelay(SPEAKER, fH, 200 * 0.8);
            if(i==4)toneDelay(SPEAKER, eH, 200 * 0.8);
            if(i==5)toneDelay(SPEAKER, dH, 200 * 0.8);
            if(i==6)toneDelay(SPEAKER, cH, 400 * 0.8);
            i++;

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
