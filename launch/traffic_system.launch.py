from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='zsi_xo6_autonom',
            executable='traffic_light_node',
            name='traffic_light_node'
        ),
        Node(
            package='zsi_xo6_autonom',
            executable='car_node',
            name='car_node'
        )
    ])

