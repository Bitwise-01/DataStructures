#include <iostream>

int getAvg(int* scores, int size);
void getScores(int* scores, int size);
void pSort(int* scores, int size);

int main() {

	int avg;
	int size;
	
	std::cout << "Enter the amount of test to enter: ";
	std::cin >> size;

	int* scores = new int[size];
	int* pScore = scores;

	// user input
	getScores(scores, size);

	// magical stuff
	pSort(scores, size);
	avg = getAvg(scores, size);

	// display list 
	std::cout << "\nScores" << std::endl;
	for (int n = 0; n < size; n++) {
		std::cout << *pScore << std::endl;
		pScore += 1;
	}

	// display average 
	std::cout << "Average score: " << avg << std::endl;
	
	delete[] scores;
	system("pause");
	return 0;
}

void getScores(int* scores, int size) {
	int index = 0;
	int userInput;
	int *p = scores;

	while (index < size) {

		std::cout << "Enter a score: "; 
		std::cin >> userInput;

		if (userInput >= 0) { 
			*p = userInput;
			index += 1;
			p += 1;
		}

	}	
}

void pSort(int* scores, int size) {

	// Selection Sort

	int tmpNum;
	int* pLowestNum;
	int* pCurrentNum;
	int* pScore = scores;

	for (int n = 0; n < size;  n++) {

		pLowestNum = pScore;
		pCurrentNum = pScore;

		for (int i = n; i < size; i++) {
			if (*pLowestNum > *pCurrentNum) {
				pLowestNum = pCurrentNum;
			}

			pCurrentNum += 1;
		}

		tmpNum = *pLowestNum;
		*pLowestNum = *pScore;
		*pScore = tmpNum;
		 pScore += 1;
	}

}

int getAvg(int* scores, int size) {
	int total = 0;
	int* pScore = scores;

	for (int n = 0; n < size; n++) {
		total += *pScore;
		pScore += 1;
	}

	return (total / size);
}