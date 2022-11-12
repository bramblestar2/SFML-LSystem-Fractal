#pragma once
#include <iostream>
class Rule
{
public:
	Rule(std::string _left, std::string _right);
	Rule();
	~Rule();

	std::string getLeft() const;
	std::string getRight() const;
protected:
	std::string left, right;
};

