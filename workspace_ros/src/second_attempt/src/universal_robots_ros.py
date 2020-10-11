#!/usr/bin/env python

import rospy
from controller import Robot
from joint_state_publisher import JointStatePublisher
from trajectory_follower import TrajectoryFollower
from rosgraph_msgs.msg import Clock

rospy.init_node('ur_driver', disable_signals=True)

jointPrefix = rospy.get_param('prefix', '')
if jointPrefix:
    print('Setting prefix to %s' % jointPrefix)

robot = Robot(bogdickur5e)
jointStatePublisher = JointStatePublisher(robot, jointPrefix)
trajectoryFollower = TrajectoryFollower(robot, jointStatePublisher, jointPrefix)
trajectoryFollower.start()

# we want to use simulation time for ROS
clockPublisher = rospy.Publisher('clock', Clock, queue_size=1)
if not rospy.get_param('use_sim_time', False):
    rospy.logwarn('use_sim_time is not set!')

timestep = int(robot.getBasicTimeStep())

while robot.step(timestep) != -1 and not rospy.is_shutdown():
    jointStatePublisher.publish()
    trajectoryFollower.update()
    # pulish simulation clock
    msg = Clock()
    time = robot.getTime()
    msg.clock.secs = int(time)
    # round prevents precision issues that can cause problems with ROS timers
    msg.clock.nsecs = round(1000 * (time - msg.clock.secs)) * 1.0e+6
    clockPublisher.publish(msg)
