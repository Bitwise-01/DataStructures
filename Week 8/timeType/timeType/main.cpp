#include <iostream>

struct timeType {
	int sec; //0..59
	int min; //0..59
	int hrs; //0..23
};//end struct timeType

timeType timeAdd(timeType t1, timeType t2);
void displayTime(timeType t);

int main() {
	timeType t1, t2, t3;

	std::cout << "Enter hrs min sec for time 1: ";
	std::cin >> t1.hrs >> t1.min >> t1.sec;

	std::cout << "Enter hrs min sec for time 2: ";
	std::cin >> t2.hrs >> t2.min >> t2.sec;

	t3 = timeAdd(t1, t2);
	displayTime(t3);

	system("pause");
	return 0;
}


timeType timeAdd(timeType t1, timeType t2) {
	timeType temp;

	temp.sec = t1.sec + t2.sec;
	temp.min = t1.min + t2.min;
	temp.hrs = t1.hrs + t2.hrs;
	
	/* reset, carry section */
	if (temp.sec >= 60) {
		temp.min += (temp.sec / 60);
		temp.sec = (temp.sec - ((int)(temp.sec / 60) * 60)); 
	}
	
	if (temp.min >= 60) {
		temp.hrs += (temp.min / 60);
		temp.min = (temp.min - ((int)(temp.min / 60) * 60));
	}

	if (temp.hrs >= 24) {
		temp.hrs = (temp.hrs - ((int)(temp.hrs / 24) * 24));
	}

	return temp;
}//end time add

void displayTime(timeType t)
{
	std::cout << "\nThe time is: " << t.hrs << " hrs, " << t.min << " min, " << t.sec << " sec.\n";
}
