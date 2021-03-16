#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char** argv){

// Initialize the arm_mover node "arm_mover is the node name"

ros::init(argc,argv,"arm_mover");

ros::NodeHandle n;

ros::Publisher joint1_pub = n.advertise<std_msgs::Float64>("/simple_arm/joint_1_position_controller/command", 10);

ros::Publisher joint2_pub = n.advertise<std_msgs::Float64>("/simple_arm/joint_2_position_controller/command", 10);

ros::Rate loop_rate(10);

int start_time; 
int elapsed;

while(not start_time){

start_time = ros::Time::now().toSec();
}

while(ros::ok()){

elapsed = ros::Time::now().toSec() - start_time;

std_msgs::Float64 joint1_angle;

std_msgs::Float64 joint2_angle;

// Set the arm joint angles

joint1_angle.data = sin(2 * M_PI * 0.1 * elapsed) * (M_PI / 2);

joint2_angle.data = sin(2 * M_PI * 0.1 * elapsed) * (M_PI / 2);

joint1_pub.publish(joint1_angle);
joint2_pub.publish(joint2_angle);

loop_rate.sleep();

}

return 0;

}

