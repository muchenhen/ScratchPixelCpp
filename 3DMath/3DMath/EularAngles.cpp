#include <math.h>

#include "EulerAngles.h"
#include "Quaternion.h"
#include "MathUtil.h"
#include "Matrix4x3.h"
#include "RotationMatrix.h"

///////////////////////////////////////////
//
//全局数据
//
///////////////////////////////////////////

//全局单位欧拉角常量
const EulerAngles kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);

void EulerAngles::canonize()
{
	//首先将pitch变换到-pi到pi之间
	pitch = wrapPi(pitch);
	//将pitch变换到-pi/2到pi/2之间
	if (pitch < -kPiOver2)
	{
		pitch = -kPi - pitch;
		heading += kPi;
		bank += kPi;
	}
	else if (pitch > kPiOver2)
	{
		pitch = kPi - pitch;
		heading += kPi;
		bank += kPi;
	}

	//检查万向节死锁情况
	if (fabs(pitch) > kPiOver2 - 1e-4)
	{
		//这种情况下将所有的bank旋转给heading，因为绕的是同一个轴
		heading += bank;
		bank = 0.0f;
	}
	else
	{
		//非万向锁将bank转换到限制集
		bank = wrapPi(bank);
	}

	//将heading转换到限制集中
	heading = wrapPi(heading);
}


//从物体-惯性四元数到欧拉角
void EulerAngles::fromObjectToInertialQuaternion(const Quaternion& q)
{

}