/*!
 * \author Andrea Tiranti
 * \bug 
 *  - If in SLEEP state all PLAY command rejected. 
 *  - User posisiton fixed. 
 *  - During action no possible to stop it.
 
 *\mainpage Navigation Server
 *\section intro_sec Introduction 
 * Assignment 1 Experimental Robotics Laboratory. This software architecture simulate the behaviour of a robot that switch beetween 3 different states: NORMAL, SLEEP, PLAY.
 *\section cmd_manager_sec Command Manager
 * This node handle the Finite State Machine and the navigation of the robot, subscribe 2 topics and it is client of the server navigation
 *\section navigation_server_sec Navigation Server
 * Server responsable of the navigation
 *\section user_cmd_sec User Command
 * Node that simulate the user command PLAY
 *\section pos_generator_sec Position Generator
 * This Node radomize position pulibshed in the topic 'position' that simulate both NORMAL and PLAY behaviour.
*/

#include "ros/ros.h"
#include "assignment_1/user_cmd.h"
#include "std_msgs/String.h"
#include <sstream>

/*! This node simulate the user command (that is a voice cmd), publishing the state PLAY as a string to the cmd_manager, that when receive it should switch to PLAY mode if in NORMAL mode, if in SLEEP mode the cmd is rejected*/

int main (int argc, char **argv){

ros::init(argc,argv,"user_cmd"); //node initialization 

ros::Publisher pub; //make the node publisher
ros::NodeHandle nh;

pub = nh.advertise<std_msgs::String>("cmd_string", 100); // publisher and topic initialization 

ros::Rate loop_rate(1); // rate for the loop 

int time = 15;

while(ros::ok())
	{

	std_msgs::String msg; // msg contain the string to pass to the cmd_manager 

	std::stringstream ss;
    
    	msg.data = "play";//the string passed 

    	ROS_INFO("state detection: %s", msg.data.c_str());//print the string for the user 

    	pub.publish(msg);// publish to the cmd_manager

   	ros::spinOnce();
	
    	sleep(time); //random delay for publishing as request
    	time = rand() % 6 + 15;


	}

return 0;
}
