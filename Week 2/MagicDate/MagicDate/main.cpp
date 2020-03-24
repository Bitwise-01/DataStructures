/*
	Date: 09/12/2018
	Author: Mohamed
	Description: Magic dates
*/

#include <iostream>

// ints
int get_month();
int get_date();
int get_year();

// booleans 
bool is_magic_date(int, int, int);
bool is_valid_date(unsigned short int);
bool is_valid_year(unsigned short int); 
bool is_valid_month(unsigned short int);

int main() {

	// user input
	int month = get_month();
	int date = get_date();
	int year = get_year();

	// output 
	std::cout << ((is_magic_date(month, date, year)) ? "\nThat is a magic date" : "\nThat is not a magic date") << std::endl;

	// pause 
	system("pause");

	return 0;
}

int get_month() {
	bool is_valid = false;
	unsigned short int month;

	while (!is_valid) {
		try {
			std::cout << "Enter the month: " << std::flush;
			std::cin >> month;

			if (is_valid_month(month))
				is_valid = true;
			else
				std::cout << std::endl;
		}
		catch (...) {}
	}
	return month;
}

int get_year() {
	bool is_valid = false;
	unsigned short int year;

	while (!is_valid) {
		try {
			std::cout << "Enter the last 2 digits of the year: " << std::flush;
			std::cin >> year;

			if (is_valid_year(year))
				is_valid = true;
			else
				std::cout << std::endl;
		}
		catch (...) {}
	}
	return year;
}

int get_date() {
	bool is_valid = false;
	unsigned short int date;

	while (!is_valid) {
		try {
			std::cout << "Enter the date: " << std::flush;
			std::cin >> date;

			if (is_valid_date(date))
				is_valid = true;
			else
				std::cout << std::endl;
		}
		catch (...) {}
	}
	return date;
}

bool is_valid_date(unsigned short int date) {
	return (date && date <= 31) ? true : false;
}

bool is_valid_year(unsigned short int year) {
	return (year) ? true : false;
}

bool is_valid_month(unsigned short int month) {
	return (month && month <= 12) ? true : false;
}

bool is_magic_date(int month, int date, int year) {
	return ((date * month) == year) ? true : false;
}