#include <math.h>

#include "EulerAngles.h"
#include "Quaternion.h"
#include "MathUtil.h"
#include "Matrix4x3.h"
#include "RotationMatrix.h"

///////////////////////////////////////////
//
//ȫ������
//
///////////////////////////////////////////

//ȫ�ֵ�λŷ���ǳ���
const EulerAngles kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);

void EulerAngles::canonize()
{
	//���Ƚ�pitch�任��-pi��pi֮��
	pitch = wrapPi(pitch);
	//��pitch�任��-pi/2��pi/2֮��
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

	//���������������
	if (fabs(pitch) > kPiOver2 - 1e-4)
	{
		//��������½����е�bank��ת��heading����Ϊ�Ƶ���ͬһ����
		heading += bank;
		bank = 0.0f;
	}
	else
	{
		//����������bankת�������Ƽ�
		bank = wrapPi(bank);
	}

	//��headingת�������Ƽ���
	heading = wrapPi(heading);
}


//������-������Ԫ����ŷ����
void EulerAngles::fromObjectToInertialQuaternion(const Quaternion& q)
{

}