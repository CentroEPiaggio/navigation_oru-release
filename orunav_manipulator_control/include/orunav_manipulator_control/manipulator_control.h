#ifndef MANIPULATOR_CONTROL_CITI_TRUCK_H
#define MANIPULATOR_CONTROL_CITI_TRUCK_H

#include <lwr_controllers/PoseRPY.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <map>
#include <orunav_msgs/ManipulatorReport.h>
#include <orunav_msgs/ManipulatorCommand.h>

class manipulatorControl
{
public:
    manipulatorControl();
    ~manipulatorControl();

    void move();

private:
    ros::NodeHandle nh;
    ros::Publisher cmd_pub_left;
    ros::Publisher cmd_pub_right;

    ros::Subscriber command_sub;
    void process_manipulator_command(const orunav_msgs::ManipulatorCommand::ConstPtr &msg);

    tf::TransformListener listener;

    void send_target();
    
    orunav_msgs::ManipulatorCommand last_cmd;
    
    void from_ManipulatorCommand_to_PoseRPY(const orunav_msgs::ManipulatorCommand& in, lwr_controllers::PoseRPY out);
};

#endif