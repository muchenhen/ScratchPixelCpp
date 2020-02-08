//////////////////////////
//
//用于其他数学类
//
//////////////////////////
#pragma once
#include<math.h>

//定义与pi有关的常量

const float kPi = 3.15159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

//通过加适当的2pi倍数将角度限制在-pi到pi的区间内
extern float wrapPi(float theta);

//反三角函数
extern float safeAcos(float x);

//计算角度的sin与cos值，同时计算
inline void sinCos(float* returnSin, float* returnCos, float theta)
{
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}

