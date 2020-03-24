#include <iostream>

void getNumbers(int(&numbers)[5]);
void largerThanN(int numbers[], int size, int n);

int main() {

	int n;
	int numbers[5];

	std::cout << "Enter a value for n: ";
	std::cin >> n;

	getNumbers(numbers);
	largerThanN(numbers, 5, n);

	system("pause");
	return 0;
}

void getNumbers(int(&numbers)[5]) {
	int number;
	int counter = 0;

	do {
		std::cout << "[" << counter + 1 << "] Enter a score or enter -99 to exit: ";
		std::cin >> number;

		if (number == -99) {
			counter = 5;
		}
		else {
			numbers[counter] = number;
			counter += 1;
		}
	} while (counter < 5);
}

void largerThanN(int numbers[], int size, int n) {
	for (int i = 0; i < size; i++) {
		if (numbers[i] > n) {
			std::cout << numbers[i] << " is gt than " << n << std::endl;
		}
	}
}