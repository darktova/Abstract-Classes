#include <iostream>
#include "InhomList.h"

int main()
{
	InhomList liste1;
	std::cout << "\nTo test inserting.\n";
	liste1.insert("Bully, Max");
	liste1.insert("Cheers, Rita", "always merry");
	liste1.insert("Quick, John", "topfit");
	liste1.insert("Banderas, Antonio");
	liste1.displayAll();
	std::cin.get();
	std::cout << "\nTo test deleting. " << '\n';
	liste1.erase("Banderas, Antonio");
	liste1.erase("Quick, John");
	liste1.erase("Cheers, Rita");
	liste1.displayAll();
	std::cin.get();
	std::cout << "\n----------------------------------"
		<< "\nGenerate a copy and insert an element. "
		<< '\n';
	InhomList liste2(liste1), // Copy constructor
		liste3; // and an empty list.
	liste2.insert("Chipper, Peter", "in good temper");
	liste3 = liste2; // Assignment
	std::cout << "\nAfter the assignment: " << '\n';
	liste3.displayAll();
	return 0;
}
