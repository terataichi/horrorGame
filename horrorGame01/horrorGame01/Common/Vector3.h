#pragma once
// ﾃﾝﾌﾟﾚｰﾄ化しま
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
		return Vector3Template<int>{ static_cast<int>(x_), static_cast<int>(y_) };
	};
	operator Vector3Template<float>()
	{
		return Vector3Template<float>{ static_cast<float>(x_), static_cast<float>(y_) };
	};

	Vector3Template operator + ()const;
	Vector3Template operator - ()const;

	// 代入演算子
	Vector3Template& operator = (const Vector3Template& vec);
	// 比較演算子
	bool operator == (const Vector3Template& vec)const;
	bool operator != (const Vector3Template& vec)const;
	bool operator > (const Vector3Template& vec)const;
	bool operator >= (const Vector3Template& vec)const;
	bool operator < (const Vector3Template& vec)const;
	bool operator <= (const Vector3Template& vec)const;

	// 単項演算子
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

// 単項演算子　Vector2 ・ int
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

// 単項演算子　Vector2 ・ Vector2
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

// 内積
template<class T>
float Dot(const Vector3Template<T>& u, const Vector3Template<T>& v);

// 外積
template<class T>
Vector3Template<T> Cross(const Vector3Template<T>& u, const Vector3Template<T>& v);

// 法線ベクトル
template<class T>
Vector3Template<T> Normal(const Vector3Template<T>& u);

// 絶対値
template<class T>
Vector3Template<T> abs(const Vector3Template<T>& u);

using Vector3 = Vector3Template<int>;
using Vector3d = Vector3Template<double>;
using Vector3f = Vector3Template<float>;

using Potision3 = Vector3;
using Potision3f = Vector3f;

using Size = Vector3;
using Sizef = Vector3f;

#include "details/Vector3.h"
