#include <string>
#include <iostream>

int countWords(char words[]);

int main() {

	std::string words;
	char c_words[512]; 

	std::cout << "Enter a sentence to count: ";
	std::getline(std::cin, words);

	if (words != "") {
		strcpy_s(c_words, words.c_str());
		std::cout << "\nThere are " << countWords(c_words) << " words in your sentence" << std::endl;
	}
	else {
		std::cout << "You must enter something for something to happen." << std::endl;
	}
		
	system("pause");
	return 0;
}

int countWords(char words[]) {
	int wordsCounted = 0; 
	unsigned int index = 0;

	while (words[index]) {

		if (index == 0) {
			wordsCounted += 1;
		}

		if (words[index] == ' ' && words[index + 1] != ' ') {
			wordsCounted += 1;
		}

		index += 1;
	}

	return wordsCounted;
}