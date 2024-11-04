
#ifndef GRIDMAP_H
#define GRIDMAP_H
#include "obstacles.h"
#include "rectangle.h"
#include <vector>
/**
 * @class GridMap
 * @brief Represents a grid environment with a boundary and obstacles.
 *
 * The GridMap class allows for defining a boundary using a rectangular shape
 * and managing obstacles within this boundary. It provides functions to add
 * obstacles and check for collisions or boundary violations.
 */
class GridMap {
private:
  Geometry::Rectangle boundary; /**< The rectangular boundary of the grid map */
  Obstacles obstacle_manager; /**< The manager for handling obstacles within the
                                 grid.*/

public:
  /**
   * @brief Constructs a GridMap with the specified boundary.
   * @param bound The rectangular boundary of the grid map.
   */
  explicit GridMap(const Geometry::Rectangle &bound) : boundary(bound) {}
  /**
   * @brief Adds a list of obstacles to the grid map.
   * @param obs A vector of unique pointers to obstacles to be added.
   */
  void addObstacles(std::vector<std::unique_ptr<Geometry::Shape>> &obs) {
    for (auto &ele : obs) {
      obstacle_manager.addObstacle(std::move(ele));
    }
  }
  /**
   * @brief Checks if a point is in collision with any obstacle.
   * @param point The point to be checked.
   * @return True if the point is colliding with any obstacle, otherwise false.
   */
  [[nodiscard]] bool isCollision(const Geometry::Point &point) const {

    for (const auto &obstacle : obstacle_manager.getObstacles()) {
      if (obstacle->isColliding(point)) {
        return true;
      }
    }
    return false;
  }
  /**
   * @brief Checks if a point is out of the grid map boundary.
   * @param point The point to be checked.
   * @return True if the point is out of bounds, otherwise false.
   */
  [[nodiscard]] bool isOutOfBounds(const Geometry::Point &point) const {
    return !boundary.isColliding(
        point); // Check if the point is outside the boundary
  }
};

#endif // GRIDMAP_H
