#include <iostream>

int main() {

	int amt = 1;

	for(int value=32; value<127; value++) 
	{
		std::cout << static_cast <char>(value) << " ";			
		
		if (amt == 16) {
			amt = 0;
			std::cout << std::endl;
		}
		amt += 1;
	} 

	std::cout << std::endl;
	system("pause");
	return 0;
}