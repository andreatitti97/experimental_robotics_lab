#!/usr/bin/env python

from __future__ import print_function

import roslib
import rospy
import smach
import smach_ros
import time
import random
import sys
from std_msgs.msg import String
from geometry_msgs.msg import Twist

from assignment_1.srv import *

# Initialize useful global variables
x = 3
y = 5
xhome = 10
yhome = 20
state = "NoInfo"

def decision(): #the decision for normal of sleep should be random
    return random.choice(['goToNormal','goToSleep'])
	
def callbackSta(data): #callback function for subscribe user_cmd node.
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    global state 
    state = "play"


# define state NORMAL
class Normal(smach.State):
    def __init__(self):
        # Initialization function
        smach.State.__init__(self, 
                             outcomes=['goToNormal','goToSleep','goToPlay'],
                             input_keys=['unlocked_counter_in'],
                             output_keys=['unlocked_counter_out'])
        self.rate = rospy.Rate(1)  # Loop at 200 Hz
        self.counter = 0
        
    def execute(self,userdata):
        
        global x
        global y
        global state
        
        self.counter = 0
        while not rospy.is_shutdown():  
            rospy.loginfo(rospy.get_caller_id() + 'Executing state NORMAL ')

            time.sleep(2)
            if self.counter == 3:
                return 'goToSleep'
            self.rate.sleep()

            rospy.loginfo(rospy.get_caller_id() + 'i m going to x: %d y: %d',x, y)
            x = x + 1
            y = y + 1
            if state == "play":
                state = 'noInput'
                return 'goToPlay'

            self.counter += 1
            
        
        return decision()
    

# Define the state SLEEP
class Sleep(smach.State):
    def __init__(self):
        smach.State.__init__(self, 
                             outcomes=['goToNormal','goToSleep'],
                             input_keys=['locked_counter_in'],
                             output_keys=['locked_counter_out'])
        self.sensor_input = 0
        self.rate = rospy.Rate(200)  # Loop at 200 Hz

    def execute(self, userdata):
        
        time.sleep(5)
       
        global xhome
        global yhome
        rospy.loginfo(rospy.get_caller_id() + 'Executing state SLEEP ')
        rospy.loginfo(rospy.get_caller_id() + 'i m going to home x: %d y: %d',xhome,yhome)
        self.rate.sleep()
        return 'goToNormal'

# define state Play
class Play(smach.State):
    def __init__(self):
        smach.State.__init__(self, 
                             outcomes=['goToNormal','goToPlay'],
                             input_keys=['locked_counter_in'],
                             output_keys=['locked_counter_out'])
        
        self.sensor_input = 0
        self.rate = rospy.Rate(200)  # Loop at 200 Hz

    def execute(self, userdata):
        
        time.sleep(3)
        

        rospy.loginfo(rospy.get_caller_id() + 'Executing state PLAY ')
        

        return 'goToNormal'


        
def main():
    rospy.init_node('cmd_manager')

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
