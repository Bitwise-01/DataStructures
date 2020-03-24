#pragma once
#include <string>

class Car
{
private:
	int year;
	int speed;
	std::string make;	

public:
	Car(int carYear, std::string carMake);

	int getYear();
	int getSpeed();
	std::string getMake();

	void brake();
	void accelerate();
};

