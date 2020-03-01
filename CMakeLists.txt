cmake_minimum_required(VERSION 3.5)
project(color_names)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
)

add_library(color_names SHARED
  src/color_names.cpp
)
ament_target_dependencies(color_names
  rclcpp
  std_msgs
)
ament_export_interfaces(export_color_names HAS_LIBRARY_TARGET)
ament_export_libraries(color_names)

install(TARGETS color_names
EXPORT export_color_names
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Install header files
install(
  DIRECTORY "include/"
  DESTINATION include
)

ament_export_libraries(color_names)
ament_export_include_directories(include)
ament_package()