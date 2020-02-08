////////////////////////////////////////////////////////////
//
//Vectoe3��
//
////////////////////////////////////////////////////////////
#include <math.h>



class Vector3
{
public:
	flaot x, y, z;

	//���캯��
	//Ĭ�Ϲ��캯��
	Vector3();
	//���ƹ��캯��
	Vector3(const Vector3 &a):x(a.x),y(a.y),z(a.z){}
	//�������Ĺ��캯����������ֵ��ɳ�ʼ��
	Vector3(float nx,float ny,float nz):x(nx),y(ny),z(nz){}

	//���ظ�ֵ��������������ã�ʵ����ֵ
	Vector3& operator = (const Vector3& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	//����==�����
	bool operator == (const Vector3& a) const
	{
		return x == a.x && y == a.y && z == a.z;
	}
	//����!=�����
	bool operator != (const Vector3& a) const
	{
		return x != a.x || y != a.y || z != a.z;
	}

	//��Ϊ0����
	void zero() { x = y = z = 0; }

	//����-�����,����ȡ��
	Vector3 operator-() const { return Vector3(-x, -y, -z); }

	//���ض�Ԫ + - �����
	Vector3 operator + (const Vector3& a) const
	{
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	Vector3 operator - (const Vector3& a) const
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	//������ĳ˳���
	Vector3 operator *(float a) const
	{
		return Vector3(x * a, y * a, z * a);
	}
	Vector3 operator /(float a) const
	{
		float oneOverA = 1.0f / a;
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}

	//�����Է������
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

	//������׼��
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

	//������ˣ����س˷������
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


//�ǳ�Ա����
///////

//��������ģ

inline float vectorMag(const Vector3& a)
{
	return sqrt(a.x * a.x, a.y * a.y, a.z * a.z);
}

//�����������Ĳ��
inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
		);
}

//ʵ�ֱ������
inline Vector3 operator *(float k, const Vector3& v)
{
	return Vector3(k * v.x, k * v.y, k * v.z);
}

//���������ľ���
inline float distance(const Vector3& a, const Vector3& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}


//////////
//
//ȫ�ֱ���
//
//////////

extern const Vector3 kZreoVectoor;