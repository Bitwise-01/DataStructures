#include <string>
#include <fstream>
#include <iomanip>  
#include <iostream>

bool isFormed(char s[]);
float strToFloat(std::string strIn, bool& isValid);

int main() {
	float n;
	bool isValid;
	std::string str;
	std::string inputfile;
	std::string outputFile = "C:\\Users\\Mohamed\\Desktop\\out.txt";

	std::cout << "Enter the file path: ";
	std::cin >> inputfile;

	std::ifstream infile;
	std::ofstream outfile;

	infile.open(inputfile);
	outfile.open(outputFile);

	while (infile >> str) {
		n = strToFloat(str, isValid);

		if (isValid) {

			outfile << str
				<< " converted to float is "
				<< std::fixed 
				<< std::showpoint 
				<< std::setprecision(1) 
				<< n 
				<< std::endl;

			std::cout << str
				<< " converted to float is " 
				<< std::fixed 
				<< std::showpoint 
				<< std::setprecision(1)
				<< n 
				<< std::endl;			
		}
		else {
			outfile << str << " can't be converted to a float" << std::endl;
			std::cout << str << " can't be converted to a float" << std::endl;	
		}
	}

	// close the files
	infile.close();
	outfile.close();
	
	system("pause");
	return 0;
}

float strToFloat(std::string str, bool& isValid) {
	char locS[100];
	isValid = false;
	bool formed = false;
	strcpy_s(locS, str.c_str());
	formed = isFormed(locS);

	float output;
	float sign = 1; // 1 is postive & -1 is negative. (1 * n) = n and (-1 * n) = -n
	float result = 0;

	bool containsDecimal = false;
	unsigned int indexer = 0;
	float decimalNum;
	int num;

	if (formed) {
		isValid = true;
		if (locS[indexer] == '-') {
			indexer += 1;
			sign = -1;
		}

		do {
			if (locS[indexer] == '.') {
				containsDecimal = true;
				decimalNum = static_cast<int>(locS[indexer + 1]) - static_cast<int>('0'); 
			}
			else {
				num = static_cast<int>(locS[indexer]) - static_cast<int>('0');  // convert char into a num and assign it to the variable num
				if (!containsDecimal) { // if the decimalpoint isn't found 
					if (num >= 0 && num <= 9) {
						result = (result * 10) + num;
					}
				}
			}

			indexer += 1;
		} while (locS[indexer]);

		if (containsDecimal) {
			decimalNum /= 10; // convert it into a decimal; dividing by 10 because we only moved one decimal place
			result += decimalNum; // and add the decimal point into the result
		}
		output = result * sign; // multiply it by the sign
	}
	else {
		output = 0.0f;
	}

	return output;
}

bool isFormed(char str[]) {

	// integers (+0, -0, 324.8, -324.0, etc.)
	int j = 0;
	bool _isFormed = true;
	int decimalPlaces = 0;
	bool decimalPointFound = false;
		
	if (str[0] == '\0') {
		_isFormed = false;
	}
	else if ((str[0] == '+') || (str[0] == '-')) { //leading sign

		if (str[1] == '\0') {//nothing after sign
			_isFormed = false;
		}
		else {
			j = 1;
			while (_isFormed && str[j]) {

				// after the decimalpoint is found
				if (decimalPointFound) { // when decimal point is found
					decimalPlaces += 1;

					if (decimalPlaces > 1) { // if there is more than one decimalplace
						_isFormed = false;
					}
					else {
						if (!((str[j] >= '0') && (str[j] <= '9'))) {
							_isFormed = false;
						}
					}
				}

				// before the decimal point is found
				if (str[j] != '.') { // when the current char isn't the a decimalpoint
					if (!decimalPointFound) {
						if (!((str[j] >= '0') && (str[j] <= '9'))) {
							_isFormed = false;
						}
					}
				}
				else { // when the current char is a decimalpoint
					decimalPointFound = true;
					if (str[j + 1] == '\0') { // when the char after the decimalpoint is the last char
						_isFormed = false;
					}
				}
				j++;
			}
		}
	}
	else
	{//no leading sign (+/-)
		while (_isFormed && str[j]) {	

			// after the decimalpoint is found
			if (decimalPointFound) { // when decimal point is found
				decimalPlaces += 1;

				if (decimalPlaces > 1) { // if there is more than one decimalplace
					_isFormed = false;
				}
				else {
					if (!((str[j] >= '0') && (str[j] <= '9'))) {
						_isFormed = false;
					}
				}
			}

			// before the decimal point is found
			if (str[j] != '.') { // when the current char isn't the a decimalpoint
				if (!decimalPointFound) {
					if (!((str[j] >= '0') && (str[j] <= '9'))) {
						_isFormed = false;
					}
				}
			}
			else { // when the current char is a decimalpoint
				decimalPointFound = true;
				if (str[j + 1] == '\0') { // when the char after the decimalpoint is the last char
					_isFormed = false;
				}
			}
			j++;
		}
	}
	return _isFormed;
}