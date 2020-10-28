#include <iostream>
#include "DerivedEl.h"

DerivedEl::DerivedEl(Cell* suc, const std::string& s, const std::string& b)
{
}

const std::string& DerivedEl::getName() const
{
	return rem;
}

void DerivedEl::display() const
{
	std::cout << "\nName: " + getName()
		<< "\nRem: " + rem << '\n';
}

std::string& DerivedEl::getRem()
{
	return rem;
}
