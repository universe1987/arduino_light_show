#include "SignalTransmissionEffect.h"

#include "LEDCurve.h"

namespace LEDGeometry {

SignalTransmissionEffect::SignalTransmissionEffect(int cycle, int fade_factor)
    : DynamicEffect(cycle), fade_factor(fade_factor), pos(0) {}

SignalTransmissionEffect::SignalTransmissionEffect(int cycle)
    : SignalTransmissionEffect(cycle, 24) {}

void SignalTransmissionEffect::set_colors(LEDCurve* led_curve) {
    int n_points = led_curve->n_points();
    for (int i = 0; i < n_points; i++) {
        led_curve->leds()[i].fadeLightBy(fade_factor);
    }
    ++pos;
    if (pos >= n_points) {
        pos = 0;
    }
    led_curve->leds()[pos] = get_current_color();
}
}  // namespace LEDGeometry
