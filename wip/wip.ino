#include "LEDCurve.h"
#include "GenericShape.h"
#include "UniformDynamicEffect.h"
#include "SignalTransmissionEffect.h"
#include "PulseEffect.h"

#include <math.h>
#include <FastLED.h>

#define LED_PIN     7
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    120
#define BRIGHTNESS  160

using namespace LEDGeometry;

// Create as global variables so that IDE displays their memory usage.
// CRGB: 3 bytes each, int, float: 4 bytes each
CRGB leds[NUM_LEDS];
GenericShape shape(NUM_LEDS / 2); // folded curve, half the number of points
LEDCurve my_light(leds, (Shape*)&shape, true);

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(my_light.leds(), NUM_LEDS).setCorrection(TypicalLEDStrip).setTemperature(HighNoonSun);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // color change every 100 frames
  LightEffect* effect1 = new UniformDynamicEffect(100);
  // 10 fps for 30 seconds
  my_light.set_effect(effect1, 30, 10);
  delete effect1;
  LightEffect* effect2 = new SignalTransmissionEffect(150);
  my_light.set_effect(effect2, 30, 15);
  delete effect2;
  LightEffect* effect3 = new PulseEffect(160);
  my_light.set_effect(effect3, 30, 16);
  delete effect3;
}
