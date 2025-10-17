#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include <string>

class CarNode : public rclcpp::Node
{
public:
    CarNode() : Node("car_node")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "/traffic/state", 10,
            std::bind(&CarNode::traffic_callback, this, std::placeholders::_1)
        );

        status_pub_ = this->create_publisher<std_msgs::msg::String>("/car/status", 10);
        moving_pub_ = this->create_publisher<std_msgs::msg::Bool>("/car/is_moving", 10);
    }

private:
    void traffic_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        std_msgs::msg::String status_msg;
        std_msgs::msg::Bool moving_msg;

        if(msg->data == "RED")
        {
            status_msg.data = "Az autó megáll";
            moving_msg.data = false;
        }
        else if(msg->data == "RED+YELLOW")
        {
            status_msg.data = "Felkészülés az indulásra";
            moving_msg.data = false;
        }
        else if(msg->data == "GREEN")
        {
            status_msg.data = "Az autó halad";
            moving_msg.data = true;
        }
        else if(msg->data == "YELLOW")
        {
            status_msg.data = "Az autó lassít";
            moving_msg.data = true;
        }

        status_pub_->publish(status_msg);
        moving_pub_->publish(moving_msg);
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr moving_pub_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CarNode>());
    rclcpp::shutdown();
    return 0;
}
