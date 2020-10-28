#pragma once
#include <string>
#include "Cell.h"

class InhomList
{
private:
	Cell* first;

protected:
	Cell* getPrev(const std::string& s); // +
	Cell* getPos(const std::string& n); // +
	void insertAfter(const std::string& s, Cell* prev); // +
	void insertAfter(const std::string& s, const std::string& b,
		Cell* prev); // +
	void erasePos(Cell* pos); // +

public:
	InhomList(); // +
	InhomList(const InhomList& src); // +
	~InhomList(); // +
	InhomList& operator=(const InhomList& src); // +
	void insert(const std::string& n); // +
	void insert(const std::string& n, const std::string& b); // +
	void erase(const std::string& n); // +
	void displayAll() const; // +
	
};
