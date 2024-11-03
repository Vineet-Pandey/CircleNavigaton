cmake_minimum_required(VERSION 3.16)
project(CircleNavigation)
set(CMAKE_CXX_STANDARD 17)

# Set the source file for the main executable
set(SOURCE_FILE src/main.cpp)

add_executable(CircleNavigation ${SOURCE_FILE})

target_include_directories(CircleNavigation PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(CircleNavigation PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

