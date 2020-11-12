#!/usr/bin/env python2

## @package cmd_manager
#  This node is the core of the system, subscribe to 'position' topic and 'cmd_string' topic, and is the client of the 'navigation' service.
#  In this node is implemented the Finite State Machine 
#  which manage the switch between states according to the information coming from the other nodes.
 
## Documentation for a function.
#
#  More details.

from __future__ import print_function

import roslib
import rospy
import smach
import smach_ros
import time
import random
import sys
from std_msgs.msg import String
from geometry_msgs.msg import Pose2D

from assignment_1.srv import *

## robot X position variable
# @param X initial X pos of the robot
X = 0  
## robot Y position variable
# @param Y initial Y pos of the robot
Y = 0
## home X position
# @param homeX inital X pos of the home
homeX = 10
## home Y position
# @param homeY inital Y pos of the house
homeY = 20
## State variable
# @param state variable that save the PLAY state coming from the user, if sended 
user_cmd = "NoInfo"

userX = 2
userY = 3

## Function that randomize the choice for choosing states NORMAL and SLEEP
def decision():
    return random.choice(['goToNormal','goToSleep'])

## Callback for 'position' subscriber
def callbackPos(data):
    global X
    X = data.x
    global Y 
    Y = data.y    

## Callback for 'user_cmd' subscriber  
def callbackSta(data): 
    rospy.loginfo(rospy.get_caller_id() + " Received cmd %s", data.data)
    global user_cmd 
    user_cmd = "play"

## Client function for navigation service 
def navigation(x,y):

    global homeX
    global homeY
    global userX
    global userY
    rospy.wait_for_service('navigation')
    try:
        go_to = rospy.ServiceProxy('navigation',GoTo)
        check = go_to(x ,y)
        if check.ok == True:
            if (check.currentX ==homeX) & (check.currentY ==homeY):
                rospy.loginfo(rospy.get_caller_id() + " Robot at home" )
            elif (check.currentX == userX) & (check.currentY == userY):
                rospy.loginfo(rospy.get_caller_id() + " Robot returned to user" )
            else:
                rospy.loginfo(rospy.get_caller_id() + " Robot arrived at x: %d , y: %d", check.currentX, check.currentY )
             
        else: 
            rospy.loginfo(rospy.get_caller_id() + " Impossible Position")
        return check.ok
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

## Define state NORMAL
class Normal(smach.State):
    def __init__(self):
        # Init of the function
        smach.State.__init__(self, 
                             outcomes=['goToNormal','goToSleep','goToPlay'],
                             input_keys=['unlocked_counter_in'],
                             output_keys=['unlocked_counter_out'])
        self.rate = rospy.Rate(1) 
        self.counter = 0
        
    def execute(self,userdata):

        global X
        global Y
        global user_cmd
        
        self.counter = random.randint(1,2) #For randomize the switch to SLEEP state 
        while not rospy.is_shutdown():  
            time.sleep(1)
            if user_cmd == "play":
                user_cmd = 'noInput'
                return 'goToPlay'
            if self.counter == 4:
                return 'goToSleep'           
            navigation(X,Y) # Request to service for navigate. (is simulated)

            self.counter += 1
            
        return 'goToSleep' 
        
    

## Define state SLEEP
class Sleep(smach.State):
    def __init__(self):
        smach.State.__init__(self, 
                             outcomes=['goToNormal','goToSleep'],
                             input_keys=['locked_counter_in'],
                             output_keys=['locked_counter_out'])
        self.rate = rospy.Rate(200)  # Loop at 200 Hz

    def execute(self, userdata):

        time.sleep(random.randint(1,4))
        
        global homeX
        global homeY
        navigation(homeX,homeY) # Resquest to the server to navigate to the home
        self.rate.sleep()
        return 'goToNormal'

## Define state PLAY
class Play(smach.State):
    def __init__(self):
        smach.State.__init__(self, 
                             outcomes=['goToNormal','goToPlay'],
                             input_keys=['locked_counter_in'],
                             output_keys=['locked_counter_out'])
        
        self.rate = rospy.Rate(200)  # Loop at 200 Hz

    def execute(self, userdata):
        
        global X
        global Y 

        navigation(X,Y)
        navigation(userX,userY)

        time.sleep(3)

        return 'goToNormal'       


        
def main():
    rospy.init_node('cmd_manager')

    rospy.Subscriber("position", Pose2D, callbackPos) # subsriber get_position 
    rospy.Subscriber("cmd_string", String, callbackSta)

    # Create a SMACH state machine
    sm = smach.StateMachine(outcomes=['container_interface'])
    sm.userdata.sm_counter = 0

    # Open the container
    with sm:
        # Add states to the container
        smach.StateMachine.add('NORMAL', Normal(), 
                               transitions={'goToSleep':'SLEEP', 
                                            'goToPlay':'PLAY',
                                            'goToNormal':'NORMAL'},
                               remapping={'locked_counter_in':'sm_counter', 
                                          'locked_counter_out':'sm_counter'})
        smach.StateMachine.add('SLEEP', Sleep(), 
                               transitions={'goToSleep':'SLEEP', 
                                            'goToNormal':'NORMAL'},
                               remapping={'unlocked_counter_in':'sm_counter',
                                          'unlocked_counter_out':'sm_counter'})
        smach.StateMachine.add('PLAY', Play(), 
                               transitions={'goToNormal':'NORMAL',
                                            'goToPlay':'PLAY'},
                               remapping={'unlocked_counter_in':'sm_counter',
                                          'unlocked_counter_out':'sm_counter'})


    # Create and start the introspection server for visualization
    sis = smach_ros.IntrospectionServer('server_name', sm, '/SM_ROOT')
    sis.start()

    # Execute the state machine
    outcome = sm.execute()

    # Wait for ctrl-c to stop the application
    rospy.spin()
    sis.stop()


if __name__ == '__main__':
    main()
