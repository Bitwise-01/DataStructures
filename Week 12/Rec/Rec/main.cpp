#include <iostream>

int add(int n);
int fib(int n);

int main() {

	// std::cout << add(4) << std::endl;
	std::cout << fib(4) << std::endl;

	system("pause");
	return 0;
}

int add(int n) {

	if (n > 0) {
		return add(n - 1) + add(n - 2);
	}

	return 1;
}


int fib(int n) {
	if (n > 0) {
		return (n - 1) + (n - 2);
	}
	
	return 1;
}