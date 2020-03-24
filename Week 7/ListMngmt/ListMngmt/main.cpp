#include <string>
#include <iostream>

// global constants
constexpr int KILL_CODE = -99;
constexpr unsigned int MAX_LIST = 5;

// structs
struct listType {
	int numbers[MAX_LIST];
	unsigned int indexer = 0;
};

void displayMenu();
int getMin(listType list);
int getMax(listType list);
bool isFull(listType list);
bool isEmpty(listType list);
int getListSize(listType list);
void displayList(listType list);
int search(listType list, int num);
void addNum(listType& list, int number);
void removeNum(listType& list, unsigned int index);

// main function
int main() {

	int userInput;
	listType list;

	do { // loop until user enter the kill code

		displayMenu();
		std::cout << "Enter an option or enter " << KILL_CODE << " to exit: ";
		std::cin >> userInput;

		if (userInput != KILL_CODE) {

			system("cls");
			switch (userInput)
			{

			case 1: // check if the list is full
				if (isFull(list)) {
					std::cout << "The list is full" << std::endl;
				}
				else {
					std::cout << "The list is not full" << std::endl;
				}
				break;

			case 2: // search the list
				int indexOfNum;
				int numToSearchFor;

				std::cout << "Enter the number to search for: ";
				std::cin >> numToSearchFor;

				// search for number in the list
				indexOfNum = search(list, numToSearchFor);

				if (indexOfNum != -1) { // means the number was found
					std::cout << "The index of the number " << numToSearchFor << " is " << indexOfNum << std::endl;
				}
				else {
					std::cout << "The number is not in the list" << std::endl;
				}
				break;

			case 3: // display min
				if (isEmpty(list)) {
					std::cout << "The list does not have any numbers" << std::endl;
				}
				else {
					std::cout << "The smallest number in the list is " << getMin(list) << std::endl;
				}
				break;

			case 4: // display max
				if (isEmpty(list)) {
					std::cout << "The list does not have any numbers" << std::endl;
				}
				else {
					std::cout << "The largest number in the list is " << getMax(list) << std::endl;
				}
				break;

			case 5: // check empty
				if (isEmpty(list)) {
					std::cout << "The list is empty" << std::endl;
				}
				else {
					std::cout << "The list is not empty" << std::endl;
				}
				break;

			case 6: // add to list
				int num;
				if (!isFull(list)) {
					std::cout << "Enter the number you would like to add into the list: ";
					std::cin >> num;
					addNum(list, num);
				}
				else {
					std::cout << "The list is full" << std::endl;
				}
				break;

			case 7: // display list
				displayList(list);
				break;

			case 8: // display list size
				std::cout << "The size of the list is " << getListSize(list) << std::endl;
				break;

			case 9: // empty the list
				list.indexer = 0;
				break;

			case 10: // remove a number from the list
				int index;
				displayList(list);
				std::cout << "\nEnter the index of the number you wish to remove: ";
				std::cin >> index;

				if (index >= 0 && index <= list.indexer) {
					removeNum(list, (unsigned)index);
				}
				else {
					std::cout << "Invalid index" << std::endl;
				}
				break;
			default:
				break;
			}

			system("pause");
		}

	} while (userInput != KILL_CODE);	

	system("pause");
	return 0;
}

// UI functions
void displayMenu() {
	
	system("cls");
	std::string menu[10] = {
		"IsFull", 
		"Search",
		"Get min",
		"Get max", 
		"IsEmpty",
		"Add a number", 
		"Display list",
		"Get list size", 
		"Empty the list", 
		"Remove a number", 
	};

	for (int n = 0; n < 5; n++) {
		std::cout << (n + 1) << ". " << menu[n];			
		std::cout << "\t " << (n + 6) << ". " << menu[n + 5];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void displayList(listType list) {
	for (unsigned int n = 0; n < list.indexer; n++) {
		if (!n) {
			std::cout << "Index: Number" << std::endl;
		}
		std::cout << n << ": " <<  list.numbers[n] << std::endl;
	}
}

// list functions
int getMin(listType list) {
	int currentMin;
	for (unsigned int n = 0; n < list.indexer; n++) {

		if (!n) { // currentMin is not assigned yet
			currentMin = list.numbers[n];
		}
		else {
			if (currentMin > list.numbers[n]) { // check if the currentMin > current number
				currentMin = list.numbers[n];
			}
		}

	}
	return currentMin;
}

int getMax(listType list) {
	int currentMax;

	if (isEmpty(list)) { // make sure the list isn't empty
		return -1;
	}
	else {
		for (unsigned int n = 0; n < list.indexer; n++) {

			if (!n) { // currentMax is not assigned yet
				currentMax = list.numbers[n];
			}
			else {
				if (currentMax < list.numbers[n]) { // check if the currentMax > current number
					currentMax = list.numbers[n];
				}
			}

		}
	}
	return currentMax;
}

bool isFull(listType list) {
	if (list.indexer < MAX_LIST) {
		return false;
	}
	else {
		return true;
	}
}

bool isEmpty(listType list) {
	if (list.indexer) {
		return false;
	}
	else {
		return true;
	}
}

int getListSize(listType list) {
	return list.indexer;
} 

int search(listType list, int num) {
	int n = 0; 
	bool isFound = false;

	while (!isFound && n < list.indexer) {
		if (list.numbers[n] == num) {
			isFound = true;
		}

		n += 1;
	}

	if (isFound) {
		return n; 
	}
	else {
		return -1;
	}
}

void addNum(listType& list, int number) {
	list.numbers[list.indexer] = number;
	list.indexer += 1;
}

void removeNum(listType& list, unsigned int index) {	
	for (unsigned int n = index; n < list.indexer; n++) {
		if ((n + 1) < list.indexer) { // make sure we aren't at the end of the list
			list.numbers[n] = list.numbers[n + 1];
		}
	}

	if (list.indexer) { // make sure the indexer isn't zero
		list.indexer -= 1;
	}
}