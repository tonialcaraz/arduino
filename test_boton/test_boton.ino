
#include "boton.h"

BotonSimple botonA(9);
BotonSimple botonB(6);

void updateBotones(){

  botonA.actualizar();
  botonB.actualizar();

}


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
  
void loop() {
  updateBotones();

  switch ( botonA.leer() ) {
    case SUELTO: digitalWrite(13, LOW); break;
    case APRETANDOLO: Serial.println("Acabas de apretar el botonA"); break;
    case APRETADO: digitalWrite(13, HIGH); break;
    case SOLTANDOLO: Serial.println("Acabas de soltar el botonA"); break;
    default: break;
  }

  switch ( botonB.leer() ) {
    case SUELTO: digitalWrite(13, LOW); break;
    case APRETANDOLO: Serial.println("Acabas de apretar el botonB"); break;
    case APRETADO: digitalWrite(13, HIGH); break;
    case SOLTANDOLO: Serial.println("Acabas de soltar el botonB"); break;
    default: break;
  }

}