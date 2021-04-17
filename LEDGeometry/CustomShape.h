#pragma once
#include "Shape.h"

namespace LEDGeometry {
class CustomShape : public Shape {
   public:
    CustomShape(int num_points) : Shape(num_points) {}

    ~CustomShape() {
        // these two pointers do not own the data
        delete x_coords;
        delete y_coords;
    }

    // x coordinate, -1 <= x <= 1
    float x(int i) const { return (float)x_coords[i] / 10000; }
    // y coordinate, -1 <= y <= 1
    float y(int i) const { return (float)y_coords[i] / 10000; };

    void set_x(int16_t* xx) { x_coords = xx; }
    void set_y(int16_t* yy) { y_coords = yy; }

   private:
    int16_t* x_coords;
    int16_t* y_coords;
};
}  // namespace LEDGeometry
