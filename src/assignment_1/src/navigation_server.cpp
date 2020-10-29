#include "ros/ros.h"
#include "assignment_1/GoTo.h"

/* This SERVER is used for navigate when the cmd_manager make a request after receveing a posisition to reach, so it has just to simulate the moving, respond to the cmd_manager that the robot reach the desired posisiton*/

//Dimensions of the map
#define Xmax 20
#define Ymax 20 

bool goTo(assignment_1::GoTo::Request  &req,
         assignment_1::GoTo::Response &res)
{
  	ROS_INFO("Go to position: x=%ld, y=%ld", (long int)req.x, (long int)req.y);//print for the user
  	if((req.x <= Xmax) && (req.y <= Ymax))
	{ 					//Check if the location is inside the map.
    		res.o = 0; 
	}
	else
	{
        res.o = 1; 
       	}
  
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_server"); //node initialization
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("navigation", goTo);//set the service.
  ROS_INFO("Ready to go in a new position.");
  ros::spin();

  return 0;
}
