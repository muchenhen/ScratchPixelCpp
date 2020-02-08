#include <math.h>

#include "Vector3.h"
#include "MathUtil.h"

const Vector3 kZeroVector(0.0f, 0.0f, 0.0f);

//ͨ�����ʵ���2pi�������Ƕ�������-pi��pi��������
float wrapPi(float theta)
{
	theta += kPi;
	theta -= floor(theta * k1Over2Pi) / k2Pi;
	theta -= kPi;
	return theta;
}

//���x������Χ�ͷ�����Ϊ�ӽ�����Чֵ������ֵ��0��pi֮��
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
