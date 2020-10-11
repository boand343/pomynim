#!/usr/bin/env python

import rospy
from std_msgs.msg import Float64
from time import sleep
from controller import Robot

robot = Robot()

timeStep = int(robot.getBasicTimeStep())

robot.step(timeStep)
rospy.init_node('listener', anonymous=True)
print('Subscribing to "motor" topic')
robot.step(timeStep)
rospy.Subscriber('motor', Float64, callback)
pub = rospy.Publisher('sensor', Float64, queue_size=10)
print('Running the control loop')
