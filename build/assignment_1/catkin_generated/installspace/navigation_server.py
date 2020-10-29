#!/usr/bin/env python2

from __future__ import print_function

from assignment_1.srv import state,AddTwoIntsResponse
import rospy

def handle_add_two_ints(req):
    print("Returning [%s + %s = %s]"%(req.a, req.b, (req.a + req.b)))
    return AddTwoIntsResponse(req.a + req.b)

def navigation_server():
    rospy.init_node('navigation_server')
    s = rospy.Service('navigation', state, handle_add_two_ints)
    print("Ready to add two ints.")
    rospy.spin()

if __name__ == "__main__":
    navigation_server()
