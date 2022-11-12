#pragma once
#include <iostream>
#include <vector>
#include "Rule.h"

class RuleSet
{
public:
	RuleSet();
	~RuleSet();

	void addRule(std::string left, std::string right);
	void addRule(Rule);

	std::string getRule(std::string left);

protected:
	std::vector<Rule> ruleList;
};

