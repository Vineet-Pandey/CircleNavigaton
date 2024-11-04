
#ifndef ROBOT_H
#define ROBOT_H

#include "geometry.h"
#include <memory>
/**
 * @class Robot
 * @brief Represents a robot with a position and radius.
 */
class Robot {
private:
  /**
   * @brief The current position of the robot.
   */
  Geometry::Point position;
  /**
   * @brief The radius of the robot, used for size validation in the grid.
   */
  double radius; // check if the correct robot size is seen in the grid

public:
  /**
   * @brief Constructs a new Robot object with the specified position and
   * radius.
   * @param x The x-coordinate of the robot's initial position.
   * @param y The y-coordinate of the robot's initial position.
   * @param radius The radius of the robot.
   */
  Robot(double x, double y, double radius) : position(x, y), radius(radius) {}
  /**
   * @brief Gets the current position of the robot.
   * @return The current position as a Geometry::Point object.
   */
  [[nodiscard]] Geometry::Point getPosition() const { return position; }
  /**
   * @brief Moves the robot to a new position.
   * @param newPosition The new position to move the robot to.
   */
  void moveTo(Geometry::Point newPosition) { position = newPosition; }
};
#endif // ROBOT_H
