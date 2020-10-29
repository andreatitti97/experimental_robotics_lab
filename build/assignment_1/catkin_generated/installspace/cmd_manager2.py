#!/usr/bin/env python2
from __future__ import print_function

import sys
import rospy
from assignment_1.srv import state

def cmd_manager2 (x, y):
    rospy.wait_for_service('navigation')
    try:
        state1 = rospy.ServiceProxy('navigation', state)
        resp1 = state1(x, y)
        return resp1.sum
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def usage():
    return "%s [x y]"%sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print(usage())
        sys.exit(1)
    print("Requesting %s+%s"%(x, y))
    print("%s + %s = %s"%(x, y, cmd_manager2 (x, y)))
