#include "Shape.h"

namespace LEDGeometry {
class GenericShape : public Shape {
   public:
    GenericShape(int n_points) : Shape(n_points) {}
    float x(int i) const { return 0; }
    float y(int i) const { return 0; }
};
}  // namespace LEDGeometry
