#include "Shape.h"

#include <math.h>

namespace LEDGeometry {
int Shape::n_points() const { return num_points; }

float Shape::r(int i) const {
    float xx = x(i);
    float yy = y(i);
    return sqrt(xx * xx + yy * yy);
}

float Shape::min_x() const {
    float result = 1;
    for (int i = 0; i < num_points; i++) {
        float x_i = x(i);
        if (x_i < result) result = x_i;
    }
    return result;
}

float Shape::max_x() const {
    float result = -1;
    for (int i = 0; i < num_points; i++) {
        float x_i = x(i);
        if (x_i > result) result = x_i;
    }
    return result;
}

float Shape::min_y() const {
    float result = 1;
    for (int i = 0; i < num_points; i++) {
        float y_i = y(i);
        if (y_i < result) result = y_i;
    }
    return result;
}

float Shape::max_y() const {
    float result = -1;
    for (int i = 0; i < num_points; i++) {
        float y_i = y(i);
        if (y_i > result) result = y_i;
    }
    return result;
}

float Shape::min_r() const {
    float result = 1;
    for (int i = 0; i < num_points; i++) {
        float r_i = r(i);
        if (r_i < result) result = r_i;
    }
    return result;
}

float Shape::max_r() const {
    float result = 0;
    for (int i = 0; i < num_points; i++) {
        float r_i = r(i);
        if (r_i > result) result = r_i;
    }
    return result;
}
}  // namespace LEDGeometry
