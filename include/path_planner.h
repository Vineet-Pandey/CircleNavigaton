
#ifndef PATH_PLANNER_H
#define PATH_PLANNER_H

#include "geometry.h"
#include "gridmap.h"
#include <algorithm>
#include <unordered_map>
#include <vector>
/**
 * @class PathPlanner
 * @brief Abstract class that defines the interface for a path planner.
 */
class PathPlanner {
public:
  /**
   * @brief Virtual destructor for PathPlanner.
   */
  virtual ~PathPlanner() = default;

  /**
   * @brief Pure virtual function to find a path between two points on a grid
   * map.
   * @param map The grid map representing the environment.
   * @param start The starting point of the path.
   * @param goal The goal point of the path.
   * @return A vector of points representing the path from start to goal.
   */
  virtual std::vector<Geometry::Point>
  findPath(const GridMap &map, const Geometry::Point &start,
           const Geometry::Point &goal) = 0;

protected:
  /**
   * @brief Utility function to generate a unique key for a point.
   * @param point The point to generate a key for.
   * @return A string representing the unique key for the point.
   */
  static std::string pointToKey(const Geometry::Point &point) {
    return std::to_string(point.x) + "," + std::to_string(point.y);
  }
  /**
   * @brief Get the neighboring points of the current point.
   * @param current The current point.
   * @return A vector of points representing the neighbors of the current point.
   */
  [[nodiscard]] static std::vector<Geometry::Point>
  getNeighbors(const Geometry::Point &current) {
    return std::vector<Geometry::Point>{
        Geometry::Point(current.x + 1, current.y),
        Geometry::Point(current.x - 1, current.y),
        Geometry::Point(current.x, current.y + 1),
        Geometry::Point(current.x, current.y - 1)};
  }

  /**
   * @brief Reconstruct the path from the start to the goal point.
   * @param came_from A map that stores the points and their predecessors.
   * @param start The starting point of the path.
   * @param goal The goal point of the path.
   * @return A vector of points representing the reconstructed path from start
   * to goal.
   */
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
