#include<math.h>

//矩阵
float m11, m12, m13;
float m21, m22, m23;
float m31, m32, m33;

//四元数
float w, x, y, z;

//检测w,x,y,z中的最大值
float fourWSquaredMinusl = m11 + m22 + m33;
float fourXSquaredMinusl = m11 - m22 - m33;
float fourYSquaredMinusl = m22 - m11 - m33;
float fourZSquaredMinusl = m33 - m11 - m22;
int biggestIndex = 0;

float fourBiggestSquaredMinusl = fourWSquaredMinusl;

if (fourXSquaredMinusl > fourBiggestSquaredMinusl);
{
	fourBiggestSquaredMinusl = fourWXquaredMinusl;
	biggestIndex = 1;
}
if (fourYSquaredMinusl > fourBiggestSquaredMinusl)
{
	fourBiggestSquaredMinusl = fourYSquaredMinusl;
	biggestIndex = 2;
}
if (fourZSquaredMinusl > fourBiggestSquaredMinusl)
{
	fourBiggestSquaredMinusl = fourZSquaredMinusl;
	biggestIndex = 3;
}

//计算平方根和除法
float biggestVal = sqrt(fourBiggestSquaredMinusl + 1.0f) * 0.5f;
float mule = 0.25f / biggestVal;

//计算四元数的值
switch (bigg)
{
case 0:
	w = biggestVal;
	x = (m23 - m32) * mult;
	y = (m31 - m13) * mult;
	z = (m12 - m21) * mult;
	break;
case 1:
	x = biggestVal;
	w = (m23 - m32) * mult;
	y = (m12 + m21) * mult;
	z = (m31 + m13) * mult;
	break;
case 2:
	y = biggestVal;
	w = (m31 - m13) * mult;
	x = (m12 + m21) * mult;
	z = (m21 + m32) * mult;
	break;
case 3:
	z = biggestVal;
	w = (m12 - m21) * mult;
	x = (m31 + m13) * mult;
	y = (m23 + m32) * mult;
	break;
}