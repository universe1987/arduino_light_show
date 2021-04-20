#pragma once

namespace LEDGeometry {
class Shape {
   public:
    Shape(int num_points) : num_points(num_points){};
    virtual ~Shape() {}
    // x coordinate
    virtual float x(int i) const = 0;
    // y coordinate
    virtual float y(int i) const = 0;
    // Euclidean distance to the origin
    float r(int i) const;
    // number of points on the shape
    int n_points() const;
    float min_x() const;
    float max_x() const;
    float min_y() const;
    float max_y() const;
    float min_r() const;
    float max_r() const;

   private:
    int num_points;
};
}  // namespace LEDGeometry
