#pragma once
#include "RuleSet.h"
#include "vec2.h"

class LSystem
{
public:
	LSystem(std::string _axiom, RuleSet _rs);
	LSystem();
	~LSystem();

	std::string getString(int steps);
	void getLSystem(std::string);
	Vec2f getAngles(); //Only for when getLSystem is used
private:
	std::string steps(int steps, std::string);

	std::string axiom;
	RuleSet rs;

	float leftAngle;
	float rightAngle;
};
