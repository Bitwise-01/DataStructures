#include <iostream>
constexpr unsigned int max_size = 3;

int getSum(int nums[], int size);

int main() {
	
	int num;
	int total = 0;
	int nums[max_size];

	for (int n = 0; n < max_size; n++) {
		std::cout << "Enter a number: ";
		std::cin >> num;
		nums[n] = num;
	}

	std::cout << "Sum: " << (nums, max_size) << std::endl;
		
	system("pause");
	return 0;
}

int getSum(int nums[], int size) {
	if (size <= 0) {
		return 0;
	}
	else {
		return getSum(nums, size-1) + nums[size - 1];
	}
}