#include "LSystem.h"

LSystem::LSystem(std::string _axiom, RuleSet _rs)
{
	axiom = _axiom;
	rs = _rs;
}

LSystem::LSystem()
{
}

LSystem::~LSystem()
{
}

std::string LSystem::getString(int steps)
{
	return this->steps(steps, axiom);;
}

std::string LSystem::steps(int steps, std::string temp)
{
	if (steps < 0)
		return temp;
	else
	{
		std::string str = "";

		for (int i = 0; i < temp.length(); i++)
		{
			std::string ch = "";
			ch += temp.at(i);
			std::string tmp = rs.getRule(ch);

			if (tmp == "NONE")
				str += temp.at(i);
			else
				str += tmp;
		}

		temp = str;

		return this->steps(steps - 1, temp);
	}
}
