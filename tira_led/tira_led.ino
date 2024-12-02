/// @file    FirstLight.ino
/// @brief   Animate a white dot moving along a strip of LEDs
/// @example FirstLight.ino

// Use if you want to force the software SPI subsystem to be used for some reason (generally, you don't)
// #define FASTLED_FORCE_SOFTWARE_SPI
// Use if you want to force non-accelerated pin access (hint: you really don't, it breaks lots of things)
// #define FASTLED_FORCE_SOFTWARE_SPI
// #define FASTLED_FORCE_SOFTWARE_PINS
#include <FastLED.h>

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
// 

// How many leds are in the strip?
#define NUM_LEDS 60
#define BRIGHTNESS  128

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 5
//#define CLOCK_PIN 13

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];
int purpleLed = 5;
int blueLed = 10;

// This function sets up the ledsand tells the controller about them
void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
    FastLED.setBrightness(BRIGHTNESS);
    
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {
   // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
     
      // Turn our current led on to white, then show the leds
      //leds[whiteLed] = CRGB::White;
      leds[whiteLed] = CRGB::Green;
      leds[purpleLed] = CRGB::Red;
      leds[blueLed] = CRGB::Indigo;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(20);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
      leds[purpleLed] = CRGB::Black;
      leds[blueLed] = CRGB::Black;

      if( purpleLed < NUM_LEDS) 
        { blueLed = blueLed + 1;
          purpleLed = purpleLed + 1;
        
        
        } else {
          
          purpleLed = 5;
          blueLed = 10;
        
        }
      

   }
}
