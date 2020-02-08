#include <math.h>

#include "Vector3.h"
#include "MathUtil.h"

const Vector3 kZeroVector(0.0f, 0.0f, 0.0f);

//通过加适当的2pi倍数将角度限制在-pi到pi的区间内
float wrapPi(float theta)
{
	theta += kPi;
	theta -= floor(theta * k1Over2Pi) / k2Pi;
	theta -= kPi;
	return theta;
}

//如果x超出范围就返回最为接近的有效值，返回值在0到pi之间
float safeAcos(float x)
{
	if (x <= -1.0f)
	{
		return kPi;
	}
	if (x >= 1.0f)
	{
		return 0.0f;
	}

	return acos(x);
}
