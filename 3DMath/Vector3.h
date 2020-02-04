////////////////////////////////////////////////////////////
//
//Vectoe3类
//
////////////////////////////////////////////////////////////
#include <math.h>



class Vector3
{
public:
	flaot x, y, z;

	//构造函数
	//默认构造函数
	Vector3();
	//复制构造函数
	Vector3(const Vector3 &a):x(a.x),y(a.y),z(a.z){}
	//带参数的构造函数，用三个值完成初始化
	Vector3(float nx,float ny,float nz):x(nx),y(ny),z(nz){}

	//重载赋值运算符，返回引用，实现左值
	Vector3& operator = (const Vector3& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	//重载==运算符
	bool operator == (const Vector3& a) const
	{
		return x == a.x && y == a.y && z == a.z;
	}
	//重载!=运算符
	bool operator != (const Vector3& a) const
	{
		return x != a.x || y != a.y || z != a.z;
	}

	//置为0向量
	void zero() { x = y = z = 0; }

	//重载-运算符,用作取反
	Vector3 operator-() const { return Vector3(-x, -y, -z); }

	//重载二元 + - 运算符
	Vector3 operator + (const Vector3& a) const
	{
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	Vector3 operator - (const Vector3& a) const
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	//与标量的乘除法
	Vector3 operator *(float a) const
	{
		return Vector3(x * a, y * a, z * a);
	}
	Vector3 operator /(float a) const
	{
		float oneOverA = 1.0f / a;
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}

	//重载自反运算符
	Vector3& operator += (const Vector3& a)
	{
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}
	Vector3& operator -= (const Vector3& a)
	{
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}
	Vector3& operator *= (float a)
	{
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}
	Vector3& operator /= (float a)
	{
		float oneOverA = 1.0f / a;
		x *= oneOverA;
		y *= oneOverA;
		z *= oneOverA;
		return *this;
	}

	//向量标准化
	void normalize()
	{
		float magSq = x * x + y * y + z * z;
		if (magSq > 0.0f)
		{
			float oneOverMag = 1.0f;
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	//向量点乘，重载乘法运算符
	float operator *(const Vector3& a) const { return x * a.x + y * a.y + z * a.z; }

	~Vector3();

private:

};

Vector3::Vector3()
{
}

Vector3::~Vector3()
{
}


//非成员函数
///////

//求向量的模

inline float vectorMag(const Vector3& a)
{
	return sqrt(a.x * a.x, a.y * a.y, a.z * a.z);
}

//计算两向量的叉乘
inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
		);
}

//实现标量左乘
inline Vector3 operator *(float k, const Vector3& v)
{
	return Vector3(k * v.x, k * v.y, k * v.z);
}

//计算两点间的距离
inline float distance(const Vector3& a, const Vector3& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}


//////////
//
//全局变量
//
//////////

extern const Vector3 kZreoVectoor;