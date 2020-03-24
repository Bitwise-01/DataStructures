#pragma once
#include <string>
#include <iostream>

class Date
{
private:
	int day;
	int year;
	int month;
	std::string strMonth;

	int getMaxDays(int month);
	std::string getStrMonth(int month);
public:
	Date();
	Date(int inDay, int inMonth, int inYear);

	void displayShort();
	void displayLong();
	void displayGlobal();
};

