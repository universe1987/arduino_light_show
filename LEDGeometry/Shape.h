#pragma once
#include <stdint.h>

namespace LEDGeometry {
class Shape {
   public:
    Shape(uint8_t num_points) : num_points(num_points){};
    virtual ~Shape() {}
    // x coordinate
    virtual float x(uint8_t i) const = 0;
    // y coordinate
    virtual float y(uint8_t i) const = 0;
    // Euclidean distance to the origin
    float r(uint8_t i) const;
    // number of points on the shape
    uint8_t n_points() const;
    // dot product of the i-th point with (px, py)
    float projection(uint8_t i, float px, float py) const;
    // distance between the i-th point and (px, py)
    float distance(uint8_t i, float px, float py) const;
    // min and max dot product with (px, py)
    float min_projection(float px, float py) const;
    float max_projection(float px, float py) const;
    // min and max distance to (px, py)
    float min_distance(float px, float py) const;
    float max_distance(float px, float py) const;

   private:
    uint8_t num_points;
};
}  // namespace LEDGeometry
