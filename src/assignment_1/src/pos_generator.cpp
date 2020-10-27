#include "ros/ros.h"
#include "assignment_1/state.h"

bool add(assignment_1::state::Request  &req,
         assignment_1::state::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pos_generator");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("state", add);
  ROS_INFO("ready to receive state");
  ros::spin();

  return 0;
}
