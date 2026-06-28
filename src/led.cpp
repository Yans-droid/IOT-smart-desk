#include <FastLED.h>

#include "config.h"
#include "globals.h"

CRGB leds[NUM_LEDS];

void ledBegin()
{
    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(50);
}

void ledUpdate()
{
    switch(state.mode)
    {
        case MODE_OFF:
            fill_solid(leds, NUM_LEDS, CRGB::Black);
            break;

        case MODE_READING:
            fill_solid(leds, NUM_LEDS, CRGB(255,180,100));
            break;

        case MODE_FOCUS:
            fill_solid(leds, NUM_LEDS, CRGB::White);
            break;

        case MODE_BREAK:
            fill_solid(leds, NUM_LEDS, CRGB::Blue);
            break;
    }

    FastLED.show();
}