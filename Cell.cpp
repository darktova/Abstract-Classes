#include "Cell.h"

Cell::Cell(Cell* suc)
{
	next = suc;
}

Cell::~Cell()
{
}

void Cell::display() const
{
}

Cell* Cell::getNext()
{
	return next;
}

void Cell::setNext(Cell* cell)
{
	next = cell;
}
