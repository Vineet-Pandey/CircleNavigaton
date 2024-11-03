
#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometry.h"

namespace Geometry {

class Circle : public Shape {
public:

  Point center;

  double radius;

  Circle(const Point &center, double radius) : center(center), radius(radius) {}

  bool isColliding(const Point &point) const override {
    double distance_squared = (point.x - center.x) * (point.x - center.x) +
                              (point.y - center.y) * (point.y - center.y);
    return distance_squared <= (radius * radius);
  }
};
} // namespace Geometry

#endif // CIRCLE_H
