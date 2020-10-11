#include <webots/distance_sensor.h>
#include <webots/motor.h>
#include <webots/position_sensor.h>
#include <webots/robot.h>

#include <stdio.h>

#define TIME_STEP 32

enum State { GRASPING, ROTATING, RELEASING};

int main(int argc, char **argv) {
  wb_robot_init();
  int counter = 0, i = 0, count = 0;
  int state = GRASPING;
  const double target_positions[] = {-1.88, -2.14, -2.38, -1.51};
  double speed = 1.0;

  if (argc == 2)
    sscanf(argv[1], "%lf", &speed);

  WbDeviceTag ur_motors[4];
  ur_motors[0] = wb_robot_get_device("shoulder_lift_joint");
  ur_motors[1] = wb_robot_get_device("elbow_joint");
  ur_motors[2] = wb_robot_get_device("wrist_1_joint");
  ur_motors[3] = wb_robot_get_device("wrist_2_joint");
  for (i = 0; i < 4; ++i)
    wb_motor_set_velocity(ur_motors[i], speed);

  WbDeviceTag distance_sensor = wb_robot_get_device("distance sensor");
  wb_distance_sensor_enable(distance_sensor, TIME_STEP);

  WbDeviceTag position_sensor = wb_robot_get_device("wrist_1_joint_sensor");
  wb_position_sensor_enable(position_sensor, TIME_STEP);

  while (wb_robot_step(TIME_STEP) != -1) {
    if (counter <= 0) {
      switch (state) {
        case GRASPING:
          count++;
          printf("target_count%lf\n", wb_motor_get_target_position(ur_motors[0]));
          printf("i skilko%d\n", count);
          state = GRASPING;
          for (i = 0; i <= 3; i++)
            wb_motor_set_position(ur_motors[i], target_positions[i]);
          state = ROTATING;
          break;
        case ROTATING:
          printf("wb_position_sensor_get_value(position_sensor):%lf\n", wb_position_sensor_get_value(position_sensor));
          if (wb_position_sensor_get_value(position_sensor) < -2.3) {
            printf("Releasing can\n");
            state = RELEASING;
          }
          break;
        case RELEASING:
          for (i = 0; i < 4; i++){
              wb_motor_set_position(ur_motors[i], 0.0);
             }
          printf("Rotating arm back\n");
          state = GRASPING;
          break;
      }
    }
    counter--;
  };

  wb_robot_cleanup();
  return 0;
}