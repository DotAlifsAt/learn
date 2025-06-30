#include "learn/learn.hpp"

#include <memory>
#include <chrono>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

using namespace std::chrono_literals;


LearnNode::LearnNode()
: Node("learn_node"), data(0)
{
  publisher_ = this->create_publisher<std_msgs::msg::Int64>("ini_Topic", 10);  //This creates a publisher
  //Name = ini_Topic
  //Queue Size = 10, basically this could hold up to to 10 messages queued up, not the limit ammount of messages
  //std_msgs::msg::Int64, this is a data type, its fine :3


  timer_ = this->create_wall_timer(std::chrono::seconds (1s), std::bind(&LearnNode::callback, this)); //creates a timer that periodically calls "Callback" from line 15
  //ls is the ammount of time between calling it, placeholder
  //(std::bind(&LearnNode::callback, this) this binds the callback method to this instance
}

void LearnNode::callback()
{
 
  std_msgs::msg::Int64 message;

  message.data = data++;
  publisher_ -> publish(message);

  RCLCPP_INFO(this->get_logger(), "Publish : %i", data);

  RCLCPP_WARN(this->get_logger(), "Publish : %i", data);
}


