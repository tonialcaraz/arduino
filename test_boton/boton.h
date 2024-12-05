
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
    BotonSimple(unsigned char _pin, unsigned long _tiempoRebote);
    void actualizar();
    int  leer();
};

BotonSimple::BotonSimple(unsigned char _pin, unsigned long _tiempoRebote=50) {
  pin = _pin;
  tiempoRebote = _tiempoRebote;
  pinMode(pin, INPUT_PULLUP);
  valor=HIGH; anterior=HIGH; estado=SUELTO;
}

void BotonSimple::actualizar() {
  // NOTA: En el ejemplo original en vez de "pin" leia directamente el pin "2", con lo que el
  // codigo no funciona correctamente con el pin que le hayamos asignado.
  if ( valor==digitalRead(pin) ){
    temporizador=0;
  }
  else
  if ( temporizador==0 ) {
    temporizador = millis();
  }
  else
  if ( millis()-temporizador >= tiempoRebote ) {
    valor = !valor;
  }
  if ( anterior==LOW  && valor==LOW  ) estado = APRETADO;
  if ( anterior==LOW  && valor==HIGH ) estado = SOLTANDOLO;
  if ( anterior==HIGH && valor==LOW  ) estado = APRETANDOLO;
  if ( anterior==HIGH && valor==HIGH ) estado = SUELTO;
  anterior = valor;
}

int BotonSimple::leer() { 
  return estado;
}
 
