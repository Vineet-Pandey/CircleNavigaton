
#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "geometry.h"
#include <memory>
#include <vector>

class Obstacles {
private:
  std::vector<std::unique_ptr<Geometry::Shape>>
      obstacles;

public:

  void addObstacle(std::unique_ptr<Geometry::Shape> obstacle) {
    obstacles.push_back(std::move(obstacle));
  }

  [[nodiscard]] std::vector<Geometry::Shape *> getObstacles() const {
    std::vector<Geometry::Shape *> rawPointers;
    for (const auto &obstacle : obstacles) {
      rawPointers.push_back(obstacle.get());
    }
    return rawPointers;
  }
};

#endif // OBSTACLES_H
