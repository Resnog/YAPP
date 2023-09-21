cmake_minimum_required(VERSION 3.22)

project(YAPP VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5
  COMPONENTS
    system window graphics REQUIRED)

add_executable(planners src/display.cpp)
include_directories(inc)
target_link_libraries(planners sfml-graphics)
