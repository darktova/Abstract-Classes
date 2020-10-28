#include <iostream>
#include "BaseEl.h"

BaseEl::BaseEl(Cell* suc, const std::string& s)
{
}

const std::string& BaseEl::getName() const
{
	return name;
}

void BaseEl::display() const
{
	std::cout << "\nName: " + name << '\n';
}
