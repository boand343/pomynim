#!/usr/bin/env python
import rospy
import os
from std_msgs.msg import String
from webots_ros import *
from webots_ros.srv import *
from rosgraph_msgs.msg import Clock


def hi():
	rospy.wait_for_service('/bogdickur5e/robot/set_mode')
	kek = rospy.ServiceProxy('/bogdickur5e/robot/set_mode', robot_set_mode)
	kek("bogdickur5e", 0)


def gsCallback(data):
	print(data)

def callback(data):
	print(data)

rospy.init_node('bogdickur5e_client', anonymous=True)
rate = rospy.Rate(10)

step = int(16)
pos = float('+inf')
speed = float(3.1)

rospy.wait_for_service('/bogdickur5e/shoulder_lift_joint_sensor/enable')
heh = rospy.ServiceProxy('/bogdickur5e/shoulder_lift_joint_sensor/enable', set_int)

rospy.wait_for_service('/bogdickur5e/robot/time_step')
fef = rospy.ServiceProxy('/bogdickur5e/robot/time_step', set_int)

rospy.wait_for_service('/bogdickur5e/shoulder_lift_joint/set_position')
kek = rospy.ServiceProxy('/bogdickur5e/shoulder_lift_joint/set_position', set_float)

rospy.wait_for_service('/bogdickur5e/shoulder_lift_joint/set_velocity')
lol = rospy.ServiceProxy('/bogdickur5e/shoulder_lift_joint/set_velocity', set_float)

rospy.wait_for_service('/bogdickur5e/shoulder_lift_joint/set_acceleration')
acc = rospy.ServiceProxy('/bogdickur5e/shoulder_lift_joint/set_acceleration', set_float)




rospy.Subscriber("model_name", String, callback)

rospy.Subscriber('clock', Clock, callback)

#if not rospy.get_param('use_sim_time', False):
 #   rospy.logwarn('use_sim_time is not set!')


#rospy.Subscriber("/bogdickur5e/shoulder_lift_joint_sensor/value", 1, gsCallback)
acc(pos)
fef(step)
kek(pos)
lol(speed)
while not rospy.is_shutdown():
	rospy.loginfo("Hello")