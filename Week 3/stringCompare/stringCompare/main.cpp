#include <string>
#include <iostream>

std::string upperCaseIt(std::string letter);
bool isUpper(std::string letter, std::string* uppercases);
bool sameString(std::string string1, std::string string2);
unsigned int getIndex(std::string letter, std::string* letters);

int main() {
	
	std::string name1;
	std::string name2;

	std::cout << "Enter name1: " << std::flush;
	std::cin >> name1;

	std::cout << "Enter name2: " << std::flush;
	std::cin >> name2;

	if (sameString(name1, name2)) {
		std::cout << "\nThe names are the same" << std::endl;
	}
	else {
		std::cout << "\nThe names are not the same" << std::endl;
	}

	system("pause");
	return 0;
}

bool sameString(std::string string1, std::string string2) {
	std::string letter1;
	std::string letter2;

	for (unsigned int n = 0; n < string1.size(); n++) {
		letter1 = string1[n];
		letter2 = string2[n];

		if (upperCaseIt(letter1) != upperCaseIt(letter2)) {
			return false;
		}
	}

	return true;
}

bool isUpper(std::string letter, std::string* uppercases) {
	bool is_upper = false;
	for (unsigned int n = 0; n < 26; n++) {		
		if (uppercases[n] == letter)
			is_upper = true;
	}
	return is_upper;
}

unsigned int getIndex(std::string letter, std::string* letters) {
	unsigned index;
	for (unsigned int n = 0; n < 26; n++) {
		if (letters[n] == letter)
			index = n;
	}
	return index;
}

std::string upperCaseIt(std::string letter) {
	std::string lower[] = {
		"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
		"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
	};

	std::string upper[] = {
		"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
		"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
	};

	unsigned int index = (isUpper(letter, upper)) ? getIndex(letter, upper) : getIndex(letter, lower);
	return upper[index];
}