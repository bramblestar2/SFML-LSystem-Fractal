#pragma once
#include "RuleSet.h"

class LSystem
{
public:
	LSystem(std::string _axiom, RuleSet _rs);
	LSystem();
	~LSystem();

	std::string getString(int steps);
private:
	std::string steps(int steps, std::string);

	std::string axiom;
	RuleSet rs;
};
