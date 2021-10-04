#include "ros/ros.h"

#include "temp_package/Service.h"

bool func(temp_package::Service::Request  &req,
          temp_package::Service::Response &res)
{
    ROS_INFO("SERVER SERVICE");
    
    res.name = req.inp_name;
    res.num = rand();
    
    return 1;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "srv_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("service_call", func);
    
    ros::spin();

    return 0;
}
