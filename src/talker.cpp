#include "testing/talker.h"

void Talker::talk(){
    std_msgs::String msg;
    std::stringstream ss;
    ss<<"hello world";
    msg.data = ss.str();
    pub_.publish(msg);
}
