#ifndef TALKER
#define TALKER

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

class Talker {
    
    public:
        Talker(void) {
            pub_ = nh_.advertise<std_msgs::String>("topic_name", 1);
        }
        ~Talker(void) {
            
        }
        void talk();
        ros::NodeHandle nh_;
        ros::Publisher pub_;
};

#endif