
#ifndef BFS_H
#define BFS_H

#include "path_planner.h"
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>


class BFSPlanner : public PathPlanner {
public:

  std::vector<Geometry::Point> findPath(const GridMap &map,
                                        const Geometry::Point &start,
                                        const Geometry::Point &goal) override {
    std::vector<Geometry::Point> path;
    std::unordered_set<std::string> visited;

    std::queue<Geometry::Point> frontier;
    frontier.push(start);
    visited.insert(pointToKey(start));

    std::unordered_map<std::string, Geometry::Point> came_from;
    came_from[pointToKey(start)] = start;

    while (!frontier.empty()) {
      Geometry::Point current = frontier.front();
      frontier.pop();

      // Goal check
      if (current == goal) {
        return reconstructPath(came_from, start, goal);
      }

      for (const auto &neighbor : getNeighbors(current)) {
        if (!map.isOutOfBounds(neighbor) && !map.isCollision(neighbor) &&
            visited.find(pointToKey(neighbor)) == visited.end()) {

          frontier.push(neighbor);
          visited.insert(pointToKey(neighbor));
          came_from[pointToKey(neighbor)] = current;
        }
      }
    }

    std::cerr << "No path found!" << std::endl;
    return path;
  }
};

#endif // BFS_H
