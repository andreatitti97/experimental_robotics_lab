
#include "ros/ros.h"
#include "assignment_1/GoTo.h"

//Dimensions of the map
#define Xmax 20
#define Ymax 20 

bool goTo(assignment_1::GoTo::Request  &req,
         assignment_1::GoTo::Response &res)
{
	ROS_INFO("Go to position: x=%ld, y=%ld", (long int)req.x, (long int)req.y);//print for the user
	if((req.x <= Xmax) && (req.y <= Ymax))
	{
		sleep(3); //which simulate the movement of the robot 
		res.ok = true;
		res.currentX = req.x;
		res.currentY = req.y; 
      	}
	else
	{
        	res.ok = false; 
       	}
  
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_server"); //node initialization
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("navigation", goTo);//set the service.
  ROS_INFO("Ready for posistion.");
  ros::spin();

  return 0;
}
