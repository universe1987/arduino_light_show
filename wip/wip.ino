#include "LEDCurve.h"
#include "CustomShape.h"
#include "ColorScheduler.h"
#include "LightEffect.h"
#include "UniformDynamicEffect.h"
#include "SignalTransmissionEffect.h"
#include "PulseEffect.h"
#include "SpiralEffect.h"
#include "FlameEffect.h"

#include <FastLED.h>

#define LED_PIN     7
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    120
#define BRIGHTNESS  144

using namespace LEDGeometry;

/**
 * Create as global variables so that IDE displays their memory usage.
 * int16_t: 2 bytes, CRGB: 3 bytes, int, float: 4 bytes
 */
CRGB leds[NUM_LEDS];
// Curve is a folded, it's shape has half the number of points
CustomShape heart_shape = CustomShape(NUM_LEDS / 2);
// Coordinates of the shape
int16_t x_coords[60] = {-283, -692, -1292, -1988, -3019, -4028, -5107, -6068, -7049, -7983, -8560, -9186, -9614, -9685, -9638, -9543, -9351, -9040, -8537, -7961, -7337, -6573, -5851, -5252, -4435, -3621, -2783, -1902, -1131, -408, 481, 1082, 1630, 2350, 3096, 3720, 4411, 5134, 5821, 6620, 7339, 7964, 8538, 8970, 9378, 9715, 9832, 9660, 9399, 8989, 8461, 7770, 6813, 5754, 4725, 3718, 2711, 1939, 1201, 696};
int16_t y_coords[60] = {3405, 4071, 4736, 5312, 5563, 5690, 5637, 5387, 5079, 4450, 3910, 3298, 2601, 1752, 956, 134, -637, -1405, -2110, -2757, -3427, -3965, -4510, -5097, -5689, -6180, -6610, -6968, -7381, -7851, -8048, -7579, -6969, -6378, -5801, -5225, -4597, -3967, -3447, -2887, -2457, -1794, -1162, -388, 280, 1034, 1824, 2580, 3317, 4039, 4775, 5260, 5547, 5622, 5658, 5491, 5298, 4793, 4198, 3588};
// Color changes every 100 frames, this can be modified by calling set_cycle.
ColorScheduler color_scheduler = ColorScheduler(100);
LEDCurve my_light(leds, (Shape*)&heart_shape, &color_scheduler, true);

void setup() {
  random16_add_entropy(random());
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip).setTemperature(HighNoonSun);
  FastLED.setBrightness(BRIGHTNESS);
  heart_shape.set_x(x_coords);
  heart_shape.set_y(y_coords);
}

void loop() {
  // Now color theme changes every 100 frames.
  color_scheduler.set_cycle(100);
  // 10 fps for 30 seconds, by default, my_light deletes the light effect in the end
  my_light.set_effect((LightEffect*)new UniformDynamicEffect(), 30, 10);
  // 20 fps for 30 seconds
  my_light.set_effect((LightEffect*)new SignalTransmissionEffect(), 30, 20);
  // Now color theme changes every 120 frames
  color_scheduler.set_cycle(120);
  // 16 fps for 30 seconds
  my_light.set_effect((LightEffect*)new PulseEffect(), 30, 16);
  // Now color theme changes every 30 frames.
  color_scheduler.set_cycle(30);
  // Effect has 2 segments and 30 points per segment, 15 fps for 30 seconds.
  my_light.set_effect((LightEffect*)new SpiralEffect(30, 2), 30, 15);
  float min_y = heart_shape.min_y();
  float max_y = heart_shape.max_y();
  my_light.set_effect((LightEffect*)new FlameEffect(50, min_y, max_y), 30, 30);
  
}
