#pragma once
#include <string>
#include <sstream>
template <typename T>
struct Pair
{
public:
	T x;
	T y;
	Pair(T nx, T ny):x(nx), y(ny){}
	Pair() :x(0),y(0){}
	std::string toString() {
		std::ostringstream ss;
		ss << "(" << x << ", " << y << ")";
		return ss.str();
	}
};