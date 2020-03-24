#include <iostream>

void getScore(int& scores);
void add(int score, int lowestScore, int& total, bool& is_found);
int findLowest(int score1, int score2, int score3, int score4, int score5);
void calcAverage(int score1, int score2, int score3, int score4, int score5);
int getTotal(int score1, int score2, int score3, int score4, int score5, int lowestScore);

int main() {

	double score;
	int score1, score2, score3, score4, score5;

	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);
		
	std::cout << "Dropping: " << findLowest(score1, score2, score3, score4, score5) << std::endl;
	calcAverage(score1, score2, score3, score4, score5);
	system("pause");

	return 0;
}

void getScore(int& score) {
	bool is_valid = false;
	
	do {
		std::cout << "Enter a score: " << std::flush;
		std::cin >> score;

		if (score >= 0 && score <= 100) {
			is_valid = true;
		}

	} while (!is_valid);
}

void calcAverage(int score1, int score2, int score3, int score4, int score5) {
	int indexOfLowestScore = findLowest(score1, score2, score3, score4, score5);
	double total = getTotal(score1, score2, score3, score4, score5, indexOfLowestScore);
	double average = total / 4; 
	std::cout << "Average: " << average << std::endl;
}

void add(int score, int lowestScore, int& total, bool& is_found) {
	if (!is_found) {
		if (score != lowestScore)
			total += score;
		else
			is_found = true;
	}
	else {
		total += score;
	}
}

int getTotal(int score1, int score2, int score3, int score4, int score5, int lowestScore) {
	int total = 0;
	bool is_found = false;

	add(score1, lowestScore, total, is_found);
	add(score2, lowestScore, total, is_found);
	add(score3, lowestScore, total, is_found);
	add(score4, lowestScore, total, is_found);
	add(score5, lowestScore, total, is_found);

	return total;
}

int findLowest(int score1, int score2, int score3, int score4, int score5) {
	int lowest_score = score1;

	if (lowest_score > score2)
		lowest_score = score2;

	if (lowest_score > score3)
		lowest_score = score3;

	if (lowest_score > score4)
		lowest_score = score4;

	if (lowest_score > score5)
		lowest_score = score5;

	return lowest_score;	
}