#ifndef _BotonSimple_h_
#define _BotonSimple_h_

#include <Arduino.h>

#define APRETADO    0
#define SUELTO      1
#define APRETANDOLO 2
#define SOLTANDOLO  3

class BotonSimple {
  private:
    unsigned char pin;
    unsigned char anterior, valor;
    unsigned char estado;

    unsigned long temporizador;
    unsigned long tiempoRebote;
  public:
    BotonSimple(unsigned char _pin, unsigned long _tiempoRebote=50);
    void actualizar();
    int  leer();
};

#endif