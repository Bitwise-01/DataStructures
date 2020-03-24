#include <iostream>
#include "LinkedList.h"

int main() {

	LinkedList list;

	list.add(3);
	list.add(1);
	list.add(4);
	list.add(1);
	list.add(5);

	if (list.isMember(7)) {
		std::cout << "Is a member" << std::endl;
	}
	else {
		std::cout << "Is not a member" << std::endl;
	}

	if (list.isMember(9)) {
		std::cout << "Is a member" << std::endl;
	}
	else {
		std::cout << "Is not a member" << std::endl;
	}


		
	system("pause");
	return 0;
}