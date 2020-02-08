////////////////
//
//��ŷ������ʽ���淽λ
//ʹ��heading-pitch-bankԼ��
//
////////////////
#pragma once

class Quaternion;
class Matrix4x3;
class RotationMatrix;

class EulerAngles {
public:
	//ֱ���û��ȱ��������Ƕ�
	float heading;
	float pitch;
	float bank;

	//Ĭ�Ϲ���
	EulerAngles(){}

	//������������
	EulerAngles(float h, float p, float b) : heading(h),pitch(p),bank(b){}

	//����
	void identity() { pitch = bank = heading = 0.0f; }

	//�任Ϊ����ŷ����
	void canonize();

	//����Ԫ��ת����ŷ����
	//����-����
	void fromObjectToInertialQuaternion(const Quaternion& q);
	//����-����
	void fromInertialToObjectQuaternion(const Quaternion& q);

	//�Ӿ���ת����ŷ����
	//����-�������
	void fromObjectToWorldMatrix(const Matrix4x3& m);
	//����-�������
	void fromWorldToObjectMatrix(const Matrix4x3& m);

	//����ת����ŷ����
	void fromRotationMatrix(const RotationMatrix& m);

	//ȫ�ֵ�λŷ����
	extern const EulerAngles kEulerAnglesIdentity;
};