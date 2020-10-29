#!/usr/bin/env python
from __future__ import print_function

import rospy
import sys
from std_msgs.msg import String
from geometry_msgs.msg import Pose2D
from assignment_1.srv import *

def navigation(x,y):
    rospy.wait_for_service('navigation')
    try:
        go_to = rospy.ServiceProxy('navigation',GoTo)
        check = go_to(x,y)
        return check.o
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def callbackState(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

def callbackPos(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.x, data.y)

def cmd_manager():

    rospy.init_node('cmd_manager', anonymous=True)
    
    rospy.Subscriber("string_cmd", String, callbackState)

    rospy.Subscriber("Position", Pose2D, callbackPos)

    rate = rospy.Rate(5)

    x = 3
    y = 6
    
    loop = 1
    while loop == 1:

        navigation(x,y)
        rate.sleep()

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()
    
if __name__ == "__main__":
    cmd_manager()	
    
