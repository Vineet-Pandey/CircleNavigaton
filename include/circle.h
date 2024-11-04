/**
 * @file circle.h
 * @brief Defines the Circle class for geometric calculations.
 *
 * This file contains the definition of the Circle class, which is derived from
 * the Shape class and represents a circle in a 2D space.
 */
#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometry.h"

namespace Geometry {

/**
 * @class Circle
 * @brief A class representing a circle in 2D space.
 *
 * The Circle class inherits from the Shape class and provides methods
 * to determine geometric properties of a circle, such as collision detection.
 */
class Circle : public Shape {
public:
  /**
   * @brief The center point of the circle.
   */
  Point center;
  /**
   * @brief The radius of the circle.
   */
  double radius;
  /**
   * @brief Constructs a Circle with a given center and radius.
   * @param center The center point of the circle.
   * @param radius The radius of the circle.
   */
  Circle(const Point &center, double radius) : center(center), radius(radius) {}
  /**
   * @brief Checks if a given point is colliding with the circle.
   * @param point The point to check for collision.
   * @return True if the point is inside or on the circle, false otherwise.
   */
  bool isColliding(const Point &point) const override {
    double distance_squared = (point.x - center.x) * (point.x - center.x) +
                              (point.y - center.y) * (point.y - center.y);
    return distance_squared <= (radius * radius);
  }
};
} // namespace Geometry

#endif // CIRCLE_H
