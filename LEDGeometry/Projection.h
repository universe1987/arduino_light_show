#pragma once

#include <stdint.h>

namespace LEDGeometry {
class Shape;

void radial_projection(Shape* shape, uint8_t* projection, uint8_t resolution,
                       float center_x, float center_y);

void radial_projection(Shape* shape, uint8_t* projection, uint8_t resolution);

void parallel_projection(Shape* shape, uint8_t* projection, uint8_t resolution,
                         float direction_x, float direction_y);

void parallel_projection(Shape* shape, uint8_t* projection, uint8_t resolution);

void intrinsic_projection(Shape* shape, uint8_t* projection,
                          uint8_t resolution);
}  // namespace LEDGeometry
