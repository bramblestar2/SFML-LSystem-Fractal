#pragma once
#include <iostream>
#include <vector>
#include "vec2.h"

class Turtle
{
public:
	Turtle(float,float);
	Turtle();
	~Turtle();

	void clear();
	void setPosition(float, float);
	void setHeading(float);

	void rt();
	void rt(float);
	void lt();
	void lt(float);

	float getHeading();
	Vec2f getPosition();
	std::vector<Vec2f> getVertices();

	void move(float);
private:
	float toRadians(float degrees);

	Vec2f position;
	float heading;

	const float PI = 3.14159265;

	std::vector<Vec2f> vertices;
};

