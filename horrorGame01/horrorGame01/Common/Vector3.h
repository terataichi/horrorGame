#pragma once
// ΓέΜίΪ°Δ»΅ά
template<class T> class Vector3Template
{
public:
	Vector3Template();
	Vector3Template(T x, T y,T z);
	~Vector3Template();
	T x_;
	T y_;
	T z_;

	operator Vector3Template<int>()
	{
		return Vector3Template<int>{ static_cast<int>(x_), static_cast<int>(y_), static_cast<int>(z_) };
	};
	operator Vector3Template<float>()
	{
		return Vector3Template<float>{ static_cast<float>(x_), static_cast<float>(y_), static_cast<float>(z_) };
	};

	Vector3Template operator + ()const;
	Vector3Template operator - ()const;

	// γόZq
	Vector3Template& operator = (const Vector3Template& vec);
	// δrZq
	bool operator == (const Vector3Template& vec)const;
	bool operator != (const Vector3Template& vec)const;
	bool operator > (const Vector3Template& vec)const;
	bool operator >= (const Vector3Template& vec)const;
	bool operator < (const Vector3Template& vec)const;
	bool operator <= (const Vector3Template& vec)const;

	// PZq
	Vector3Template& operator += (const Vector3Template& vec);
	Vector3Template& operator -= (const Vector3Template& vec);
	Vector3Template& operator *= (const Vector3Template& vec);
	Vector3Template& operator /= (const Vector3Template& vec);
	Vector3Template& operator %= (const Vector3Template& vec);

	Vector3Template& operator *= (T k);
	Vector3Template& operator /= (T k);

	float Magnitude()const;
	static Vector3Template ZERO;
	Vector3Template<float> Normalized(void);
};

// PZq@Vector2 E int
template<class T>
Vector3Template<T> operator +(const Vector3Template<T>& u, const T& k);
template<class T>
Vector3Template<T> operator -(const Vector3Template<T>& u, const T& k);
template<class T>
Vector3Template<T> operator *(const Vector3Template<T>& u, const T& k);
template<class T>
Vector3Template<T> operator /(const Vector3Template<T>& u, const T& k);
template<class T>
Vector3Template<T> operator %(const Vector3Template<T>& u, const T& k);

// PZq@Vector2 E Vector2
template<class T>
Vector3Template<T> operator +(const Vector3Template<T>& u, const Vector3Template<T>& v);
template<class T>
Vector3Template<T> operator -(const Vector3Template<T>& u, const Vector3Template<T>& v);
template<class T>
Vector3Template<T> operator *(const Vector3Template<T>& u, const Vector3Template<T>& v);
template<class T>
Vector3Template<T> operator /(const Vector3Template<T>& u, const Vector3Template<T>& v);
template<class T>
Vector3Template<T> operator %(const Vector3Template<T>& u, const Vector3Template<T>& v);

// int * Vector2
template<class T>
Vector3Template<T> operator *(const T& k, const Vector3Template<T>& u);

// ΰΟ
template<class T>
float Dot(const Vector3Template<T>& u, const Vector3Template<T>& v);

// OΟ
template<class T>
Vector3Template<T> Cross(const Vector3Template<T>& u, const Vector3Template<T>& v);

// @όxNg
template<class T>
Vector3Template<T> Normal(const Vector3Template<T>& u);

// βΞl
template<class T>
Vector3Template<T> abs(const Vector3Template<T>& u);

using Vector3 = Vector3Template<int>;
using Vector3d = Vector3Template<double>;
using Vector3f = Vector3Template<float>;

using Potision3 = Vector3;
using Potision3f = Vector3f;

using Size3 = Vector3;
using Size3f = Vector3f;

#include "details/Vector3.h"
