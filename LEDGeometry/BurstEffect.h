#pragma once
#include "LightEffect.h"
#include <FastLED.h>


namespace LEDGeometry {
class LEDCurve;

class BurstEffect: public LightEffect {
public:
    BurstEffect();
    ~BurstEffect();
    int next_hue() const;
    void next_state();
    void set_color(LEDCurve* ledCurve);

private:
    int i_frame;
    int hue;
    CRGB current_color;
    CRGB future_color;
    CRGB* spectrum;
};
}
