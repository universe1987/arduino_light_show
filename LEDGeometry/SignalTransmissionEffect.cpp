#include "SignalTransmissionEffect.h"

#include "LEDInterface.h"
#include "utils.h"

namespace LEDGeometry {

SignalTransmissionEffect::SignalTransmissionEffect(int period, int fade_delta)
    : DynamicEffect(period), pos(0), fade_delta(fade_delta) {}

SignalTransmissionEffect::SignalTransmissionEffect(int period)
    : SignalTransmissionEffect(period, 8) {}

void SignalTransmissionEffect::next_state() {
    DynamicEffect::next_state();
    ++pos;
}

void SignalTransmissionEffect::set_colors(LEDInterface* ledCurve) {
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i].fadeLightBy(fade_delta);
    }
    ledCurve->leds()[pos % ledCurve->n_points()] = get_current_color();
}
}  // namespace LEDGeometry
