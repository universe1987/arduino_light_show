#include "LEDCurve.h"
#include "GenericShape.h"
#include "UniformEffect.h"
#include <math.h>
#include <FastLED.h>


#define LED_PIN     7
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    120
#define BRIGHTNESS  128

using namespace LEDGeometry;

CRGB leds[NUM_LEDS];
GenericShape s{120};
LEDCurve my_light(leds, &s);

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(my_light.leds(), my_light.n_leds()).setCorrection(TypicalLEDStrip).setTemperature(HighNoonSun);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  LightEffect* effect = new UniformEffect(32);
  // 30 fps for 60 seconds
  my_light.set_effect(effect, 60, 30);
  delete effect;
}
