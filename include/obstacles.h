
#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "geometry.h"
#include <memory>
#include <vector>
/**
 * @class Obstacles
 * @brief Represents a collection of obstacles in a 2D/3D space.
 *
 * This class is used to manage a collection of obstacles represented as
 * geometric shapes. It provides functionality to add obstacles and check if a
 * given point is colliding with any of the obstacles.
 */
class Obstacles {
private:
  std::vector<std::unique_ptr<Geometry::Shape>>
      obstacles; /**< A vector of unique pointers to geometric shapes
                    representing obstacles. */

public:
  /**
   * @brief Adds a new obstacle to the collection.
   *
   * @param obstacle A unique pointer to a geometric shape representing the
   * obstacle.
   */
  void addObstacle(std::unique_ptr<Geometry::Shape> obstacle) {
    obstacles.push_back(std::move(obstacle));
  }

  /**
   * @brief Returns the collection of obstacles.
   *
   * @return A vector of raw pointers to the geometric shapes representing the
   * obstacles.
   */
  [[nodiscard]] std::vector<Geometry::Shape *> getObstacles() const {
    std::vector<Geometry::Shape *> rawPointers;
    for (const auto &obstacle : obstacles) {
      rawPointers.push_back(obstacle.get());
    }
    return rawPointers;
  }
};

#endif // OBSTACLES_H
