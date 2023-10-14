cmake_minimum_required(VERSION 3.22)

project(YAPP VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

set(SRC_FILES src/yapp.cpp 
              src/map.cpp
              src/node.cpp
              src/graph.cpp)

find_package(SFML 2.5
  COMPONENTS
    system window graphics REQUIRED)

add_executable(planners ${SRC_FILES})
include_directories(inc)
target_link_libraries(planners sfml-graphics)
