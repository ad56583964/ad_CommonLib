/*
 * ad_moto_openloop.c
 *
 *  Created on: Feb 27, 2021
 *      Author: AD_PRO13
 */

#include "../Inc/ad_moto_openloop.h"

#include "math.h"

//轴角度？？
float shaft_angle;//!< current motor angle
// motor configuration parameters

int pole_pairs;//!< Motor pole pairs number

long open_loop_timestamp;

float Ua,Ub,Uc;//!< Current phase voltages Ua,Ub and Uc set to motor
float Ualpha,Ubeta; //!< Phase voltages U alpha and U beta used for inverse Park and Clarke transform

float voltage_limit = 12;
float voltage_power_supply = 20;

float zero_electric_angle = 0;

void BLDC_setPwm(float Ua, float Ub, float Uc)
{

	  float dc_a = _constrain(Ua / voltage_power_supply, 0.0 , 1.0 );
	  float dc_b = _constrain(Ub / voltage_power_supply, 0.0 , 1.0 );
	  float dc_c = _constrain(Uc / voltage_power_supply, 0.0 , 1.0 );

      AD1_Print("ABC:%f,%f,%f\n",dc_a,dc_b,dc_c);
	AD_PWM1_SET(dc_a);
	AD_PWM2_SET(dc_b);
	AD_PWM3_SET(dc_c);
}

void SVPWM_setPhaseVoltage(float Uq, float Ud, float angle_el)
{
	int sector;
      if(Uq < 0) angle_el += _PI;
      Uq = abs(Uq);

      // angle normalisation in between 0 and 2pi
      // only necessary if using _sin and _cos - approximation functions
      angle_el = _normalizeAngle(angle_el + zero_electric_angle + _PI_2);

      // find the sector we are in currently
      sector = floor(angle_el / _PI_3) + 1;
      // calculate the duty cycles
      float T1 = _SQRT3*_sin(sector*_PI_3 - angle_el) * Uq/voltage_limit;
      float T2 = _SQRT3*_sin(angle_el - (sector-1.0)*_PI_3) * Uq/voltage_limit;
      // two versions possible
      float T0 = 0; // pulled to 0 - better for low power supply voltage

        T0 = 1 - T1 - T2; //centered around driver->voltage_limit/2


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
      Ua = Ta*voltage_limit;
      Ub = Tb*voltage_limit;
      Uc = Tc*voltage_limit;

      BLDC_setPwm(Ua,Ub,Uc);
}

//理想情况 Uq为设定 与转矩 成正比的值，Ud作为无功力为0， angle_el为希望达到的电角度（一个S->N周期）
void SPWM_setPhaseVoltage(float Uq, float Ud, float angle_el)
{
	  float _ca,_sa;

      angle_el = _normalizeAngle(angle_el + zero_electric_angle);
      _ca = _cos(angle_el);
      _sa = _sin(angle_el);
      // Inverse park transform
      Ualpha =  _ca * Ud - _sa * Uq;  // -sin(angle) * Uq;
      Ubeta =  _sa * Ud + _ca * Uq;    //  cos(angle) * Uq;

      // Clarke transform
      Ua = Ualpha + voltage_limit/2;
      Ub = -0.5 * Ualpha  + _SQRT3_2 * Ubeta + voltage_limit/2;
      Uc = -0.5 * Ualpha - _SQRT3_2 * Ubeta + voltage_limit/2;


      BLDC_setPwm(Ua,Ub,Uc);
}

void BLDCMotor_velocityOpenloop(float target_velocity)
{
  // get current timestamp
  uint32_t now_ms = AD_Get_Tick_ms();
  // calculate the sample time from last call
  float Ts = (now_ms - open_loop_timestamp) * 0.001;
  // calculate the necessary angle to achieve target velocity
   shaft_angle = _normalizeAngle(shaft_angle + target_velocity*Ts);

  // set the maximal allowed voltage (voltage_limit) with the necessary angle
   SVPWM_setPhaseVoltage(voltage_limit,  0, _electricalAngle(shaft_angle, 7));
  AD1_Print("anl:%f,",shaft_angle);
  // save timestamp for next call
  open_loop_timestamp = now_ms;
}


