
#ifndef GEOMETRY_H
#define GEOMETRY_H

namespace Geometry {

struct Point {
  double x; 
  double y; 
  explicit Point(double x = 0, double y = 0) : x(x), y(y) {}
  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

class Shape {
public:

  virtual ~Shape() = default;

  [[nodiscard]] virtual bool isColliding(const Point &point) const = 0;
};

} // namespace Geometry

#endif // GEOMETRY_H
