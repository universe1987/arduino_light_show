#pragma once
#include "Shape.h"

namespace LEDGeometry {
/**
 * Constructs a shape using coordinates.
 * CustomShape does not own the coordinates, so make the coordinates global or
 * keep them on the heap.
 */
class CustomShape : public Shape {
   public:
    CustomShape(int num_points, int16_t* x, int16_t* y)
        : Shape(num_points), x_coords(x), y_coords(y) {}

    // x coordinate, -1 <= x <= 1
    float x(int i) const { return (float)x_coords[i] / 10000; }
    // y coordinate, -1 <= y <= 1
    float y(int i) const { return (float)y_coords[i] / 10000; };

   private:
    int16_t* x_coords;
    int16_t* y_coords;
};
}  // namespace LEDGeometry
