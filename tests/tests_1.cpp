#include "testing/talker.h"

#include "rospy_tutorials/AddTwoInts.h"

#include <ros/ros.h>

#include <gtest/gtest.h>

#include <thread>
#include <chrono>

// using namespace std;

class MyTestSuite : public ::testing::Test {
  private:
    ros::ServiceServer mServer;
    int a, b;
    bool mFailService, mFailUnique;
    bool callback(rospy_tutorials::AddTwoInts::Request& req, rospy_tutorials::AddTwoInts::Response& res){
      a = req.a;
      b = req.b;
      res.sum = a+b;
      return res.sum;
    }
  public:
    MyTestSuite() {
      mServer = ros::NodeHandle().advertiseService("myTestService", &MyTestSuite::callback, this);
    }
    ~MyTestSuite() {}
};

TEST_F(MyTestSuite, firstTest) {
  ASSERT_EQ(1, 1) << "Sum is not correct";
}

TEST_F(MyTestSuite, secondTest) {
  ASSERT_EQ(12, 12) << "Sum is not correct";
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "TestNode");
    
    testing::InitGoogleTest(&argc, argv);
    
    std::thread t([]{while(ros::ok()) ros::spin();});
    
    auto res = RUN_ALL_TESTS();
    
    ros::shutdown();
    
    return res;
}
