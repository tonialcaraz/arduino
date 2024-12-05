#include <FastLED.h>
#include "boton.h"

//#define NUM_LEDS 128
#define NUM_LEDS 300

#define DATA_PIN 5  // Change this to match your LED strip's data pin
#define BRIGHTNESS 255

CRGB leds[NUM_LEDS];

BotonSimple botonA(9);
BotonSimple botonB(6);

void updateBotones(){
  botonA.actualizar();
  botonB.actualizar();
}

void kitt(){
   FastLED.clear();
   for(int dot = 75; dot < 95; dot++) { 
            leds[dot] = CRGB::Red;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            delay(50);
        }
  
    for(int dot = 95; dot > 75; dot--) { 
            leds[dot] = CRGB::Red;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            delay(50);
        }
}

void kitt2(){
   int led_patras = NUM_LEDS;
   FastLED.clear();
   for(int dot = 0; dot < NUM_LEDS; dot++) { 
            
            leds[dot] = CRGB::Blue;
            leds[led_patras] = CRGB::Red;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            leds[led_patras] = CRGB::Black;
            led_patras = led_patras - 1;
            delay(10);
           
        }
  }

void Police(){

FastLED.clear();

  delay(100);
  for (int i=0; i<4; i++){
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Blue;
  FastLED.show();
  delay(30);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  FastLED.show();
  delay(30);
  }
  delay(100);
  for (int j=0; j<4; j++){
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  FastLED.show();
  delay(30);
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  FastLED.show();
  delay(30);
  }

}




void apaga(){ 
 FastLED.clear();
 for(int dot=0; dot<NUM_LEDS; dot++){
  leds[dot] = CRGB::Black;
  FastLED.show();
  }
}

String modoAnimacion="";

void setup() {
  
  delay(2000);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  while (!Serial) { }; // for Leos
    Serial.begin(9600);


}

void loop() {
   
    
  updateBotones();
  
  switch ( botonA.leer() ) {
    case SUELTO: ; break;
    case APRETANDOLO: Serial.println("Acabas de apretar el botonA"); modoAnimacion="kitt"; break;
    case APRETADO:  break;
    case SOLTANDOLO: Serial.println("Acabas de soltar el botonA"); break;
    default: break;
  }

  switch ( botonB.leer() ) {
    case SUELTO: break;
    case APRETANDOLO: Serial.println("Acabas de apretar el botonB"); modoAnimacion="apaga"; break;
    case APRETADO: ; break;
    case SOLTANDOLO: Serial.println("Acabas de soltar el botonB"); break;
    default: break;
  }

 if (modoAnimacion=="kitt") {Police();}// updateBotones();}
 else if (modoAnimacion=="apaga") {apaga();} //updateBotones();}
 




 }
  


