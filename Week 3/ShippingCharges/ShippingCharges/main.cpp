#include <iostream>

double calculateCharge(double weight, double distance);

int main() {
	double charge; 
	double weight;
	double distance;

	do {
		std::cout << "Enter package weight in kg: " << std::flush;
		std::cin >> weight;

		if (weight > 0) {
			std::cout << "Enter the distance to ship: " << std::flush;
			std::cin >> distance;		

			charge = calculateCharge(weight, distance);
			std::cout << "Charge: $" << charge << "\n" << std::endl;
		}

	} while (weight != 0);

	return 0;
}

double calculateCharge(double weight, double distance) {
	double rate;

	if (weight <= 2) {
		rate = 3.10;
	}
	else if (weight > 2 && weight <= 6) {
		rate = 4.20;
	}
	else if (weight > 6 && weight <= 10) {
		rate = 5.30;
 	} else if(weight > 10) {
		rate = 6.40;
	}

	return (rate * distance)/500;
}