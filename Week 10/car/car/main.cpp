#include "Car.h"
#include <iostream>

int main() {

	Car aTinyClownCar(2019, "Ferrari");

	for (int n = 0; n < 5; n++) {
		aTinyClownCar.accelerate();
		std::cout << "Speed: " << aTinyClownCar.getSpeed() << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (int n = 0; n < 5; n++) {
		aTinyClownCar.brake();
		std::cout << "Speed: " << aTinyClownCar.getSpeed() << std::endl;
	}
	   	 
	system("pause");
	return 0;
}