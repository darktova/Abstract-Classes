#include <string>
#include <typeinfo>

#include "BaseEl.h"
#include "InhomList.h"

#include "DerivedEl.h"

Cell* InhomList::getPrev(const std::string& s) 
{
	// tmp vars
	Cell *i = first,
		*prev = nullptr;
	while (i)
		if (s > dynamic_cast<BaseEl*>(i)->getName())
		{
			prev = i;
			i = i->getNext();
		}
		else
			return prev;
}

Cell* InhomList::getPos(const std::string& n) 
{
	auto* i = first;
	while (i && (dynamic_cast<BaseEl*>(i)->getName() == n)) 
		i = i->getNext();

	return (i && (dynamic_cast<BaseEl*>(i)->getName() == n)
		? i : nullptr);
}

void InhomList::insertAfter(const std::string& s, Cell* prev) 
{
	if (!prev) // Insert at the beginning,
		first = new BaseEl(first, s);
	else // middle, or end.
	{
		Cell* p = new BaseEl(prev->getNext(), s);
		prev->setNext(p);
	}
}

void InhomList::insertAfter(const std::string& s, const std::string& b, Cell* prev) 
{
	if (prev == nullptr) // Insert at the beginning,
		first->setNext(new DerivedEl(first, s, b));
	else // middle, or end.
	{
		Cell* p = new DerivedEl(prev->getNext(), s, b);
		prev->setNext(p);
	}
}

void InhomList::erasePos(Cell* pos)
{
	if (pos)
	{ 
		// Get the predecessor
		auto* i = getPrev(dynamic_cast<BaseEl*>(pos)->getName());
		
		// and bend pointer
		if (i)
			i = pos->getNext();

		// release memory;
		delete i, pos;
	}
}

InhomList::InhomList() 
{
	first = nullptr;
}

InhomList::InhomList(const InhomList& src)
{
	// Append the elements from src to the empty list.
	first = nullptr;
	
	for (auto* i = src.first; i != nullptr; i = i->getNext())
		if (typeid(*i) == typeid(DerivedEl))
			insert(dynamic_cast<DerivedEl*>(i)->getName(),
				dynamic_cast<DerivedEl*>(i)->getRem());
		else
			insert(dynamic_cast<BaseEl*>(i)->getName());
}

InhomList::~InhomList()
{
	for (Cell* i = first, *next = nullptr;
		i != nullptr; i = next)
	{
		next = i->getNext();
		delete i;
	}
}

InhomList& InhomList::operator=(const InhomList& src)  
{
	Cell* i = first;

	// Release whole list memory
	for (Cell *next = nullptr; i != nullptr; i = next)
	{
		next = i->getNext();
		delete i;
	}

	// Empty list
	first = nullptr;
	
	// Append the elements from src to the empty list.
	for (i = src.first; i != nullptr; i = i->getNext())
		if (typeid(*i) == typeid(DerivedEl))
			insert(dynamic_cast<DerivedEl*>(i)->getName(),
				dynamic_cast<DerivedEl*>(i)->getRem());
		else
			insert(dynamic_cast<BaseEl*>(i)->getName());
	
	return *this;
}

void InhomList::insert(const std::string& n) 
{
	insertAfter(n, getPrev(n));
}

void InhomList::insert(const std::string& n, const std::string& b)
{
	insertAfter(n, b, getPrev(n));
}

void InhomList::erase(const std::string& n)
{
	erasePos(getPos(n));
}

void InhomList::displayAll() const
{
	for (auto* i = first; i != nullptr; i = i->getNext())
		i->display();
}
