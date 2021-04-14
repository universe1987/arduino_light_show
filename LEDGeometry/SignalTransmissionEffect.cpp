#include "SignalTransmissionEffect.h"

#include "LEDCurve.h"

namespace LEDGeometry {

SignalTransmissionEffect::SignalTransmissionEffect(int cycle, int fade_factor)
    : DynamicEffect(cycle), fade_factor(fade_factor), pos(0) {}

SignalTransmissionEffect::SignalTransmissionEffect(int cycle)
    : SignalTransmissionEffect(cycle, 8) {}

void SignalTransmissionEffect::next_state() {
    DynamicEffect::next_state();
    ++pos;
}

void SignalTransmissionEffect::set_colors(LEDCurve* ledCurve) {
    int n_points = ledCurve->n_points();
    for (int i = 0; i < n_points; i++) {
        ledCurve->leds()[i].fadeLightBy(fade_factor);
    }
    if (pos >= n_points) {
        pos = 0;
    }
    ledCurve->leds()[pos] = get_current_color();
}
}  // namespace LEDGeometry
