#include <iostream>
#include <vector> 

class Queue {
private:
	std::vector<int> numbers;

public:
	void put(int);
	int get(int);
	int get_min();
	int get_max();
};

int main() {

	int number;
	Queue numbers;
	bool is_alive = true;
	const int EXIT = -99;

	while (is_alive) {
		std::cout << "Enter any number or enter " << EXIT << " to exit: " << std::flush;		std::cin >> number;

		if (number != EXIT)
			numbers.put(number);
		else
			is_alive = false;
	}

	std::cout << "Min: " << numbers.get_min() << std::endl;
	std::cout << "Max: " << numbers.get_max() << std::endl;

	system("pause");
	return 0;
}

void Queue::put(int num) {
	numbers.push_back(num);
}

int Queue::get(int index) {
	return (index < 0 || index > this->numbers.size()) ? 0 : this->numbers[index];
}

int Queue::get_min() {
	int current_min = this->numbers[0];
	int current_num;

	for (unsigned int n = 0; n < this->numbers.size(); n++) {
		current_num = this->numbers[n];

		if (current_num < current_min) {
			current_min = current_num;
		}
	}
	return current_min;
}    

int Queue::get_max() {
	int current_max = this->numbers[0];
	int current_num;

	for (unsigned int n = 0; n < this->numbers.size(); n++) {
		current_num = this->numbers[n];

		if (current_num > current_max) {
			current_max = current_num;
		}
	}
	return current_max;
}