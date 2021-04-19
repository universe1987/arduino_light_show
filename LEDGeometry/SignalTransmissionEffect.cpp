#include "SignalTransmissionEffect.h"

#include <FastLED.h>

#include "ColorScheduler.h"
#include "LEDCurve.h"

namespace LEDGeometry {
SignalTransmissionEffect::SignalTransmissionEffect(int fade_factor)
    : fade_factor(fade_factor), pos(0) {}

SignalTransmissionEffect::SignalTransmissionEffect()
    : SignalTransmissionEffect(16) {}

void SignalTransmissionEffect::update(LEDCurve* led_curve) {
    int n_points = led_curve->n_points();
    for (int i = 0; i < n_points; i++) {
        led_curve->led(i).fadeLightBy(fade_factor);
    }
    ++pos;
    if (pos >= n_points) {
        pos = 0;
    }
    led_curve->led(pos) = led_curve->next_color();
}
}  // namespace LEDGeometry
