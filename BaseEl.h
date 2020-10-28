#pragma once
#include <string>

#include "Cell.h"
class BaseEl : public Cell
{
private:
	std::string name;

public:
	BaseEl(Cell* suc = nullptr, const std::string& s = "");
	
	// Access methods would be declared here.
	virtual const std::string& getName() const;
	void display() const override;
};
