#include "Shape.h"

namespace LEDGeometry {
// Use PointShape when you do not care about the position of the points.
class PointShape : public Shape {
   public:
    PointShape(int n_points) : Shape(n_points) {}
    float x(int i) const { return 0; }
    float y(int i) const { return 0; }
};
}  // namespace LEDGeometry
