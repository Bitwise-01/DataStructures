#include <iostream>
#include <string>
#include "date.h"

int main()
{
	Date aDate(3, 15, 2016);

	aDate.displayShort();
	aDate.displayLong();
	aDate.displayGlobal();
	std::cout << std::endl;

	system("pause");
	return 0;
} 
