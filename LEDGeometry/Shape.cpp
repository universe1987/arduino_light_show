#include "Shape.h"

#include <math.h>

namespace LEDGeometry {
uint8_t Shape::n_points() const { return num_points; }

float Shape::r(uint8_t i) const {
    float xx = x(i);
    float yy = y(i);
    return sqrt(xx * xx + yy * yy);
}

float Shape::projection(uint8_t i, float px, float py) const {
    return px * x(i) + py * y(i);
}

float Shape::distance(uint8_t i, float px, float py) const {
    float x_i = x(i);
    float y_i = y(i);
    return sqrt((x_i - px) * (x_i - px) + (y_i - py) * (y_i - py));
}

float Shape::min_projection(float px, float py) const {
    float proj_min = 100;
    for (uint8_t i = 0; i < num_points; i++) {
        float p = projection(i, px, py);
        if (p < proj_min) proj_min = p;
    }
    return proj_min;
}

float Shape::max_projection(float px, float py) const {
    float proj_max = -100;
    for (uint8_t i = 0; i < num_points; i++) {
        float p = projection(i, px, py);
        if (p > proj_max) proj_max = p;
    }
    return proj_max;
}

float Shape::min_distance(float px, float py) const {
    float x_i, y_i;
    float dist_min = 100;
    for (uint8_t i = 0; i < num_points; i++) {
        float d = (x_i - px) * (x_i - px) + (y_i - py) * (y_i - py);
        if (d < dist_min) dist_min = d;
    }
    return sqrt(dist_min);
}

float Shape::max_distance(float px, float py) const {
    float x_i, y_i;
    float dist_max = 0;
    for (uint8_t i = 0; i < num_points; i++) {
        float d = (x_i - px) * (x_i - px) + (y_i - py) * (y_i - py);
        if (d > dist_max) dist_max = d;
    }
    return sqrt(dist_max);
}
}  // namespace LEDGeometry
