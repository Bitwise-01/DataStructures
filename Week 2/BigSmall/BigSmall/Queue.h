#pragma once
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
