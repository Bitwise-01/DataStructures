/*
	Date: 09/12/2018
	Author: Mohamed
	Description: Asks the user to guess a random number.
*/

#include <iostream>
#include <time.h>

int main() {

	srand(time(NULL)); // seed
	int rand_int = (1 + rand() % 100);
	bool is_guessed = false;
	int attempts = 0;
	int num;

	do {
		std::cout << "Enter a number between 1-100: " << std::flush;
		std::cin >> num;
		attempts += 1;

		if (num > rand_int) {
			std::cout << "Your guess is above" << std::endl;
		}
		else if (num < rand_int) {
			std::cout << " Your guess is below" << std::endl;
		}
		else {
			std::cout << "\nYour guess is correct\nAttempts: " << attempts << std::endl;
			is_guessed = true;
		}
	} while (!is_guessed);

	system("pause");
	return 0;
}