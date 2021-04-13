#include "Shape.h"

#include <math.h>

namespace LEDGeometry {
float Shape::r(int i) const {
    float xx = x(i);
    float yy = y(i);
    return sqrt(xx * xx + yy * yy);
}
}  // namespace LEDGeometry
