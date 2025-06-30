#ifndef LEARN__LEARN_HPP_
#define LEARN__LEARN_HPP_  



#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"


class LearnNode : public rclcpp::Node // Declaring LearnNode Class, that inherits from rclcpp::Node
{
public:
  LearnNode(); //Constructor

private:
  void callback(); //Method named callback


  rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_; //Declares a shared pointer the messages of std_msgs::msg::Int64
  rclcpp::TimerBase::SharedPtr timer_; //Declares a shared pointer to callback

  int data;

};


#endif  // LEARN__LEARN HPP_
 