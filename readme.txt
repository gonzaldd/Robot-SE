Antes de correr nada:

1)Poner las carpetas de librerias en la carpeta "libraries" del Duinopack

2) Cambiar el constructor de la clase DCMotor en "DCMotor.h". Hay que sacarle el
valor inicial al atributo Clockwise (tiene un true creo), para poder
incializarlo cuando se hace una instancia. Quedaría asi:

    public:
    		inline DCMotor(const int enable_pin,
                           const int d0_pin, const int d1_pin,
                           const bool clockwise) :   clockwise(clockwise),
                                                            braked(false),
                                                            speed(0.0), prevSpeed(0.0), zeroZone(0.1),
                                                            enable_pin(enable_pin),
                                                            d0_pin(d0_pin), d1_pin(d1_pin)

3) Los include e incializaciones del archivo .ino son:

    #include <DCMotor.h>
    #include <Ping.h>
    #include <IRremote.h>
    #include <Movimiento.h>
    #include <Sensores.h>
    #include <Estrategias.h>

    DCMotor motor0(M0_EN, M0_D0, M0_D1, false);   //Inciializamos el motor con el constructor modificado y le pasamos false a clockwise
    DCMotor motor1(M1_EN, M1_D0, M1_D1, false);   //Idem
    IRrecv irReceiver(A0);                        //S0 input
    PingSensor ping(A1);                          //S1 input - Sensor ultrasonido
    Movimiento mov = Movimiento(motor0, motor1);  //La clase movimiento esta definida en "Movimiento.h", motores como parametros.
    Sensores sen = Sensores(irReceiver,ping);     //La clase sensores, definida en "Sensores.h", para tomar los valores de los sensores
    Estrategias est = Estrategias(sen,mov);       //La clase de estrategias definida en "Estrategias.h"


4) La estructura del setup:

    void setup()
    {
      Serial.begin(115200);
      pinMode(25, INPUT);
      digitalWrite(25, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      delay(5000);                                //Esto es mas que nada para que no arranque al toque
    }

5) Como las funciones estan definidas en las librerias, hay que invocar los
metodos desde las instancias de las clases.
Por ej: mov.avanzar_full();
        sen.prueba_sensores();
        est.recorrer();
