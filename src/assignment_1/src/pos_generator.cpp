#include "ros/ros.h"
#include "assignment_1/GoTo.h"
#include  "geometry_msgs/Pose2D.h"

int main (int argc, char **argv){

	int x = rand() % 15;
	int y = rand() % 15;
	ros::init(argc,argv,"pos_generator"); //node initialization
	ros::Publisher pub;
	ros::NodeHandle nh;

	pub = nh.advertise<geometry_msgs::Pose2D>("Position",1000); //Publicher and topi init

	ros::Rate loop_rate(3); //it'll be random in the simulation ohase
	int count = 0;
//count ohw many msgs sent, to create a unique string for each msg.
	while(ros::ok())
	{
		
		geometry_msgs::Pose2D pos;
		pos.x = x;
		pos.y = y;

		ROS_INFO("The (x,y) position is : (%d,%d)",x,y);

		pub.publish(pos);

		ros::spinOnce();

		loop_rate.sleep();
		x = rand() % 15;
    		y = rand() % 15;
		
	}
	
	return 0;
}
