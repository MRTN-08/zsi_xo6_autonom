cmake_minimum_required(VERSION 3.5)
project(zsi_xo6_autonom)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Build traffic_light_node
add_executable(traffic_light_node src/traffic_light_node.cpp)
ament_target_dependencies(traffic_light_node rclcpp std_msgs)

# Build car_node
add_executable(car_node src/car_node.cpp)
ament_target_dependencies(car_node rclcpp std_msgs)

# Install executables
install(TARGETS
  traffic_light_node
  car_node
  DESTINATION lib/${PROJECT_NAME}
)

# Telepítsd a launch mappát
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

# Ament package
ament_package()


