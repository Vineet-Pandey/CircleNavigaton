#include "../include/bfs.h"
#include "../include/circle.h"
#include "../include/geometry.h"
#include "../include/gridmap.h"
#include "../include/obstacles.h"
#include "../include/path_planner.h"
#include "../include/rectangle.h"
#include "../include/robot.h"
#include <gtest/gtest.h>

// Test case for BFSPlanner::findPath
TEST(BFSPlannerTest, FindsPathInSimpleGrid) {
    GridMap map(Geometry::Rectangle(-10, -10, 10, 10));
    Geometry::Point start(0, 0);
    Geometry::Point goal(5, 5);
    BFSPlanner planner;
    auto path = planner.findPath(map, start, goal);
    EXPECT_FALSE(path.empty());
    EXPECT_EQ(path.front(), start);
    EXPECT_EQ(path.back(), goal);
}

// Test case for Geometry::Circle collision detection
TEST(CircleTest, PointInsideCircle) {
    Geometry::Circle circle(Geometry::Point(0, 0), 5);
    Geometry::Point point(3, 4);
    EXPECT_TRUE(circle.isColliding(point));
}

TEST(CircleTest, PointOutsideCircle) {
    Geometry::Circle circle(Geometry::Point(0, 0), 5);
    Geometry::Point point(6, 0);
    EXPECT_FALSE(circle.isColliding(point));
}

// Test case for Geometry::Rectangle collision detection
TEST(RectangleTest, PointInsideRectangle) {
    Geometry::Rectangle rect(0, 0, 10, 10);
    Geometry::Point point(5, 5);
    EXPECT_TRUE(rect.isColliding(point));
}

TEST(RectangleTest, PointOutsideRectangle) {
    Geometry::Rectangle rect(0, 0, 10, 10);
    Geometry::Point point(15, 15);
    EXPECT_FALSE(rect.isColliding(point));
}

// Test case for Robot movement
TEST(RobotTest, RobotMovement) {
    Robot robot(0, 0, 1);
    Geometry::Point newPosition(5, 5);
    robot.moveTo(newPosition);
    EXPECT_EQ(robot.getPosition(), newPosition);
}

// Test case for GridMap bounds
TEST(GridMapTest, PointOutOfBounds) {
    GridMap map(Geometry::Rectangle(-10, -10, 10, 10));
    Geometry::Point point(11, 5);
    EXPECT_TRUE(map.isOutOfBounds(point));
}

TEST(GridMapTest, PointWithinBounds) {
    GridMap map(Geometry::Rectangle(-10, -10, 10, 10));
    Geometry::Point point(5, 5);
    EXPECT_FALSE(map.isOutOfBounds(point));
}

// Test point collision with obstacles
TEST(GridMapTest, PointCollision) {
    Geometry::Rectangle boundary(0, 0, 10, 10);
    GridMap gridMap(boundary);

    std::vector<std::unique_ptr<Geometry::Shape>> obstacles;
    obstacles.push_back(std::make_unique<Geometry::Circle>(Geometry::Point(2, 2), 1));
    gridMap.addObstacles(obstacles);

    Geometry::Point collisionPoint(2, 2);
    EXPECT_TRUE(gridMap.isCollision(collisionPoint));

    Geometry::Point nonCollisionPoint(8, 8);
    EXPECT_FALSE(gridMap.isCollision(nonCollisionPoint));
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
