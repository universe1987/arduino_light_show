#include "SignalTransmissionEffect.h"

#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

SignalTransmissionEffect::SignalTransmissionEffect(int period,
                                                   int min_hue_delta,
                                                   int max_hue_delta,
                                                   int fade_delta)
    : DynamicEffect(period, min_hue_delta, max_hue_delta),
      fade_delta(fade_delta),
      pos(0) {}

SignalTransmissionEffect::SignalTransmissionEffect(int period)
    : SignalTransmissionEffect(period, 32, 224, 8) {}

void SignalTransmissionEffect::next_state() {
    DynamicEffect::next_state();
    ++pos;
}

void SignalTransmissionEffect::set_colors(LEDCurve* ledCurve) {
    for (int i = 0; i < ledCurve->n_points(); i++) {
        ledCurve->leds()[i].fadeLightBy(fade_delta);
    }
    ledCurve->leds()[pos % ledCurve->n_points()] = get_current_color();
}
}  // namespace LEDGeometry
