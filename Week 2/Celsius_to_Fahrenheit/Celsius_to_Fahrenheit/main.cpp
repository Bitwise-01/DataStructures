/*
	Date: 09/10/18
	Author: Mohamed
	Description: Celsius to Fahrenheit
*/

#include <iostream>
double to_fahrenheit(double);

int main() {

	float fahrenheit; 

	for (double celsius = 0; celsius <= 30; celsius++) {
		fahrenheit = to_fahrenheit(celsius);
		std::cout << (celsius < 10 ? "0" : "") << celsius << "(c)" << " is " << fahrenheit << "(f)" << std::endl;
	}

	system("pause");
	return 0;
}

double to_fahrenheit(double celsius) {
	return ((9.0 / 5.0) * celsius) + 32;
}

/*

f = 9/5c + 32

*/