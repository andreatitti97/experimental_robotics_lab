#include "ros/ros.h"
#include "assignment_1/GoTo.h"
#include  "geometry_msgs/Pose2D.h"

// max dimension for the map
#define Xmax 20
#define Ymax 20 

bool GoTo(assignment_1::GoTo::Request  &req,
         assignment_1::GoTo::Response &res)
{
 
  ROS_INFO("Go to quest: x=%ld, y=%ld", (long int)req.x, (long int)req.x);
  if((req.x <= Xmax) && (req.y <= Ymax)){
    res.o = 0; // the location is within the map boundaries
  }else{
        res.o = 1; // it's not
       }
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("navigation",GoTo);
  ROS_INFO("ready to go to new position");
  ros::spin();

  return 0;
}
