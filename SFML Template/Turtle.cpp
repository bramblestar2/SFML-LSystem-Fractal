#include "Turtle.h"

Turtle::Turtle(float x, float y)
{
	position = Vec2f(x, y);
	heading = 0;

	vertices.push_back(position);
}

Turtle::Turtle()
{
	position = Vec2f(0, 0);
	heading = 0;

	vertices.push_back(position);
}

Turtle::~Turtle()
{
}

void Turtle::clear()
{
	vertices.clear();
}

void Turtle::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void Turtle::setHeading(float a)
{
	heading = a;
}

void Turtle::rt()  
{
	heading = fmod(heading + 90, 360);
}

void Turtle::rt(float angle) 
{
	heading = fmod(heading + angle, 360);
}

void Turtle::lt() 
{
	heading = fmod(fmod(heading - 90, -360) + 360, 360);
}

void Turtle::lt(float angle) 
{
	heading = fmod(fmod(heading - angle, -360) + 360, 360);
}

void Turtle::move(float distance) 
{
	//Move
	position.x += cosf(toRadians(heading)) * distance;
	position.y += sinf(toRadians(heading)) * distance;

	//Push back location
	vertices.push_back(position);
}

float Turtle::toRadians(float degrees)
{
	return heading * (PI / 180);
}

float Turtle::getHeading()
{
	return heading;
}

Vec2f Turtle::getPosition()
{
	return position;
}

std::vector<Vec2f> Turtle::getVertices()
{
	return vertices;
}