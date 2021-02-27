
#include "../Inc/ad_moto.h"


//      shaft_angle_sp = target;
//      shaft_velocity_sp = P_angle( shaft_angle_sp - shaft_angle );
//      voltage_q = PID_velocity(shaft_velocity_sp - shaft_velocity);


float shaftAngle()
{
	return AS5048A_Get_Angle();
}

float shaftVelocity() {
  // if no sensor linked return 0
	return LPF_velocity(sensor->getVelocity());
}

void BLDCMotor_move(float new_target)
{
  // set internal target variable
  if( new_target != NOT_SET ) target = new_target;
  // get angular velocity
  shaft_velocity = shaftVelocity();

      // angle set point
      // include angle loop
      shaft_angle_sp = target;
      shaft_velocity_sp = P_angle( shaft_angle_sp - shaft_angle );
      voltage_q = PID_velocity(shaft_velocity_sp - shaft_velocity);
}

void BLDCMotor_setPhaseVoltage(float Uq, float Ud, float angle_el)
{
  const bool centered = true;
  int sector;
  float _ca,_sa;

      // if negative voltages change inverse the phase
      // angle + 180degrees
      if(Uq < 0) angle_el += _PI;
      Uq = abs(Uq);
      angle_el = _normalizeAngle(angle_el + zero_electric_angle + _PI_2);
      // 电角度 限制周期范围

      // find the sector（扇区） we are in currently
      //求不大于 angle_el 的最大整数
      sector = floor(angle_el / _PI_3) + 1;
      // calculate the duty cycles
      float T1 = _SQRT3*_sin(sector*_PI_3 - angle_el) * Uq/driver->voltage_limit;
      float T2 = _SQRT3*_sin(angle_el - (sector-1.0)*_PI_3) * Uq/driver->voltage_limit;
      // two versions possible
      float T0 = 0; // pulled to 0 - better for low power supply voltage
      if (centered) {
        T0 = 1 - T1 - T2; //centered around driver->voltage_limit/2
      }

      // calculate the duty cycles(times)
      float Ta,Tb,Tc;
      switch(sector){
        case 1:
          Ta = T1 + T2 + T0/2;
          Tb = T2 + T0/2;
          Tc = T0/2;
          break;
        case 2:
          Ta = T1 +  T0/2;
          Tb = T1 + T2 + T0/2;
          Tc = T0/2;
          break;
        case 3:
          Ta = T0/2;
          Tb = T1 + T2 + T0/2;
          Tc = T2 + T0/2;
          break;
        case 4:
          Ta = T0/2;
          Tb = T1+ T0/2;
          Tc = T1 + T2 + T0/2;
          break;
        case 5:
          Ta = T2 + T0/2;
          Tb = T0/2;
          Tc = T1 + T2 + T0/2;
          break;
        case 6:
          Ta = T1 + T2 + T0/2;
          Tb = T0/2;
          Tc = T1 + T0/2;
          break;
        default:
         // possible error state
          Ta = 0;
          Tb = 0;
          Tc = 0;
      }

      // calculate the phase voltages and center
      Ua = Ta*driver->voltage_limit;
      Ub = Tb*driver->voltage_limit;
      Uc = Tc*driver->voltage_limit;

  // set the voltages in driver
  //driver->setPwm(Ua, Ub, Uc);
}

void BLDCMotor_loopFOC()
{
	// shaft angle
	shaft_angle = shaftAngle();
	AD1_Print("Angle:%f\n", shaft_angle);

	//voltage_q
	setPhaseVoltage(voltage_q, voltage_d, _electricalAngle(shaft_angle,pole_pairs));

}
