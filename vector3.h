#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "measure_conversion.h"

template <class type>
class vector3
{
public:
	type x, y, z;

	/*constructor*/		vector3					(type x = (type)0, type y = (type)0, type z = (type)0);
	/*destructor*/		~vector3				(void);

	vector3				operator -				() const;
	vector3				operator +				(const vector3 &) const;
	vector3				operator -				(const vector3 &) const;
	vector3				operator =				(const vector3 &);
	vector3				operator *				(const vector3 &) const;
	vector3				operator /				(const vector3 &) const;

	vector3				operator +=				(const vector3 &);
	vector3				operator -=				(const vector3 &);
	vector3				operator *=				(const vector3 &);
	vector3				operator /=				(const vector3 &);

	vector3				operator *				(double) const;
	vector3				operator /				(double) const;

	vector3				operator *=				(double);
	vector3				operator /=				(double);

	bool				operator !=				(const vector3 &) const;
	bool				operator ==				(const vector3 &) const;

	// scalar(dot) product
	double				dot						(const vector3 &) const;

	// cross product
	vector3				cross					(const vector3 &) const;

	vector3				normalize				(void);
	double				length					(void) const;
	
	vector3				normalized				(void) const;
	
	double				sum_of_coordinates		(void) const;
	
	vector3				shifted_coordinates		(void) const;

	// angle with another vector, in degrees
	double				angle_with_d			(const vector3 &) const;
	// in rad
	double				angle_with_r			(const vector3 &) const;

	// get rotated, without changing current, in rad
	vector3				rotated_around_axis_r				(vector3 axis, double angle) const;
	vector3				rotated_around_axis_rodrigues_r		(vector3 axis, double angle) const;
};

