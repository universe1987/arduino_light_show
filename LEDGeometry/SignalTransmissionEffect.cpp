#include "SignalTransmissionEffect.h"
#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

SignalTransmissionEffect::SignalTransmissionEffect(int period) : DynamicEffect(period), pos(0) {
}

void SignalTransmissionEffect::next_state() {
    DynamicEffect::next_state();
    ++pos;
}

void SignalTransmissionEffect::set_colors(LEDCurve* ledCurve) {
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i].fadeLightBy(6);
    }
    ledCurve->leds()[pos % ledCurve->n_points()] = get_color();
}
}  // namespace LEDGeometry
