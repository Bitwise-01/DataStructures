#include <string>
#include <iostream>

bool isPalindromIter(std::string str);
bool isPalindromRec(std::string str, int lower, int upper);

int main() {

	std::string str;

	do {
		std::cout << "Enter a string or nothing to exit: ";
		std::getline(std::cin, str);

		if (str != "") {			
			// use Rec
			if (isPalindromRec(str, 0, str.size()-1)) {
				std::cout << str << " is palindrome" << std::endl;
			}
			else {
				std::cout << str << " is not palindrome" << std::endl;
			}
						
			// use Iter
			if (isPalindromIter(str)) {
				std::cout << str << " is palindrome" << std::endl;
			}
			else {
				std::cout << str << " is not palindrome" << std::endl;
			}
		}

	} while (str != "");

	system("pause");
	return 0;
}

bool isPalindromRec(std::string str, int lower, int upper) {
	if (str[lower] != str[upper]) {
		return false;
	}
	else {
		if (lower == upper) {
			if (str[lower] == str[upper]) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return isPalindromRec(str, lower + 1, upper - 1);
		}
	}
}

bool isPalindromIter(std::string str) {
	int lower = 0;
	int upper = str.size()-1;
	bool isPalindrome = true;

	while ((lower != upper) && isPalindrome) {
		if (str[lower] != str[upper]) {
			isPalindrome = false;
		} 
		
		lower += 1;
		upper -= 1;
	}

	return isPalindrome;
}