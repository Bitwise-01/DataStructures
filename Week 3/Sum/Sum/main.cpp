#include <iostream>

int main() {

	int total = 0;
	int max_number;
	bool is_valid = false;

	do {
		std::cout << "Enter a number greater than 0: " << std::flush;
		std::cin >> max_number;

		is_valid = (max_number > 0) ? true : false;
	} while (!is_valid);

	for (int n = 1; n <= max_number; n++) {
		total += n;
	}

	std::cout << "Total: " << total << std::endl;
	system("pause");
	return 0;
}