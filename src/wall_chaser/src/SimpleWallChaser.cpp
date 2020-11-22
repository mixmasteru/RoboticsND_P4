#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "wall_chaser/DriveToTarget.h"

class SimpleWallChaser {
public:


    SimpleWallChaser() {
        //scan topic to subscribe
        sub = n.subscribe("/scan", 10, &SimpleWallChaser::callback, this);
        // Define a client service capable of requesting services from command_robot
        client = n.serviceClient<wall_chaser::DriveToTarget>("/wall_chaser/command_robot");
    }

    // This function calls the command_robot service to drive the robot in the specified direction
    void drive_robot(float lin_x, float ang_z) {
        //ROS_INFO_STREAM("Moving the bot);

        wall_chaser::DriveToTarget srv;
        srv.request.linear_x = lin_x;
        srv.request.angular_z = ang_z;

        if (!client.call(srv))
            ROS_ERROR("Failed to call service wall_chaser");
    }

    void callback(const sensor_msgs::LaserScan::ConstPtr &input) {
        //ROS_INFO("size: [%zd]",input->ranges.size());
        //ROS_INFO("range 0: [%f]",input->ranges[0]);
        //ROS_INFO("range 360: [%f]",input->ranges[360]);
        //ROS_INFO("range 719: [%f]",input->ranges[719]);
        float lin_x = 0.5;
        float ang_z = 0;
        float left = input->ranges[0];
        float mid = input->ranges[360];
        float right = input->ranges[719];
        if (left < min_range || mid < min_range) {
            ang_z = 1.2;
            //ROS_INFO("range: [%f]", mid);
        } else if (right < min_range) {
            ang_z = -1.2;
            //ROS_INFO("range: [%f]", right);
        }

        drive_robot(lin_x, ang_z);
    }

private:
    const float min_range = 1.3;
    const int start = 355;
    const int mid = 360;
    const int end = 365;

    ros::NodeHandle n;
    ros::Subscriber sub;
    // Define a global client that can request services
    ros::ServiceClient client;
};


int main(int argc, char **argv) {
    //Initiate ROS
    ros::init(argc, argv, "SimpleWallChaser");

    SimpleWallChaser simpleWallChaser;
    ros::spin();

    return 0;
}