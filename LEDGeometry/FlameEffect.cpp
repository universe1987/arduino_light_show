#include "FlameEffect.h"

#include <FastLED.h>

#include "LEDCurve.h"
#include "Shape.h"

namespace LEDGeometry {
FlameEffect::FlameEffect(int cooling, int sparking, int resolution, float min_y,
                         float max_y)
    : cooling((uint8_t)cooling),
      sparking((uint8_t)sparking),
      resolution(resolution),
      min_y(min_y),
      max_y(max_y) {
    uint8_t* heat = new uint8_t[resolution];
};

FlameEffect::FlameEffect(int resolution, float min_y, float max_y)
    : FlameEffect((int)(750 / resolution) + 2, 120, resolution, min_y, max_y) {}

FlameEffect::~FlameEffect() { delete[] heat; }

void FlameEffect::update(LEDCurve* led_curve) {
    float scale = (resolution - 1) / (max_y - min_y);
    for (int i = 0; i < led_curve->shape->n_points(); i++) {
        float y = led_curve->shape->y(i);
        int projection = (int)round((y - min_y) * scale);
        uint8_t temperature = heat[projection];
        int delta = random8(0, 32) - 16;
        if (delta > 0) {
            temperature = qadd8(temperature, delta);
        } else {
            temperature = qsub8(temperature, -delta);
        }
        uint8_t color_index = scale8(temperature, 240);
        led_curve->leds[i] = ColorFromPalette(HeatColors_p, color_index);
    }
    update_heat();
}

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
}  // namespace LEDGeometry
