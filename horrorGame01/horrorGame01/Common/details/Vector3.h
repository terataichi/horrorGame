#pragma once
#include "../Vector3.h"
#include <cmath>
#include <cassert>

template<class T>
Vector3Template<T>::Vector3Template() :x_(0), y_(0), z_(0)
{
}

template<class T>
Vector3Template<T>::Vector3Template(T x, T y, T z) :x_(x), y_(y),z_(z)
{
}

template<class T>
Vector3Template<T>::~Vector3Template()
{
}

template<class T>
inline Vector3Template<T> Vector3Template<T>::operator+() const
{
	return *this;
}

template<class T>
inline Vector3Template<T> Vector3Template<T>::operator-() const
{
	return {-x_,-y_,-z_};
}

template<class T>
inline Vector3Template<T>& Vector3Template<T>::operator=(const Vector3Template& vec)
{
	x_ = vec.x_;
	y_ = vec.y_;
	z_ = vec.z_;
	return *this;
}

template<class T>
inline bool Vector3Template<T>::operator==(const Vector3Template& vec) const
{
	return (x_ == vec.x_ && y_ == vec.y_ && z_ == vec.z_);
}

template<class T>
inline bool Vector3Template<T>::operator!=(const Vector3Template& vec) const
{
	return !(x_ == vec.x_ && y_ == vec.y_ && z_ == vec.z_);;
}

template<class T>
inline bool Vector3Template<T>::operator>(const Vector3Template& vec) const
{
	return (x_ > vec.x_ && y_ > vec.y_ && z_ > vec.z_);
}

template<class T>
inline bool Vector3Template<T>::operator>=(const Vector3Template& vec) const
{
	return  (x_ >= vec.x_ && y_ >= vec.y_ && z_ >= vec.z_);
}

template<class T>
inline bool Vector3Template<T>::operator<(const Vector3Template& vec) const
{
	return (x_ < vec.x_ && y_ < vec.y_ && z_ < vec.z_);
}

template<class T>
inline bool Vector3Template<T>::operator<=(const Vector3Template& vec) const
{
	return (x_ <= vec.x_&& y_ <= vec.y_&& z_ <= vec.z_);
}

template<class T>
inline Vector3Template<T>& Vector3Template<T>::operator+=(const Vector3Template& vec)
{
	x_ += vec.x_;
	y_ += vec.y_;
	z_ += vec.z_;
	return *this;
}

template<class T>
inline Vector3Template<T>& Vector3Template<T>::operator-=(const Vector3Template& vec)
{
	x_ -= vec.x_;
	y_ -= vec.y_;
	z_ -= vec.z_;
	return *this;
}

template<class T>
inline Vector3Template<T>& Vector3Template<T>::operator*=(const Vector3Template& vec)
{
	x_ *= vec.x_;
	y_ *= vec.y_;
	z_ *= vec.z_;
	return *this;
}

template<class T>
inline Vector3Template<T>& Vector3Template<T>::operator/=(const Vector3Template& vec)
{
	if (vec.x_ != 0)
	{
		x_ /= vec.x_;
	}
	else
	{
		x_ = 0;
	}
	if (vec.y_ != 0)
	{
		y_ /= vec.y_;
	}
	else
	{
		y_ = 0;
	}
	if (vec.z_ != 0)
	{
		z_ /= vec.z_;
	}
	else
	{
		z_ = 0;
	}
	return *this;
}

template<class T>
inline Vector3Template<T>& Vector3Template<T>::operator%=(const Vector3Template& vec)
{
	Vector3 tmp{};
	if (vec.x_ != 0)
	{
		tmp.x_ = static_cast<int>(x_) % static_cast<int>(vec.x_);
	}
	if (vec.y_ != 0)
	{
		tmp.y_ = static_cast<int>(y_) % static_cast<int>(vec.y_);
	}
	if (vec.z_ != 0)
	{
		tmp.z_ = static_cast<int>(z_) % static_cast<int>(vec.z_);
	}
	x_ = static_cast<T>(tmp.x_);
	y_ = static_cast<T>(tmp.y_);
	z_ = static_cast<T>(tmp.z_);

	return *this;
}

