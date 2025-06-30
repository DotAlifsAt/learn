#include "learn/learn.hpp"

#include "rclcpp/rclcpp.hpp"


int main(int argc, char* argv[])
  {
    rclcpp::init(argc, argv);

    auto node = std::make_shared<LearnNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;

  }