/*
 * @file rectangle.h
 * @brief Defines the Rectangle class for the Geometry namespace.
 */
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "geometry.h"

namespace Geometry {
/*
 * @class Rectangle
 * @brief Represents a rectangle defined by two corner points.
 *
 * The Rectangle class is derived from the Shape base class and provides
 * functionality to check for collisions with a point.
 */
class Rectangle : public Shape {
public:
  /*
   * @brief Bottom-left corner of the rectangle.
   */
  Point bottom_left;
  /*
   * @brief Top-right corner of the rectangle.
   */
  Point top_right;
  /*
   * @brief Constructs a Rectangle using two corner points.
   * @param x1 X-coordinate of the bottom-left corner.
   * @param y1 Y-coordinate of the bottom-left corner.
   * @param x2 X-coordinate of the top-right corner.
   * @param y2 Y-coordinate of the top-right corner.
   */
  Rectangle(double x1, double y1, double x2, double y2)
      : bottom_left(x1, y1), top_right(x2, y2) {}
  /*
   * @brief Checks if a point is within the rectangle.
   * @param point The point to check.
   * @return True if the point is inside or on the border of the rectangle,
   * false otherwise.
   */
  [[nodiscard]] bool isColliding(const Point &point) const override {
    return (point.x >= bottom_left.x && point.x <= top_right.x &&
            point.y >= bottom_left.y && point.y <= top_right.y);
  }
};
} // namespace Geometry

#endif // RECTANGLE_H
