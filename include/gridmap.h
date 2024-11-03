
#ifndef GRIDMAP_H
#define GRIDMAP_H
#include "obstacles.h"
#include "rectangle.h"
#include <vector>

class GridMap {
private:
  Geometry::Rectangle boundary; 
  Obstacles obstacle_manager; 

public:
  
  explicit GridMap(const Geometry::Rectangle &bound) : boundary(bound) {}
 
  void addObstacles(std::vector<std::unique_ptr<Geometry::Shape>> &obs) {
    for (auto &ele : obs) {
      obstacle_manager.addObstacle(std::move(ele));
    }
  }

  [[nodiscard]] bool isCollision(const Geometry::Point &point) const {

    for (const auto &obstacle : obstacle_manager.getObstacles()) {
      if (obstacle->isColliding(point)) {
        return true;
      }
    }
    return false;
  }

  [[nodiscard]] bool isOutOfBounds(const Geometry::Point &point) const {
    return !boundary.isColliding(
        point); 
  }
};

#endif // GRIDMAP_H