template<class T>
inline Vector3Template<T>& Vector3Template<T>::operator*=(T k)
{
	x_ *= k;
	y_ *= k;
	z_ *= k;
	return *this;
}

template<class T>
inline Vector3Template<T>& Vector3Template<T>::operator/=(T k)
{
	x_ /= k;
	y_ /= k;
	z_ /= k;
	return *this;
}

template<class T>
inline float Vector3Template<T>::Magnitude() const
{
	return sqrtf(x_ * x_ + y_ * y_ + z_ + z_);
}

template<class T>
inline Vector3Template<float> Vector3Template<T>::Normalized(void)
{
	float mag = Magnitude();
	return { x_ / mag, y_ / mag , z_ / mag};
}

template<class T>
inline Vector3Template<T> operator+(const Vector3Template<T>& u, const T& k)
{
	return { u.x_ + k ,u.y_ + k ,u.z_ + k };
}

template<class T>
inline Vector3Template<T> operator-(const Vector3Template<T>& u, const T& k)
{
	return { u.x_ - k ,u.y_ - k ,u.z_ - k };
}

template<class T>
inline Vector3Template<T> operator*(const Vector3Template<T>& u, const T& k)
{
	return { u.x_ * k ,u.y_ * k ,u.z_ * k };
}

template<class T>
inline Vector3Template<T> operator/(const Vector3Template<T>& u, const T& k)
{
	return { u.x_ / k ,u.y_ / k ,u.z_ / k };
}

template<class T>
inline Vector3Template<T> operator%(const Vector3Template<T>& u, const T& k)
{
	return { u.x_ % k ,u.y_ % k ,u.z_ % k };

}

template<class T>
inline Vector3Template<T> operator+(const Vector3Template<T>& u, const Vector3Template<T>& v)
{
	return { u.x_ + v.x_,u.y_ + v.y_ ,u.z_ + v.z_ };
}

template<class T>
inline Vector3Template<T> operator-(const Vector3Template<T>& u, const Vector3Template<T>& v)
{
	return { u.x_ - v.x_,u.y_ - v.y_ ,u.z_ - v.z_ };
}

template<class T>
inline Vector3Template<T> operator*(const Vector3Template<T>& u, const Vector3Template<T>& v)
{
	return { u.x_ * v.x_,u.y_ * v.y_ ,u.z_ * v.z_ };
}

template<class T>
inline Vector3Template<T> operator/(const Vector3Template<T>& u, const Vector3Template<T>& v)
{
	return { u.x_ / v.x_,u.y_ / v.y_ ,u.z_ / v.z_ };
}

template<class T>
inline Vector3Template<T> operator%(const Vector3Template<T>& u, const Vector3Template<T>& v)
{
	return 	{ u.x_ % v.x_,u.y_ % v.y_ ,u.z_ % v.z_ };
}

template<class T>
inline Vector3Template<T> operator*(const T& k, const Vector3Template<T>& u)
{
	return { u.x_ * k ,u.y_ * k ,u.z_ * k };
}

template<class T>
inline float Dot(const Vector3Template<T>& u, const Vector3Template<T>& v)
{
	return u.x_ * v.x_ + u.y_ * v.y_ + u.z_ * v.z_;
}

template<class T>
inline Vector3Template<T> Cross(const Vector3Template<T>& u, const Vector3Template<T>& v)
{
	return { u.y_ * v.z_ - u.z_ * v.y_,
			 u.z_ * v.x_ - u.x_ * v.z_,
			 u.x_ * v.y_ - u.y_ * v.x_};
}

template<class T>
inline Vector3Template<T> Normal(const Vector3Template<T>& u)
{
	

	return Vector3Template<T>();
}

template<class T>
inline Vector3Template<T> abs(const Vector3Template<T>& u)
{
	return { abs(u.x_), abs(u.y_),abs(u.z_) };
}