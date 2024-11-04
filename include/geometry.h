
#ifndef GEOMETRY_H
#define GEOMETRY_H
/**
 * @namespace Geometry
 * @brief Contains geometric structures and classes for handling
 * geometry-related operations.
 */
namespace Geometry {
/**
 * @struct Point
 * @brief Represents a point in 2D space.
 */
struct Point {
  double x; /**< X-coordinate of the point. */
  double y; /**< Y-coordinate of the point. */
  /**
   * @brief Constructs a Point with given coordinates.
   * @param x The X-coordinate (default is 0).
   * @param y The Y-coordinate (default is 0).
   */
  explicit Point(double x = 0, double y = 0) : x(x), y(y) {}
  /**
   * @brief Checks if two points are equal.
   * @param other The point to compare with.
   * @return True if the points have the same coordinates, false otherwise.
   */
  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};
/**
 * @class Shape
 * @brief Abstract base class representing a geometric shape.
 */
class Shape {
public:
  /**
   * @brief Virtual destructor for Shape.
   */
  virtual ~Shape() = default;
  /**
   * @brief Checks if the shape is colliding with a given point.
   * @param point The point to check for collision.
   * @return True if the point is colliding with the shape, false otherwise.
   */
  [[nodiscard]] virtual bool isColliding(const Point &point) const = 0;
};

} // namespace Geometry

#endif // GEOMETRY_H
