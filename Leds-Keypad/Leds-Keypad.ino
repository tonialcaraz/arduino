#include <FastLED.h>
#include <Keypad.h>
#include "boton.h"

//#define NUM_LEDS 128
#define NUM_LEDS 300

#define DATA_PIN 4  // Change this to match your LED strip's data pin
#define BRIGHTNESS 255

const byte rowsCount = 4;
const byte columsCount = 4;
 
char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};

const byte rowPins[rowsCount] = { 12, 11, 10, 9 };
const byte columnPins[columsCount] = { 8, 7, 6, 5 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);

CRGB leds[NUM_LEDS];

BotonSimple botonA(3);
BotonSimple botonB(2);

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

void setup() {
  
  delay(2000);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  while (!Serial) { }; // for Leos
    Serial.begin(9600);


}

void loop() {
   
 
 char key = keypad.getKey();
 switch ( key ) {
    case '1': Serial.println("Acabas de apretar 1 - KITT ");kitt(); break;
    case '2': Serial.println("Acabas de apretar 2 - KITT2 "); kitt2(); break;
    case '3': Serial.println("Acabas de apretar 3 - POLICE "); Police() ;break;
    case '0': Serial.println("Acabas de apretar 0 - STOP "); apaga(); break;
    default: break;
  }

 }
  