template <class type>
vector3<type>::vector3(type x, type y, type z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template <class type>
vector3<type>::~vector3()
{
	//
}

template <class type>
vector3<type> vector3<type>::shifted_coordinates(void) const
{
	vector3<type> res;
	res.x = this->z;
	res.y = this->x;
	res.z = this->y;
	return res;
}

template <class type>
double vector3<type>::sum_of_coordinates(void) const
{
	double res = 0;
	res += this->x;
	res += this->y;
	res += this->z;
	return res;
}

template <class type>
vector3<type> vector3<type>::operator +(const vector3 &operand) const
{
	vector3 result = *this;
	result += operand;
	return result;
}

template <class type>
vector3<type> vector3<type>::operator -(const vector3 &operand) const
{
	vector3 result = *this;
	result -= operand;
	return result;
}

template <class type>
vector3<type> vector3<type>::operator =(const vector3 &operand)
{
	this->x = operand.x;
	this->y = operand.y;
	this->z = operand.z;
	return *this;
}

template <class type>
vector3<type> vector3<type>::operator * (double operand) const
{
	vector3 result = *this;
	result *= operand;
	return result;
}

template <class type>
vector3<type> vector3<type>::operator / (double operand) const
{
	vector3 result = *this;
	result /= operand;
	return result;
}

template <class type>
vector3<type> vector3<type>::operator *= (double operand)
{
	x *= operand;
	y *= operand;
	z *= operand;
	return *this;
}

template <class type>
vector3<type> vector3<type>::operator /= (double operand)
{
	x /= operand;
	y /= operand;
	z /= operand;
	return *this;
}

template <class type>
vector3<type> vector3<type>::normalize(void)
{
	double len = length();
	if(len != 0.0)
	{
		(*this) /= len;
	}
	return *this;
}

template <class type>
vector3<type> vector3<type>::normalized(void) const
{
	vector3 res = *this;
	res.normalize();
	return res;
}

template <class type>
vector3<type> vector3<type>::operator += (const vector3 &operand)
{
	x += operand.x;
	y += operand.y;
	z += operand.z;
	return *this;
}

template <class type>
vector3<type> vector3<type>::operator -= (const vector3 &operand)
{
	x -= operand.x;
	y -= operand.y;
	z -= operand.z;
	return *this;
}

template <class type>
double vector3<type>::length() const
{
	return sqrt(x * x + y * y + z * z);
}

template <class type>
double vector3<type>::dot(const vector3 &operand) const
{
	double result;
	result = x * operand.x + y * operand.y + z * operand.z;
	return result;
}

template <class type>
double vector3<type>::angle_with_d(const vector3 &operand) const
{
	double result = DEG(angle_with_r(operand));
	return result;
}

template <class type>
double vector3<type>::angle_with_r(const vector3 &operand) const
{
	double acos_param = (operand.dot(*this)) / (operand.length() * this->length());
	if(fabs(acos_param) > 1.0)
	{
		acos_param = acos_param > 0.0 ? 1.0 : -1.0;
	}
	double result = acos(acos_param);
	return result;
}

template <class type>
vector3<type> vector3<type>::cross(const vector3 &operand) const
{
	vector3 result;
	result.x = z * operand.y - y * operand.z;
	result.y = x * operand.z - z * operand.x;
	result.z = y * operand.x - x * operand.y;
	return result;
}

template <class type>
vector3<type> vector3<type>::rotated_around_axis_r(vector3 axis, double angle) const
{
	if(angle == 0.0)
	{
		return *this;
	}
	axis.normalize();
	vector3 res;

	type cA = cos(angle);
	type omcA = 1.0 - cA;
	type sA = sin(angle);

	type &ux = axis.x;
	type &uy = axis.y;
	type &uz = axis.z;

	// left handed
	/*res.x = (cA + ux * ux * omcA) * x + (ux * uy * omcA - uz * sA) * y + (ux * uz * omcA + uy * sA) * z;
	res.y = (uy * ux * omcA + uz * sA) * x + (cA + uy * uy * omcA) * y + (uy * uz * omcA - ux * sA) * z;
	res.z = (uz * ux * omcA - uy * sA) * x + (uz * uy * omcA + ux * sA) * y + (cA + uz * uz * omcA) * z;*/

	// right handed (transposed left, as eye can see)
	res.x = (cA + ux * ux * omcA) * x + (ux * uy * omcA + uz * sA) * y + (ux * uz * omcA - uy * sA) * z;
	res.y = (uy * ux * omcA - uz * sA) * x + (cA + uy * uy * omcA) * y + (uy * uz * omcA + ux * sA) * z;
	res.z = (uz * ux * omcA + uy * sA) * x + (uz * uy * omcA - ux * sA) * y + (cA + uz * uz * omcA) * z;

	return res;
}

template <class type>
bool vector3<type>::operator != (const vector3 &op) const
{
	return ((x != op.x) || (y != op.y) || (z != op.z));
}

template <class type>
bool vector3<type>::operator == (const vector3 &op) const
{
	return ((x == op.x) && (y == op.y) && (z == op.z));
}

template <class type>
vector3<type> vector3<type>::operator *= (const vector3 &operand)
{
	x *= operand.x;
	y *= operand.y;
	z *= operand.z;
	return *this;
}

template <class type>
vector3<type> vector3<type>::operator /= (const vector3 &operand)
{
	x /= operand.x;
	y /= operand.y;
	z /= operand.z;
	return *this;
}

template <class type>
vector3<type> vector3<type>::operator *(const vector3 &operand) const
{
	vector3 result = *this;
	result *= operand;
	return result;
}

template <class type>
vector3<type> vector3<type>::operator /(const vector3 &operand) const
{
	vector3 result = *this;
	result /= operand;
	return result;
}

template <class type>
vector3<type> vector3<type>::rotated_around_axis_rodrigues_r(vector3 axis, double angle) const
{
	if(angle == 0.0)
	{
		return *this;
	}
	axis.normalize();
	vector3 res;

	res = (axis.cross(*this)) * sin(angle) + (*this) * cos(angle) + axis * ((axis.dot(*this)) * (1 - cos(angle)));

	return res;
}

template <class type>
vector3<type> vector3<type>::operator - () const
{
	return *this * (type)-1;
}

typedef vector3<double>		vector3d;
typedef vector3<float>		vector3f;
typedef vector3<int>		vector3i;
