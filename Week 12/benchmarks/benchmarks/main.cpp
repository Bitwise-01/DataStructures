#include <time.h>           
#include <iostream>

int randInt(int max);
int benchmarkLinearSearch(int list[], int size);
int benchmarkBinarySearch(int list[], int size);
int binarySearch(int list[], int size, int num);
int linearSearch(int list[], int size, int num);

int main() {

	srand(time(NULL)); // random number seed
	int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	int size = sizeof(list) / sizeof(int);
	std::cout << "Binary search average: " << benchmarkBinarySearch(list, size) << std::endl;
	std::cout << "Linear search average: " << benchmarkLinearSearch(list, size) << std::endl;

	/*
	while (person.isAlive) {
		person.eat();
		
		if (person.isBored) {
			person.createDrama();
		}

		person.sleep();
	}
	*/
	
	system("pause");
	return 0;
}

int linearSearch(int list[], int size, int num) {
	int count = 0;
	
	for (int n = 0; n < size; n++) {
		count += 1;

		if (list[n] == num) {
			return count;
		}		
	}

	return -1;
}

int binarySearch(int list[], int size, int num)
{
	int mid;
	int start = 0;
	int count = 0;
	int end = size-1;

	while (start <= end)
	{
		count += 1;
		mid = (start + end) / 2;
		if (list[mid] == num) {
			return count;
		}
		else {
			if (num > list[mid]) {
				start = mid + 1;
			}
			else if (num < list[mid]) {
				end = mid - 1;
			}
		}
	}

	return -1;
}

int benchmarkLinearSearch(int list[], int size) {
	int num;
	int tries;
	int sum = 0;
	int linearSearchResults[1000];

	for (int n = 0; n < 1000; n++) {
		num = randInt(size);
		tries = linearSearch(list, size, num);
		linearSearchResults[n] = tries;
	}

	for (int n = 0; n < 1000; n++) {
		sum += linearSearchResults[n];
	}

	return sum / 1000;
}

int benchmarkBinarySearch(int list[], int size) {
	int num; 
	int tries;
	int sum = 0;
	int binarySearchResults[1000];

	for (int n = 0; n < 1000; n++) {
		num = randInt(size);
		tries = binarySearch(list, size, num);
		binarySearchResults[n] = tries;
	}

	for (int n = 0; n < 1000; n++) {
		sum += binarySearchResults[n];
	}
	
	return sum / 1000;
}

int randInt(int max) {
	int randInts[100];

	for (int n = 0; n < 100; n++) {
		if (rand() % 3) {
			randInts[n] = rand() % max;
		}
		else {
			randInts[n] = (rand() % max) + 1;
		}
	}

	return randInts[rand() % 100];
}