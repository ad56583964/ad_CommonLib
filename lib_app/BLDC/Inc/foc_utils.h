/*
 * foc_utils.h
 *
 *  Created on: 2021年2月24日
 *      Author: AD_PRO13
 */

#ifndef LIB_APP_BLDC_INC_FOC_UTILS_H_
#define LIB_APP_BLDC_INC_FOC_UTILS_H_

#define _2_SQRT3 1.15470053838
#define _SQRT3 1.73205080757    //3的算术平方根
#define _1_SQRT3 0.57735026919
#define _SQRT3_2 0.86602540378
#define _SQRT2 1.41421356237
#define _120_D2R 2.09439510239
#define _PI 3.14159265359
#define _PI_2 1.57079632679
#define _PI_3 1.0471975512
#define _2PI 6.28318530718
#define _3PI_2 4.71238898038

//约束 数据符号为正
// sign function
#define _sign(a) ( ( (a) < 0 )  ?  -1   : ( (a) > 0 ) )

#define _round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

#define _constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

// normalizing radian angle to [0,2PI]
float _normalizeAngle(float angle);

float _electricalAngle(float shaft_angle, int pole_pairs);

float _sin(float a);

float _cos(float a);





#endif /* LIB_APP_BLDC_INC_FOC_UTILS_H_ */
