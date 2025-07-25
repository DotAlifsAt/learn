cmake_minimum_required(VERSION 3.8)
project(learn)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable( learn_node
  src/learn_node.cpp
  src/learn.cpp
)

target_include_directories(learn_node PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

ament_target_dependencies(learn_node rclcpp std_msgs)

install(
  TARGETS learn_node
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
