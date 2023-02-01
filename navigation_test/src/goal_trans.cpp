#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>

geometry_msgs::PoseStamped goal;

void trans_callback(const nav_msgs::Odometry& data){
    goal.header = data.header;
    goal.pose = data.pose.pose;
}

int main(int argc, char** argv){
   
    ros::init(argc, argv, "goal_trans");

    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/move_base_simple/goal", 1000, trans_callback);
    ros::Publisher pub = nh.advertise<geometry_msgs::PoseStamped>("/nav_goal", 50);
    while(nh.ok()){
        pub.publish(goal);
    }
}