#include "Date.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 2001;
}

Date::Date(int inMonth, int inDay, int inYear) {

	if((inMonth > 0) && (inMonth <= 12)) {
		month = inMonth;
	}
	else {
		month = 1;
	}
	
	strMonth = getStrMonth(month);

	if ((inDay > 0) && (inDay <= getMaxDays(month))) { 
		day = inDay;
	}
	else {
		day = 1;
	}

	if (inYear > 0) {
		year = inYear;
	}
	else {
		year = 2001;
	}
}

int Date::getMaxDays(int month) {	
	if (month == 1) {
		return 31;
	}
	else if (month == 2) {
		return 29;
	}
	else if (month == 3) {
		return 31;
	}
	else if (month == 4) {
		return 30;
	}
	else if (month == 5) {
		return 31;
	}
	else if (month == 6) {
		return 30;
	}
	else if (month == 7) {
		return 31;
	}
	else if (month == 8) {
		return 31;
	}
	else if (month == 9) {
		return 30;
	}
	else if (month == 10) {
		return 31;
	}
	else if (month == 11) {
		return 30;
	}
	else if (month == 12) {
		return 31;
	}
}

std::string Date::getStrMonth(int month) {
	
	if (month == 1) {
		return "January";
	}
	else if (month == 2) {
		return "February";
	}
	else if (month == 3) {
		return "March";
	}
	else if (month == 4) {
		return "April";
	}
	else if (month == 5) {
		return "May";
	}
	else if (month == 6) {
		return "June";
	}
	else if (month == 7) {
		return "July";
	}
	else if (month == 8) {
		return "August";
	}
	else if (month == 9) {
		return "September";
	}
	else if (month == 10) {
		return "October";
	}
	else if (month == 11) {
		return "November";
	}
	else {
		return "December";
	}

}

void Date::displayShort() {
	std::cout << month << "/" << day << "/" << year << std::endl;
}

void Date::displayLong() {
	std::cout << strMonth << " " << day << ", " << year << std::endl;
}

void Date::displayGlobal() {
	std::cout << day << " " << strMonth << " " << year << std::endl;
}