#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <vector>
#include <string>

class TrafficLightNode : public rclcpp::Node
{
public:
    TrafficLightNode() : Node("traffic_light_node"), state_index_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("/traffic/state", 10);

        // Állapotok: RED, RED+YELLOW, GREEN, YELLOW
        states_ = {"RED", "RED+YELLOW", "GREEN", "YELLOW"};
        durations_ = {5.0, 2.0, 5.0, 2.0}; // időtartam másodpercben

        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&TrafficLightNode::timer_callback, this)
        );
        counter_ = 0.0;
    }

private:
    void timer_callback()
    {
        counter_ += 1.0;
        if(counter_ >= durations_[state_index_])
        {
            counter_ = 0.0;
            state_index_ = (state_index_ + 1) % states_.size();
        }

        std_msgs::msg::String msg;
        msg.data = states_[state_index_];
        publisher_->publish(msg);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::vector<std::string> states_;
    std::vector<double> durations_;
    size_t state_index_;
    double counter_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TrafficLightNode>());
    rclcpp::shutdown();
    return 0;
}
