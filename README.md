# Robot Navigation

## Overview

This project is a navigation solution for a virtual world called "CircleNavigation." The main components of the solution include algorithms and data structures designed for path planning and obstacle avoidance. It is suitable for a robotics application where efficient navigation through a grid map with various obstacles is needed. The solution is implemented in C++ and makes use of multiple header and source files to break down different components of the navigation system.

## Project Structure

The project contains the following files:

- **main.cpp**: The entry point for the application, where the various components are brought together to demonstrate path planning capabilities.
- **bfs.h**: Contains the implementation of the Breadth-First Search (BFS) algorithm, which is used for finding the shortest path in the grid map.
- **circle.h**: Defines the Circle class, which represents circular obstacles in the environment.
- **geometry.h**: Provides geometric functions and operations used by other components, including distance calculations and intersection tests.
- **gridmap.h**: Implements the GridMap class, which represents the navigable environment. It provides utilities for managing obstacles and checking if locations are valid.
- **obstacles.h**: Manages obstacles in the environment, including adding and representing different types of obstacles.
- **path_planner.h**: Implements the PathPlanner class, which coordinates different algorithms to generate a valid path from the start to the goal.
- **rectangle.h**: Defines the Rectangle class, which represents rectangular obstacles in the environment.
- **robot.h**: Represents the robot, including its position, size, and functions for interacting with the environment.

## Compilation and Execution

To compile and run the project, you will need CMake and a C++ compiler. Use the following commands from the `CircleNavigation` directory:

1. **Install Pre-requisites**:
   ```sh
   ./install.sh
   ```

2. **Build the Project**:
   ```sh
   ./run.sh
   ```

3. **Run the Tests**:
   ```sh
   ./build/bin/UnitTests
   ```
   
4. **Run the Executable**:
   ```sh
   ./build/bin/CircleNavigaton
   ```

## Features

- **Breadth-First Search Path Planning**: Uses the BFS algorithm for finding a path through the grid. This method can be used since the graph isn't weighed. If the graph is weighed, methods like ```A*``` which have heuristic-based approach, can be used.
- **Obstacle Management**: Supports both circular and rectangular obstacles, allowing for diverse environment setups.
- **Grid Representation**: The environment is represented as a grid, making it easy to work with different pathfinding algorithms.

## Dependencies

- **CMake**: Used for building the project.
- **C++17** or later: Required for compiling the source code.

## Usage

1. Define obstacles and a grid environment in `main.cpp`.
2. Instantiate the robot and set its start and goal positions.
3. Use the `PathPlanner` to compute a valid path around obstacles.
4. Print the path using output utilities.

## Future Improvements

- Implement more advanced pathfinding algorithms (e.g., Dijkstra's,A*).
- Introduce dynamic obstacle avoidance.
- Use configuration files like `.yaml` to setup the `path planner`, `start`, `end` etc.

## License

This project is open-source and available under the MIT License.

## Author

This project was created by Vineet Pandey

