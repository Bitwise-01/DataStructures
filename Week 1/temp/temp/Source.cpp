/*
	Date: 09/03/2018
	Author: Mohamed
	Description: Increases the average temp by 2 percent
*/

#define CHANGE_TEMP_AMNT 2.0 // the amount to increase the temperture by
#include <iostream>
#include <sstream>

const double get_percent(double, bool);
void display_data(std::string, double*);
double vary_temp(double*, const double*);

int main() {

	// convert amount into percentile
	const double AMNT = get_percent(CHANGE_TEMP_AMNT, true);

	// current average
	double denver_avg_temp = 88.0;
	double pheonix_avg_temp = 106.0;
	double new_york_city_avg_temp = 85.0;

	// new average
	double denver_new_avg_temp = vary_temp(&denver_avg_temp, &AMNT);
	double pheonix_new_avg_temp = vary_temp(&pheonix_avg_temp, &AMNT);
	double new_york_city_new_avg_temp = vary_temp(&new_york_city_avg_temp, &AMNT);

	// display data 
	display_data("Denver", &denver_new_avg_temp);
	display_data("Pheonix", &pheonix_new_avg_temp);
	display_data("New York City", &new_york_city_new_avg_temp);

	// pause
	std::cin.get();

	return 0;
}

void display_data(std::string city_name, double* temp) {
	std::cout << "The new average for " << city_name << " Would be: " << *temp << std::endl;
}

double vary_temp(double* current_temp, const double* amnt) {
	return (*current_temp) * (*amnt);
}

const double get_percent(double num, bool increase = true) {
	return increase ? (num / 100) + 1 : ((num / 100) - 1) * -1; 
}