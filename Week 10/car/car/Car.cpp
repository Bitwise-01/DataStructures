#include "Car.h"

Car::Car(int carYear, std::string carMake) {

	// preventing bad state
	if (carYear > 0) {
		year = carYear;
	}
	else {
		year = 2001;
	}

	if (carMake != "" && carMake != " ") {
		make = carMake;
	}
	else {
		make = "Ferrari";
	}

	speed = 0;
}

int Car::getYear() {
	return year;
}

int Car::getSpeed() {
	return speed;
}

std::string Car::getMake() {
	return make;
}

void Car::accelerate() {
	if ((speed + 5) < 70) {
		speed += 5;
	}
}

void Car::brake() {
	if ((speed - 5) > 0) {
		speed -= 5;
	}
}