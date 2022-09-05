//
// Created by dinhnambkhn on 22. 9. 3.
//
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

//using std::placeholders::_1;

class MinimalSubcriber : public rclcpp::Node {
public:
    MinimalSubcriber() : Node("minimal_subcriber") {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
                "topic", 10, std::bind(&MinimalSubcriber::topic_callback, this, std::placeholders::_1));
    }

private:
    void topic_callback(const std_msgs::msg::String &msg) const {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubcriber>());
    rclcpp::shutdown();
    return 0;
}