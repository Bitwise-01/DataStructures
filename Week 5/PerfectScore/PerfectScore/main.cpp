#include <iostream>

void getScores(double(&scores)[20]);
int countPerfect(double scores[], int size);

int main() {
	
	int perfectScores;
	double scores[20];

	getScores(scores);
	perfectScores = countPerfect(scores, 20);
	std::cout << "Perfect scores: " << perfectScores << std::endl;

	system("pause");
	return 0;
}

void getScores(double(&scores)[20]) {
	double score;
	int counter = 0;

	do {
		std::cout << "[" << counter + 1 << "] Enter a score or enter -99 to exit: ";
		std::cin >> score;

		if (score == -99) {
			counter = 20;
		}

		if (score >= 0 && score <= 100) {
			scores[counter] = score;
			counter += 1;
		}
	} while (counter < 20);
}

int countPerfect(double scores[], int size) {
	int perfectScores = 0;
	for (unsigned int n = 0; n < size; n++) {
		if (scores[n] == 100) {
			perfectScores += 1;
		}
	}
	return perfectScores;
}