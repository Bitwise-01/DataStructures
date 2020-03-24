/*
	Date: 09/03/2018
	Author: Mohamed
	Description: A simple program that reports amount of paint needed
*/

#define PAINT_PER_SQR_FT 340.0 // the amount of the paint per square feet
#include <iostream>

class Fence {

private:
	double height;
	double length;
public:
	double get_height();
	double get_length();
	double total_space();
	Fence(double, double);
};

Fence::Fence(double height, double length):height(height), length(length) {}

double Fence::get_height() {
	return this->height;
}

double Fence::get_length() {
	return this->length;
}

double Fence::total_space() {
	return this->get_height() * this->get_length();
}

class FenceCompany {

private:
	Fence* fences;
	unsigned int total_fences;
public:
	double get_total_paint();
	FenceCompany(Fence*, unsigned int);
};

FenceCompany::FenceCompany(Fence* fences, unsigned int num_of_fences):fences(fences), total_fences(num_of_fences) {}

double FenceCompany::get_total_paint() {
	double total_space = this->fences[0].total_space() * this->total_fences;
	return total_space / PAINT_PER_SQR_FT;
}

int main() {

	/* fences */
	Fence fence_side1(6, 100); 
	Fence fence_side2(6, 100);
	Fence fences[] = { fence_side1, fence_side2 };
	FenceCompany fence_company(fences, sizeof(fences)/sizeof(Fence));

	/* total gallons of paint */
	double total_gallons_paint = fence_company.get_total_paint();

	/* display */
	std::cout << "The job requires approximately " << total_gallons_paint << " gallons of paint" << std::endl;
	std::cin.get();

	// ((6 * 100) * 2) / 340
	return 0;
}