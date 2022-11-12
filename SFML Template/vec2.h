#pragma once
#include <math.h>

template<typename T>
struct Vec2 
{
public:
	T x, y;

	Vec2(T _x, T _y)
	{
		x = _x;
		y = _y;
	}

	Vec2() 
	{ 
		x = NULL; 
		y = NULL;
	}
};

typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec2<int> Vec2i;