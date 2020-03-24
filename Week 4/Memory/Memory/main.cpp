#include <iostream>
#include <string>


int main() {

	int a[3] = { 20, 32, 44 };
		
	// locations 
	std::cout << a[0] << "; " << &a[0] << std::endl;
	std::cout << a[1] << "; " << &a[1] << std::endl;
	std::cout << a[2] << "; " << &a[2] << std::endl;	

	system("pause");
	return 0;
}