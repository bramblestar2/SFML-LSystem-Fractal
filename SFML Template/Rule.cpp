#include "Rule.h"

Rule::Rule(std::string _left, std::string _right)
{
	left = _left;
	right = _right;
}

Rule::Rule()
{
}

Rule::~Rule()
{
}

std::string Rule::getLeft() const
{
	return left;
}

std::string Rule::getRight() const
{
	return right;
}
