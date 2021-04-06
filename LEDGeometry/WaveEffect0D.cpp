#include "WaveEffect0D.h"
#include "LEDCurve.h"
#include "utils.h"

namespace LEDGeometry {

WaveEffect0D::WaveEffect0D(int period) : GradualChangingColorEffect(period) {
}

void WaveEffect0D::update_leds(LEDCurve* ledCurve) {
    CRGB current_color = get_color();
    for (int i = 0; i < ledCurve->n_leds(); i++) {
        ledCurve->leds()[i] = current_color;
    }
}
}  // namespace LEDGeometry
