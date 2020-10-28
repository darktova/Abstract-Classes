#pragma once
#include <string>

#include "BaseEl.h"
#include "Cell.h"

class DerivedEl : public BaseEl
{
private:
	std::string rem;

public:
	DerivedEl(Cell* suc = nullptr, const std::string& s = "",
		const std::string& b = "");
	
	// Access methods would be declared here.
	const std::string& getName() const override;
	void display() const override;
	std::string& getRem();
};

