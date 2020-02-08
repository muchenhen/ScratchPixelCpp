////////////////
//
//以欧拉角形式保存方位
//使用heading-pitch-bank约定
//
////////////////
#pragma once

class Quaternion;
class Matrix4x3;
class RotationMatrix;

class EulerAngles {
public:
	//直接用弧度保存三个角度
	float heading;
	float pitch;
	float bank;

	//默认构造
	EulerAngles(){}

	//接受三个参数
	EulerAngles(float h, float p, float b) : heading(h),pitch(p),bank(b){}

	//置零
	void identity() { pitch = bank = heading = 0.0f; }

	//变换为限制欧拉角
	void canonize();

	//从四元数转换到欧拉角
	//物体-惯性
	void fromObjectToInertialQuaternion(const Quaternion& q);
	//惯性-物体
	void fromInertialToObjectQuaternion(const Quaternion& q);

	//从矩阵转换到欧拉角
	//物体-世界矩阵
	void fromObjectToWorldMatrix(const Matrix4x3& m);
	//世界-物体矩阵
	void fromWorldToObjectMatrix(const Matrix4x3& m);

	//从旋转矩阵到欧拉角
	void fromRotationMatrix(const RotationMatrix& m);

	//全局单位欧拉角
	extern const EulerAngles kEulerAnglesIdentity;
};