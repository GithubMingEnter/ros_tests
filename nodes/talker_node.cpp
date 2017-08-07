#include <ros/ros.h>
#include "testing/talker.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "talker");
    Talker rt;
    ros::Rate loop_rate(1);
    while(ros::ok()){
        rt.talk();
        loop_rate.sleep();
        ros::spinOnce();
    }
    return 0;
}