#include "RuleSet.h"

RuleSet::RuleSet()
{
}

RuleSet::~RuleSet()
{
}

void RuleSet::addRule(std::string left, std::string right)
{
	ruleList.push_back(Rule(left, right));
}

void RuleSet::addRule(Rule rule)
{
	ruleList.push_back(rule);
}

std::string RuleSet::getRule(std::string left)
{
	for (int i = 0; i < ruleList.size(); i++)
	{
		if (left == ruleList.at(i).getLeft())
			return ruleList.at(i).getRight();
	}
	return std::string("NONE");
}
