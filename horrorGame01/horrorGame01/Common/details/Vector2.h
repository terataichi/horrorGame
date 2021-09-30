#include "../Vector2.h"
#include <cmath>
#include <cassert>

template<class T>
Vector2Template<T> Vector2Template<T>::ZERO = {static_cast<T>(0),static_cast<T>(0)};

template<class T>
Vector2Template<T>::Vector2Template()
{
	x_ = 0;
	y_ = 0;
}

template<class T>
Vector2Template<T>::Vector2Template(T x, T y):x_(x), y_(y)
{
}

template<class T>
Vector2Template<T>::~Vector2Template()
{
}

// ���
template<class T>
Vector2Template<T> & Vector2Template<T>::operator=(const Vector2Template<T> & vec)
{
	x_ = vec.x_;
	y_ = vec.y_;
	return *this;
}

// ��r���Z�q
template<class T>
bool Vector2Template<T>::operator==(const Vector2Template<T> & vec) const
{
	return (x_ == vec.x_ && y_ == vec.y_);
}

template<class T>
bool Vector2Template<T>::operator!=(const Vector2Template<T> & vec) const
{
	return !(x_ == vec.x_ && y_ == vec.y_);
}

template<class T>
bool Vector2Template<T>::operator>(const Vector2Template<T> & vec) const
{
	return (x_ > vec.x_ &&y_ > vec.y_);
}

template<class T>
bool Vector2Template<T>::operator>=(const Vector2Template<T> & vec) const
{
	return (x_ >= vec.x_ && y_ >= vec.y_);
}

template<class T>
bool Vector2Template<T>::operator<(const Vector2Template<T> & vec) const
{
	return (x_ > vec.x_ && y_ > vec.y_);
}

template<class T>
bool Vector2Template<T>::operator<=(const Vector2Template<T> & vec) const
{
	return (x_ <= vec.x_ && y_ <= vec.y_);
}

// �Y�������Z
template<class T>
int & Vector2Template<T>::operator[](int i)
{
	if (i == 0)
	{
		return x_;
	}
	else if (i == 1)
	{
		return y_;
	}
	else
	{
		assert(!"error");
		return x_;	// ��O����
	}
}

// ---�P�����Z�q
template<class T>
Vector2Template<T> & Vector2Template<T>::operator+=(const Vector2Template<T> & vec)
{
	x_ += vec.x_;
	y_ += vec.y_;
	return *this;
}

template<class T>
Vector2Template<T> & Vector2Template<T>::operator-=(const Vector2Template<T> & vec)
{
	x_ -= vec.x_;
	y_ -= vec.y_;
	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator*=(const Vector2Template& vec)
{
	x_ *= vec.x_;
	y_ *= vec.y_;
	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator/=(const Vector2Template& vec)
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
	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator%=(const Vector2Template& vec)
{
	Vector2 tmp{ 0,0 };
	if (vec.x_ != 0)
	{
		tmp.x_ = static_cast<int>(x_) % static_cast<int>(vec.x_);
	}
	if (vec.y_ != 0)
	{
		tmp.y_ = static_cast<int>(y_) % static_cast<int>(vec.y_);
	}
	this->x_ = static_cast<T>(tmp.x_);
	this->y_ = static_cast<T>(tmp.y_);
	return *this;
}

template<class T>
Vector2Template<T> & Vector2Template<T>::operator*=(T k)
{
	x_ *= k;
	y_ *= k;
	return *this;
}

template<class T>
Vector2Template<T> & Vector2Template<T>::operator/=(T k)
{
	x_ /= k;
	y_ /= k;
	return *this;
}

template<class T>
float Vector2Template<T>::Magnitude() const
{
	return sqrtf(x_ * x_ + y_ * y_);
}

template<class T>
Vector2Template<float> Vector2Template<T>::Normalized(void)
{
	float mag = Magnitude();
	return { x_ / mag, y_ / mag };
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator+() const
{
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator-() const
{
	return { -x_, -y_ };
}

// ---�޸�ق̉��Z
template<class T>
Vector2Template<T> operator+(const Vector2Template<T>& u, const T& k)
{
	return { u.x_ + k ,u.y_ + k };
}
template<class T>
Vector2Template<T> operator-(const Vector2Template<T> & u, const T & k)
{
	return { u.x_ - k ,u.y_ - k };
}
template<class T>
Vector2Template<T> operator%(const Vector2Template<T> & u, const T & k)
{
	return { u.x_ % k ,u.y_ % k };
}
template<class T>
Vector2Template<T> operator*(const Vector2Template<T> & u, const T & k)
{
	return { u.x_ * k ,u.y_ * k };
}
template<class T>
Vector2Template<T> operator/(const Vector2Template<T> & u, const T & k)
{
	return { u.x_ / k ,u.y_ / k };
}

template<class T>
Vector2Template<T> operator+(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	return { u.x_ + v.x_,u.y_ + v.y_ };
}
template<class T>
Vector2Template<T> operator-(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	return { u.x_ - v.x_,u.y_ - v.y_ };
}
template<class T>
Vector2Template<T> operator*(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	return { u.x_ * v.x_,u.y_ * v.y_ };
}
template<class T>
Vector2Template<T> operator/(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	return { u.x_ / v.x_,u.y_ / v.y_ };
}
template<class T>
Vector2Template<T> operator%(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	return { u.x_ % v.x_,u.y_ % v.y_ };
}

template<class T>
Vector2Template<T> operator*(const T & k, const Vector2Template<T> & u)
{
	return { k * u.x_ ,k * u.y_ };
}

template<class T>
float Dot(const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	return u.x_ * v.x_ + u.y_ * v.y_;
}

template<class T>
float Cross(const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	return u.x_ * v.y_ - v.x_ * u.y_;
}

template<class T>
Vector2Template<T> Normal(Vector2Template<T>& u)
{
	return { -u.y_, u.x_ };
}

template<class T>
Vector2Template<T> abs(const Vector2Template<T>& u)
{
	return { abs(u.x_), abs(u.y_) };
}
