#include "LEDCurve.h"
#include "GenericShape.h"
#include "UniformDynamicEffect.h"
#include "SignalTransmissionEffect.h"

#include <math.h>
#include <FastLED.h>

#define LED_PIN     7
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    120
#define BRIGHTNESS  160

using namespace LEDGeometry;

CRGB leds[NUM_LEDS];
// create a folded led curve, so the shape has half of the points
Shape* shape = new GenericShape(NUM_LEDS / 2);
LEDCurve my_light(leds, shape, true);

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(my_light.leds(), NUM_LEDS).setCorrection(TypicalLEDStrip).setTemperature(HighNoonSun);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // 10 fps for 30 seconds, color change every 50 frames
  LightEffect* effect1 = new UniformDynamicEffect(100);
  my_light.set_effect(effect1, 30, 10);
  delete effect1;
  // 10 fps for 30 seconds, color change every 60 frames
  LightEffect* effect2 = new SignalTransmissionEffect(60);
  my_light.set_effect(effect2, 30, 15);
  delete effect2;
}
