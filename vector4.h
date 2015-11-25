#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

template <class type>
class vector4
{
public:
	type x, y, z, w;

				vector4					(type x = (type)0, type y = (type)0, type z = (type)0, type w = (type)0);
				~vector4				();

	vector4		operator +				(const vector4 &) const;
	vector4		operator -				(const vector4 &) const;
	vector4		operator =				(const vector4 &);

	vector4		operator +=				(vector4 &);
	vector4		operator -=				(vector4 &);

	vector4		operator *				(double) const;
	vector4		operator /				(double) const;

	vector4		operator *=				(double);
	vector4		operator /=				(double);

	// scalar product
	double		operator *				(const vector4 &) const;

	vector4		normalize				(void);
	double		length					(void);
	double		angle_with_d			(const vector4 &) const;
};

template <class type>
vector4<type>::vector4(type _x, type _y, type _z, type _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

template <class type>
vector4<type>::~vector4()
{
	//
}

template <class type>
vector4<type> vector4<type>::operator +(const vector4 &operand) const
{
	vector4 result = *this;
	result += operand;
	return result;
}

template <class type>
vector4<type> vector4<type>::operator -(const vector4 &operand) const
{
	vector4 result = *this;
	result -= operand;
	return result;
}

template <class type>
vector4<type> vector4<type>::operator =(const vector4 &operand)
{
	this->x = operand.x;
	this->y = operand.y;
	this->z = operand.z;
	this->w = operand.w;
	return *this;
}

template <class type>
vector4<type> vector4<type>::operator * (double operand) const
{
	vector4 result = *this;
	result *= operand;
	return result;
}

template <class type>
vector4<type> vector4<type>::operator / (double operand) const
{
	vector4 result = *this;
	result /= operand;
	return result;
}

template <class type>
vector4<type> vector4<type>::operator *= (double operand)
{
	x *= operand;
	y *= operand;
	z *= operand;
	w *= operand;
	return *this;
}

template <class type>
vector4<type> vector4<type>::operator /= (double operand)
{
	x /= operand;
	y /= operand;
	z /= operand;
	w /= operand;
	return *this;
}

template <class type>
vector4<type> vector4<type>::normalize()
{
	double len = length();
	(*this) /= len;
	return *this;
}

template <class type>
vector4<type> vector4<type>::operator += (vector4 &operand)
{
	x += operand.x;
	y += operand.y;
	z += operand.z;
	w += operand.w;
	return *this;
}

template <class type>
vector4<type> vector4<type>::operator -= (vector4 &operand)
{
	x -= operand.x;
	y -= operand.y;
	z -= operand.z;
	w -= operand.w;
	return *this;
}

template <class type>
double vector4<type>::length()
{
	return sqrt(x*x + y*y + z*z + w*w);
}

template <class type>
double vector4<type>::operator *(const vector4 &operand) const
{
	double result;
	result = x * operand.x + y * operand.y + z * operand.z + w * operand.w;
	return result;
}

template <class type>
double vector4<type>::angle_with_d(const vector4 &operand) const
{
	double result = 180.0 * acos( (operand * (*this)) / ( operand.length() * this->length() )) / M_PI;
	return result;
}

typedef vector4<double>		vector4d;
typedef vector4<float>		vector4f;
typedef vector4<int>		vector4i;
