#include "LEDCurve.h"
#include "CustomShape.h"
#include "UniformDynamicEffect.h"
#include "SignalTransmissionEffect.h"
#include "PulseEffect.h"
#include "SpiralEffect.h"


#include <math.h>
#include <FastLED.h>

#define LED_PIN     7
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    120
#define BRIGHTNESS  144

using namespace LEDGeometry;

// Create as global variables so that IDE displays their memory usage.
// CRGB: 3 bytes each, int, float: 4 bytes each
CRGB leds[NUM_LEDS];
CustomShape heart_shape = CustomShape(NUM_LEDS / 2); // folded curve, half the number of points
LEDCurve my_light(leds, (Shape*)&heart_shape, true);
int16_t x_coords[60] = {-388, -1074, -1807, -2644, -3440, -4213, -4990, -5558, -6245, -6971, -7563, -8110, -8588, -8883, -9066, -9156, -9201, -9134, -8726, -8132, -7584, -6696, -5765, -4852, -3827, -2868, -1888, -1227, -658, -269, 661, 1141, 1842, 2575, 3532, 4489, 5467, 6472, 7381, 8038, 8540, 8929, 9177, 9341, 9229, 8909, 8522, 8111, 7565, 6972, 6289, 5530, 4878, 4190, 3534, 2941, 2232, 1548, 1028, 457};
int16_t y_coords[60] = {7459, 7012, 6619, 6279, 5871, 5404, 4843, 4284, 3767, 3256, 2620, 2005, 1335, 605, -128, -909, -1665, -2471, -3133, -3715, -4228, -4825, -5118, -5355, -5406, -5285, -5047, -4499, -3868, -3235, -3409, -3988, -4553, -5033, -5217, -5375, -5341, -5270, -4997, -4536, -3837, -3151, -2451, -1732, -983, -266, 369, 1104, 1704, 2334, 2743, 3274, 3769, 4367, 4964, 5511, 6060, 6621, 7201, 7646};

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(my_light.leds(), NUM_LEDS).setCorrection(TypicalLEDStrip).setTemperature(HighNoonSun);
  FastLED.setBrightness(BRIGHTNESS);
  heart_shape.set_x(x_coords);
  heart_shape.set_y(y_coords);
}

void loop() {
  // color change every 100 frames
  LightEffect* effect1 = new UniformDynamicEffect(100);
  // 10 fps for 30 seconds
  my_light.set_effect(effect1, 30, 10);
  delete effect1;
  LightEffect* effect2 = new SignalTransmissionEffect(100, 24);
  my_light.set_effect(effect2, 30, 20);
  delete effect2;
  LightEffect* effect3 = new PulseEffect(160, 30);
  my_light.set_effect(effect3, 30, 16);
  delete effect3;
  // 2 segments, 30 points per segment
  LightEffect* effect4 = new SpiralEffect(30, 2);
  my_light.set_effect(effect4, 30, 15);
  delete effect4;
}
