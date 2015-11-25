#pragma once

#include "vector3.h"

template<class type>
vector3<type> atan(const vector3<type> &op)
{
	return vector3<type>(atan(op.x), atan(op.y));
}

template<class type>
vector3<type> tan(const vector3<type> &op)
{
	return vector3<type>(tan(op.x), tan(op.y));
}

template<class type>
vector3<type> cos(const vector3<type> &op)
{
	return vector3<type>(cos(op.x), cos(op.y));
}

template<class type>
vector3<type> sin(const vector3<type> &op)
{
	return vector3<type>(sin(op.x), sin(op.y));
}
