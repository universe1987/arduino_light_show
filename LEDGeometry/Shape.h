#pragma once

namespace LEDGeometry {
class Shape {
   public:
    Shape(int n_points) : n_points_(n_points){};
    virtual ~Shape() {}
    virtual float x(int i) const = 0;
    virtual float y(int i) const = 0;
    int n_points() const { return n_points_; };
    float r(int i) const;

   private:
    int n_points_;
};
}  // namespace LEDGeometry
