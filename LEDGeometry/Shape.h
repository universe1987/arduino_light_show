#pragma once

namespace LEDGeometry {
class Shape {
   public:
    Shape(int n_points) : n_points_(n_points){};
    virtual ~Shape() {}
    // x coordinate, -1 <= x <= 1
    virtual float x(int i) const = 0;
    // y coordinate, -1 <= y <= 1
    virtual float y(int i) const = 0;
    // Euclidean distance to the origin
    float r(int i) const;
    // number of points on the shape
    int n_points() const { return n_points_; };

   private:
    int n_points_;
};
}  // namespace LEDGeometry
