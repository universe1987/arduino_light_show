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
int16_t x_coords[60] = {-408, -1131, -1902, -2783, -3621, -4435, -5252, -5851, -6573, -7337, -7961, -8537, -9040, -9351, -9543, -9638, -9685, -9614, -9186, -8560, -7983, -7049, -6068, -5107, -4028, -3019, -1988, -1292, -692, -283, 696, 1201, 1939, 2711, 3718, 4725, 5754, 6813, 7770, 8461, 8989, 9399, 9660, 9832, 9715, 9378, 8970, 8538, 7964, 7339, 6620, 5821, 5134, 4411, 3720, 3096, 2350, 1630, 1082, 481};
int16_t y_coords[60] = {7851, 7381, 6968, 6610, 6180, 5689, 5097, 4510, 3965, 3427, 2757, 2110, 1405, 637, -134, -956, -1752, -2601, -3298, -3910, -4450, -5079, -5387, -5637, -5690, -5563, -5312, -4736, -4071, -3405, -3588, -4198, -4793, -5298, -5491, -5658, -5622, -5547, -5260, -4775, -4039, -3317, -2580, -1824, -1034, -280, 388, 1162, 1794, 2457, 2887, 3447, 3967, 4597, 5225, 5801, 6378, 6969, 7579, 8048};
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
