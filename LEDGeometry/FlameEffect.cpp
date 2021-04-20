#include "FlameEffect.h"

#include <FastLED.h>

#include "LEDCurve.h"
#include "Shape.h"

namespace LEDGeometry {
FlameEffect::FlameEffect(int cooling, int sparking, int resolution,
                         projection p_func)
    : cooling((uint8_t)cooling),
      sparking((uint8_t)sparking),
      resolution(resolution),
      p_func(p_func) {
    uint8_t* heat = new uint8_t[resolution];
};

FlameEffect::FlameEffect(int resolution, projection p_func)
    : FlameEffect((int)(600 / resolution) + 2, 120, resolution, p_func) {}

FlameEffect::~FlameEffect() { delete[] heat; }

void FlameEffect::update_heat() {
    // randomly cool down
    for (int i = 0; i < resolution; i++) {
        heat[i] = qsub8(heat[i], random8(0, cooling));
    }
    // transmit heat up
    for (int i = resolution - 1; i >= 2; i--) {
        // this does not overflow
        heat[i] = (heat[i - 1] + heat[i - 2] + heat[i - 2]) / 3;
    }
    // random ignition
    if (random8() < sparking) {
        int y = random8(7);
        heat[y] = qadd8(heat[y], random8(160, 255));
    }
}

void FlameEffect::update(LEDCurve* led_curve) {
    for (int i = 0; i < led_curve->shape->n_points(); i++) {
        int p = p_func(i, led_curve->shape->x(i), led_curve->shape->y(i));
        uint8_t temperature = heat[p];
        uint8_t color_index = scale8(temperature, 240);
        led_curve->leds[i] = ColorFromPalette(HeatColors_p, color_index);
    }
    update_heat();
}
}  // namespace LEDGeometry
