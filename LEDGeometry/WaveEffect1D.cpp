#include "WaveEffect1D.h"
#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

WaveEffect1D::WaveEffect1D(int period) : GradualChangingColorEffect(period), pos(0) {
}

void WaveEffect1D::next_state() {
    GradualChangingColorEffect::next_state();
    ++pos;
}

void WaveEffect1D::update_leds(LEDCurve* ledCurve) {
    for (int i = 0; i < ledCurve->n_leds(); i++) {
        ledCurve->leds()[i].fadeLightBy(6);
    }
    ledCurve->leds()[pos % ledCurve->n_leds()] = get_color();
}
}  // namespace LEDGeometry
