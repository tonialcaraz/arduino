#include <FastLED.h>
#include <Button.h>

#define NUM_LEDS 128
#define DATA_PIN 5  // Change this to match your LED strip's data pin
#define BRIGHTNESS 180

CRGB leds[NUM_LEDS];

Button Boton_A(9);
int Estado = 1;
int count =0;

void log_boton(){
 
  Serial.println("Boton A pulsado");
  Serial.print("Estado: ");
  Serial.println(Estado);
  Serial.print("Contador: ");
  Serial.println(count);
  Estado = !Estado;
  count = count+1; 

}




void setup() {
  
  Boton_A.begin(); 

  delay(2000);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  while (!Serial) { }; // for Leos
    Serial.begin(9600);


}

void loop() {
   
    //leds[80] = CRGB::Purple;

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
  


