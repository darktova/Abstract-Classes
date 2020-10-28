#pragma once
class Cell
{
private:
	Cell* next;
	
protected:
	Cell(Cell* suc = nullptr);

public:
	virtual ~Cell();
	// Access methods to be declared here.
	Cell* getNext();
	void setNext(Cell* cell);
	virtual void display() const;
};
