
#ifndef BFS_H
#define BFS_H

#include "path_planner.h"
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

/**
 * @class BFSPlanner
 * @brief Implements a breadth-first search (BFS) pathfinding algorithm.
 *
 * This class inherits from the PathPlanner interface and provides an
 * implementation for the findPath function using the BFS algorithm. The
 * BFSPlanner is capable of finding a path between two points in a grid-based
 * map.
 */
class BFSPlanner : public PathPlanner {
public:
  /**
   * @brief Finds a path from the start point to the goal point using BFS.
   *
   * This method implements the BFS algorithm to find the shortest path in a
   * grid map. It uses a queue to explore the nodes in a breadth-first manner
   * and keeps track of visited nodes to avoid redundant processing.
   *
   * @param map The grid map to search for the path.
   * @param start The starting point of the path.
   * @param goal The goal point of the path.
   * @return A vector of points representing the path from start to goal.
   */
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
