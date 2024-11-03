
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "geometry.h"

namespace Geometry {

class Rectangle : public Shape {
public:

  Point bottom_left;

  Point top_right;

  Rectangle(double x1, double y1, double x2, double y2)
      : bottom_left(x1, y1), top_right(x2, y2) {}

  [[nodiscard]] bool isColliding(const Point &point) const override {
    return (point.x >= bottom_left.x && point.x <= top_right.x &&
            point.y >= bottom_left.y && point.y <= top_right.y);
  }
};
} // namespace Geometry

#endif // RECTANGLE_H
