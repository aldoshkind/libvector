#pragma once

#include "vector2.h"

template<class type>
vector2<type> atan(const vector2<type> &op)
{
	return vector2<type>(atan(op.x), atan(op.y));
}

template<class type>
vector2<type> tan(const vector2<type> &op)
{
	return vector2<type>(tan(op.x), tan(op.y));
}

template<class type>
vector2<type> cos(const vector2<type> &op)
{
	return vector2<type>(cos(op.x), cos(op.y));
}

template<class type>
vector2<type> sin(const vector2<type> &op)
{
	return vector2<type>(sin(op.x), sin(op.y));
}
