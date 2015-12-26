#pragma once

#include <algorithm>

// returns value closest to v which is in [lower, upper]
template <class value_type>
inline value_type clamp(const value_type &v, const value_type &lower, const value_type &upper)
{
	return v > upper ? upper : (v < lower ? lower : v);
}

// sets v to a value which is a closest to v and is in [lower, upper]
template <class value_type>
inline void clamp_this(value_type &v, const value_type &lower, const value_type &upper)
{
	v = v > upper ? upper : (v < lower ? lower : v);
}

// swaps arguments values if first is bigger
template <class value_type>
inline void less_first(value_type &a, value_type &b)
{
	if(a > b)
	{
		std::swap(a, b);
	}
}

template <class value_type>
inline value_type wrap(const value_type &v, const value_type &lower, const value_type &upper)
{
	value_type d = abs(upper - lower);
	return (v < lower) ? (upper - (lower - v) % d) : (lower + (v - lower) % d);
}

template <class value_type>
inline bool within(const value_type &value, const value_type &left, const value_type &right, bool inclusive = true)
{
	bool res = false;
	if(inclusive)
	{
		res = ((left <= value) && (value <= right)) || ((left >= value) && (value >= right));
	}
	else
	{
		res = ((left < value) && (value < right)) || ((left > value) && (value > right));
	}
	return res;
}
