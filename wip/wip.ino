#include "LEDCurve.h"
#include "GenericShape.h"
#include "WaveEffect0D.h"
#include "WaveEffect1D.h"

#include <math.h>
#include <FastLED.h>

#define LED_PIN     7
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    120
#define BRIGHTNESS  128

using namespace LEDGeometry;

CRGB leds[NUM_LEDS];
Shape* shape = new GenericShape(NUM_LEDS);
LEDCurve my_light(leds, shape);

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(my_light.leds(), my_light.n_leds()).setCorrection(TypicalLEDStrip).setTemperature(HighNoonSun);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  LightEffect* effect1 = new WaveEffect0D(10);
  // 30 fps for 60 seconds
  my_light.set_effect(effect1, 30, 10);
  delete effect1;
  LightEffect* effect2 = new WaveEffect1D(10);
  my_light.set_effect(effect2, 30, 10);
  delete effect2;
}
