
#include "bfs.h"
#include "circle.h"
#include "robot.h"
#include <iostream>

int main() {
  // Define robot and map
  Robot robot(0, 0, 1.0);
  Geometry::Rectangle boundary(-20, -20, 20, 20);
  GridMap map(boundary);

  // Add obstacles
  std::vector<std::unique_ptr<Geometry::Shape>> obstacles;
  obstacles.push_back(
      std::make_unique<Geometry::Circle>(Geometry::Point(5, 1), 1.0));
  map.addObstacles(obstacles);

  // Select a planner
  BFSPlanner planner;

  // Plan path
  Geometry::Point start(0, 0);
  Geometry::Point goal(10, 10);
  std::vector<Geometry::Point> path = planner.findPath(map, start, goal);

  // output
  for (const auto &point : path) {
    std::cout << "(" << point.x << ", " << point.y << ")\n";
  }

  return 0;
}
