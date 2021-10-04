#include "ros/ros.h"
#include "temp_package/Service.h"
#include "temp_package/Message.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "srv_client");
    ros::NodeHandle n;
    
    ros::Publisher pub = n.advertise<temp_package::Message>("/temp_package/srv_client_msg", 1);
    ros::ServiceClient client = n.serviceClient<temp_package::Service>("service_call");
    
    temp_package::Service srv;    
    temp_package::Message output;
    
    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        srv.request.inp_name = "Hello";
        if (client.call(srv))
        {
            ROS_INFO("CLIENT SERVICE");
            output.name = srv.response.name;
            output.num = srv.response.num;
        }
        else
        {
            ROS_ERROR("FAILED TO CALL SERVICE");
        }
        pub.publish(output);
        
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 1;
}
