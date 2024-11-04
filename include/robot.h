
#ifndef ROBOT_H
#define ROBOT_H

#include "geometry.h"
#include <memory>

class Robot {
private:

  Geometry::Point position;

  double radius; 

public:

  Robot(double x, double y, double radius) : position(x, y), radius(radius) {}

  [[nodiscard]] Geometry::Point getPosition() const { return position; }

  void moveTo(Geometry::Point newPosition) { position = newPosition; }
};
#endif // ROBOT_H
