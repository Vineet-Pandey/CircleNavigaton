
#ifndef PATH_PLANNER_H
#define PATH_PLANNER_H

#include "geometry.h"
#include "gridmap.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

class PathPlanner {
public:

  virtual ~PathPlanner() = default;


  virtual std::vector<Geometry::Point>
  findPath(const GridMap &map, const Geometry::Point &start,
           const Geometry::Point &goal) = 0;

protected:
 
  static std::string pointToKey(const Geometry::Point &point) {
    return std::to_string(point.x) + "," + std::to_string(point.y);
  }
 
  [[nodiscard]] static std::vector<Geometry::Point>
  getNeighbors(const Geometry::Point &current) {
    return std::vector<Geometry::Point>{
        Geometry::Point(current.x + 1, current.y),
        Geometry::Point(current.x - 1, current.y),
        Geometry::Point(current.x, current.y + 1),
        Geometry::Point(current.x, current.y - 1)};
  }

  [[nodiscard]] std::vector<Geometry::Point> reconstructPath(
      const std::unordered_map<std::string, Geometry::Point> &came_from,
      const Geometry::Point &start, const Geometry::Point &goal) const {
    std::vector<Geometry::Point> path;
    Geometry::Point trace = goal;

    while (!(trace == start)) {
      path.push_back(trace);
      trace = came_from.at(pointToKey(trace));
    }

    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
  }
};

#endif // PATH_PLANNER_H
