"""UR5_e_by_Bogdick controller."""

# You may need to import some classes of the controller module. Ex:
from controller import Robot, Motor, DistanceSensor, PositionSensor, GPS, Camera


# create the Robot instance.
robot = Robot()

# get the time step of the current world.
timestep = int(robot.getBasicTimeStep())

# You should insert a getDevice-like function in order to get the
# instance of a device of the robot. Something like:
#  motor = robot.getMotor('motorname')
#  ds = robot.getDistanceSensor('dsname')
#  ds.enable(timestep)
speed = 0.05
target_positions = [-1.88, -2.14, -2.38, -1.51]

ur_motors = [] 
ur_motors.append(robot.getMotor("shoulder_lift_joint"))
ur_motors.append(robot.getMotor("elbow_joint"))
ur_motors.append(robot.getMotor("wrist_1_joint"))
ur_motors.append(robot.getMotor("wrist_2_joint"))
ur_motors.append(robot.getMotor("shoulder_pan_joint"))

distance_sensor = robot.getDistanceSensor("distance sensor")
distance_sensor.enable(timestep)

position_sensor = robot.getPositionSensor("wrist_3_joint_sensor")
position_sensor.enable(timestep)

gps_sensor = robot.getGPS("gps")
gps_sensor.enable(timestep)

camera = robot.getCamera("camera")
camera.enable(timestep)

print(robot.getName())
for i in range(4):
    ur_motors[i].setVelocity(speed)
# Main loop:
# - perform simulation steps until Webots is stopping the controller
while robot.step(timestep) != -1:
    
    #ur_motors[1].setPosition(target_positions[1])
    for i in range(3):
        ur_motors[i].setPosition(target_positions[i])
    #print(distance_sensor.getValue())
    #print(position_sensor.getValue())
    #print(gps_sensor.getValues())
    #for i in range(4):
     #   ur_motors[i].setPosition(target_positions[i])
    # Read the sensors:
    # Enter here functions to read sensor data, like:
    #  val = ds.getValue()
    
    # Process sensor data here.

    # Enter here functions to send actuator commands, like:
    #  motor.setPosition(10.0)
    pass

# Enter here exit cleanup code.
