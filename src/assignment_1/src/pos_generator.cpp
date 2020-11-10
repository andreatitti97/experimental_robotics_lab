/*!
 * \author Andrea Tiranti
 */
#include "ros/ros.h"
#include "geometry_msgs/Pose2D.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

/*!
This node publish random position in the map, for simulationg both the gesture recognition and the normal behaviour where the robot move randomly
*/

int main (int argc, char **argv)
{

	//generation of the random position
	int x = rand() % 15;
	int y = rand() % 15;


	ros::init(argc,argv,"position_generator"); //node initialization

	ros::Publisher pub; //make the node publisher
	ros::NodeHandle nh;

	pub = nh.advertise<geometry_msgs::Pose2D>("position", 1000); //publisher and topic initialization

	ros::Rate loop_rate(1); //rate for the loop


	while(ros::ok())
	{

		geometry_msgs::Pose2D pose; //struct were saving the posisiton to pass to the cmd_manager
				    
		pose.x = x ;
		pose.y = y ;


		ROS_INFO("The position is x : %d and y : %d ", x,y);//print the position for the user

		pub.publish(pose);//publish this position 

		ros::spinOnce();

		loop_rate.sleep();//delay for see the behavior
		x = rand() % 15;
		y = rand() % 15;
	    
	}

	return 0;
}
