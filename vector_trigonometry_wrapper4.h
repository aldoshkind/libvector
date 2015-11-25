#pragma once

#include "vector4.h"

template<class type>
vector4<type> atan(const vector4<type> &op)
{
	return vector4<type>(atan(op.x), atan(op.y));
}

template<class type>
vector4<type> tan(const vector4<type> &op)
{
	return vector4<type>(tan(op.x), tan(op.y));
}

template<class type>
vector4<type> cos(const vector4<type> &op)
{
	return vector4<type>(cos(op.x), cos(op.y));
}

template<class type>
vector4<type> sin(const vector4<type> &op)
{
	return vector4<type>(sin(op.x), sin(op.y));
}
