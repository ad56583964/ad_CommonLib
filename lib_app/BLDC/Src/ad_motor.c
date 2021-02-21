/*
 * ad_motor.c
 *
 *  Created on: Feb 20, 2021
 *      Author: ad565
 */


void BLDCMotor_move(float new_target) {
  // set internal target variable
  if( new_target != NOT_SET ) target = new_target;
  // get angular velocity
  shaft_velocity = shaftVelocity();
  // choose control loop
  switch (controller) {
    case voltage:
      voltage_q =  target;
      break;
    case angle:
      // angle set point
      // include angle loop
      shaft_angle_sp = target;
      shaft_velocity_sp = P_angle( shaft_angle_sp - shaft_angle );
      voltage_q = PID_velocity(shaft_velocity_sp - shaft_velocity);
      break;
    case velocity:
      // velocity set point
      // include velocity loop
      shaft_velocity_sp = target;
      voltage_q = PID_velocity(shaft_velocity_sp - shaft_velocity);
      break;
    case velocity_openloop:
      // velocity control in open loop
      // loopFOC should not be called
      shaft_velocity_sp = target;
      velocityOpenloop(shaft_velocity_sp);
      break;
    case angle_openloop:
      // angle control in open loop
      // loopFOC should not be called
      shaft_angle_sp = target;
      angleOpenloop(shaft_angle_sp);
      break;
  }
}

