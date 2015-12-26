#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "additional_math.h"

template <class type>
class vector2
{
public:
	type x, y;

				vector2					(type x = (type)0, type y = (type)0);
				~vector2				();

	vector2		operator +				(const vector2 &) const;
	vector2		operator -				(const vector2 &) const;
	vector2		operator -				(void);
	vector2		operator =				(const vector2 &);
	vector2		operator *				(const vector2 &) const;
	vector2		operator /				(const vector2 &) const;

	vector2		operator +=				(const vector2 &);
	vector2		operator -=				(const vector2 &);
	vector2		operator *=				(const vector2 &);
	vector2		operator /=				(const vector2 &);

	vector2		operator *				(double) const;
	vector2		operator /				(double) const;

	vector2		operator *=				(double);
	vector2		operator /=				(double);
	
	bool		operator < 				(const vector2 &) const;
	bool		operator == 			(const vector2 &) const;
	bool		operator != 			(const vector2 &) const;

	// scalar product
	double		dot						(const vector2 &) const;

	vector2		normalize				(void);
	vector2		normalized				(void);
	double		length					(void) const;
	
	double		angle_with_r			(const vector2 &) const;
	double		directed_angle_with_r	(const vector2 &) const;

	vector2		rotated					(type angle) const;

	//
	template <class t>
	operator	vector2<t>				() const
	{
		return vector2<t> ((t)x, (t)y);
	}
};

template <class type>
vector2<type>::vector2(type _x, type _y)
{
	x = _x;
	y = _y;
}

template <class type>
vector2<type>::~vector2()
{
	//
}

template <class type>
vector2<type> vector2<type>::operator +(const vector2 &operand) const
{
	vector2 result = *this;
	result += operand;
	return result;
}

template <class type>
vector2<type> vector2<type>::operator -(const vector2 &operand) const
{
	vector2 result = *this;
	result -= operand;
	return result;
}

template <class type>
vector2<type> vector2<type>::operator -(void)
{
	vector2 &result = *this;
	result.x = -result.x;
	result.y = -result.y;
	return result;
}

template <class type>
vector2<type> vector2<type>::operator =(const vector2 &operand)
{
	this->x = operand.x;
	this->y = operand.y;
	return *this;
}

template <class type>
vector2<type> vector2<type>::operator * (double operand) const
{
	vector2 result = *this;
	result *= operand;
	return result;
}

template <class type>
vector2<type> vector2<type>::operator / (double operand) const
{
	vector2 result = *this;
	result /= operand;
	return result;
}

template <class type>
vector2<type> vector2<type>::operator *= (double operand)
{
	x *= operand;
	y *= operand;
	return *this;
}

template <class type>
vector2<type> vector2<type>::operator /= (double operand)
{
	x /= operand;
	y /= operand;
	return *this;
}

template <class type>
vector2<type> vector2<type>::normalize()
{
	double len = length();
	(*this) /= len;
	return *this;
}

template <class type>
vector2<type> vector2<type>::normalized()
{
	vector2<type> res = (*this);
	res.normalize();
	return res;
}

template <class type>
vector2<type> vector2<type>::operator += (const vector2 &operand)
{
	x += operand.x;
	y += operand.y;
	return *this;
}

template <class type>
vector2<type> vector2<type>::operator -= (const vector2 &operand)
{
	x -= operand.x;
	y -= operand.y;
	return *this;
}

template <class type>
double vector2<type>::length()  const
{
	return sqrt(x * x + y * y);
}

template <class type>
double vector2<type>::dot(const vector2 &operand)  const
{
	double result;
	result = x * operand.x + y * operand.y;
	return result;
}

template <class type>
double vector2<type>::angle_with_r(const vector2 &operand)  const
{	
	double result = acos(clamp((operand.dot(*this)) / (operand.length() * this->length()), -1.0, 1.0));
	return result;
}

template <class type>
double vector2<type>::directed_angle_with_r(const vector2 &operand)  const
{
	double result = this->angle_with_r(operand);
	double dir = this->y * operand.x - this->x * operand.y;
	if(dir < 0.0)
	{
		result = 2 * M_PI - result;
	}
	return result;
}

template <class type>
vector2<type> vector2<type>::operator /= (const vector2 &operand)
{
	x /= operand.x;
	y /= operand.y;
	return *this;
}

template <class type>
vector2<type> vector2<type>::operator *= (const vector2 &operand)
{
	x *= operand.x;
	y *= operand.y;
	return *this;
}

template <class type>
vector2<type> vector2<type>::operator * (const vector2 &operand)  const
{
	vector2 result = *this;
	result *= operand;
	return result;
}

template <class type>
vector2<type> vector2<type>::operator / (const vector2 &operand)  const
{
	vector2 result = *this;
	result /= operand;
	return result;
}

template <class type>
vector2<type> vector2<type>::rotated(type angle)  const
{
	vector2 result;
	result.x = this->x * cos(angle) + this->y * sin(angle);
	result.y = this->x * -sin(angle) + this->y * cos(angle);
	return result;
}

template <class type>
bool vector2<type>::operator < (const vector2 &op) const
{
	if(x < op.x)
	{
		return true;
	}
	else if(x == op.x)
	{
		if(y < op.y)
		{
			return true;
		}
	}
	
	return false;
}

template <class type>
bool vector2<type>::operator == (const vector2 &op) const
{
	if(x == op.x && y == op.y)
	{
		return true;
	}
	
	return false;
}

template <class type>
bool vector2<type>::operator != (const vector2 &op) const
{
	return !(*this == op);
}

typedef vector2<double>		vector2d;
typedef vector2<float>		vector2f;
typedef vector2<int>		vector2i;
