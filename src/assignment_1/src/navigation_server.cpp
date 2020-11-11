
#include "ros/ros.h"
#include "assignment_1/GoTo.h"

#define Xmax 20 //!< X dimension of the Map 
#define Ymax 20 //!< Y dimension of the Map  

#define homeX 10 //!< X coordinate of the home
#define homeY 20 //!< Y coordinate of the home

#define userX 2 //!< X coordinate of the user
#define userY 3 //!< Y coordinate of the user

/*!This function print useful information fo the user interface suchs as:
 * - If the robot going home (for sleepin)
 * - If the robot is going to some position (during play and normal)
 * - If the robot is returning to the user (after play)
*/

void printlogs(int x ,int y)
{

  	if((x == homeX)&&(y == homeY))
	{
     		ROS_INFO("Returning Home");
    	}
		else if ((x == userX)&&(y == userY))
	{
      		ROS_INFO("Going to user");
    	}
		else{ROS_INFO("Going to: x=%ld, y=%ld wait...",x,y);
   	}
}

/*! This function given a requested goal position first chek if is inside the map boundaries and then simulate the navigation to the posisition and retun it when 'reached'*/
bool goTo(assignment_1::GoTo::Request  &request,
         assignment_1::GoTo::Response &response)
{ 
  	
  	printlogs((long int)request.x,(long int)request.y);
  	if((request.x <= Xmax) && (request.y <= Ymax))
	{
	     sleep(3); //this 'wait' is for simulate the robot moving 
	     response.ok = true;
	     response.currentX = request.x;
	     response.currentY = request.y; 
      	}
	else
	{
        	response.ok = false; 
       	}
  
  return true;
}
/*! Main function where the server is initialized*/
int main(int argc, char **argv)
{

	  ros::init(argc, argv, "navigation_server"); //node init
	  ros::NodeHandle n;

	  ros::ServiceServer service = n.advertiseService("navigation", goTo);
	  ROS_INFO(" Ready to go in a new position.");
	  ros::spin();

  return 0;
}
