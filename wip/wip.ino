#include "LEDCurve.h"
#include "CustomShape.h"
#include "ColorScheduler.h"
#include "LightEffect.h"
#include "MonoColorEffect.h"
#include "SignalTransmissionEffect.h"
#include "PulseEffect.h"
#include "SpiralEffect.h"
#include "FlameEffect.h"
#include "BurstEffect.h"

#include <FastLED.h>

#define LED_PIN     7
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    120
#define BRIGHTNESS  144

#define COLOR_BUFFER_SIZE 32
#define BYTE_BUFFER_SIZE 38

using namespace LEDGeometry;

/**
 * Create as global variables so that IDE displays their memory usage.
 * int16_t: 2 bytes, CRGB: 3 bytes, int, float: 4 bytes
 */
CRGB leds[NUM_LEDS];
CRGB color_buffer[COLOR_BUFFER_SIZE];
uint8_t byte_buffer[BYTE_BUFFER_SIZE];
int16_t x_coords[60] = {-283, -692, -1292, -1988, -3019, -4028, -5107, -6068, -7049, -7983, -8560, -9186, -9614, -9685, -9638, -9543, -9351, -9040, -8537, -7961, -7337, -6573, -5851, -5252, -4435, -3621, -2783, -1902, -1131, -408, 481, 1082, 1630, 2350, 3096, 3720, 4411, 5134, 5821, 6620, 7339, 7964, 8538, 8970, 9378, 9715, 9832, 9660, 9399, 8989, 8461, 7770, 6813, 5754, 4725, 3718, 2711, 1939, 1201, 696};
int16_t y_coords[60] = {3405, 4071, 4736, 5312, 5563, 5690, 5637, 5387, 5079, 4450, 3910, 3298, 2601, 1752, 956, 134, -637, -1405, -2110, -2757, -3427, -3965, -4510, -5097, -5689, -6180, -6610, -6968, -7381, -7851, -8048, -7579, -6969, -6378, -5801, -5225, -4597, -3967, -3447, -2887, -2457, -1794, -1162, -388, 280, 1034, 1824, 2580, 3317, 4039, 4775, 5260, 5547, 5622, 5658, 5491, 5298, 4793, 4198, 3588};
// Curve is a folded, it's shape has half the number of points
CustomShape heart_shape = CustomShape(NUM_LEDS / 2, x_coords, y_coords);
// Color changes every 100 frames, this can be modified by calling set_cycle.
ColorScheduler color_scheduler = ColorScheduler(100);
LEDCurve my_light(leds, (Shape*)&heart_shape, &color_scheduler, true);
// Projection function for flame effect.
int get_intrinsic_level(LEDCurve* led_curve, int i) {
  return i > 29? i - 23: 36 - i;
}

MonoColorEffect mono_color;
SignalTransmissionEffect signal_transmission;
PulseEffect pulse;
SpiralEffect spiral(2, 30);
FlameEffect flame(byte_buffer, BYTE_BUFFER_SIZE, get_intrinsic_level);
BurstEffect burst(color_buffer, COLOR_BUFFER_SIZE);

void setup() {
  random16_add_entropy(random());
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip).setTemperature(HighNoonSun);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  color_scheduler.set_cycle(100);
  color_scheduler.set_continuous_mode();
  // 10 fps for 30 seconds
  my_light.set_effect((LightEffect*)&mono_color, 30, 10);
  my_light.set_effect((LightEffect*)&signal_transmission, 30, 20);
  color_scheduler.set_cycle(120);
  my_light.set_effect((LightEffect*)&pulse, 30, 16);
  color_scheduler.set_cycle(30);
  my_light.set_effect((LightEffect*)&burst, 30, 20);
  // Spiral effect looks better under discrete mode
  color_scheduler.set_discrete_mode();
  my_light.set_effect((LightEffect*)&spiral, 30, 15);
  my_light.set_effect((LightEffect*)&flame, 30, 30);
}
