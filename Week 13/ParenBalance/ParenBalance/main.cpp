#include <string>
#include <fstream>
#include "stack.h"
#include <iostream>

bool isValid(std::string expr);

int main() {
	std::string file = "C:\\Users\\Mohamed\\Desktop\\exp.txt";
	std::ifstream infile; 
	infile.open(file);
	std::string expr;	

	while (std::getline(infile, expr)) {
		if (isValid(expr)) {
			std::cout << expr << " is valid " << std::endl;
		}
		else {
			std::cout << expr << " is invalid " << std::endl;
		}
	}
	
	system("pause");
	return 0;
}

bool isValid(std::string expr) {

	char item;
	Stack stack;
	unsigned int index = 0;
	bool isValidExpr = true;

	while (expr[index] && isValidExpr) {

		item = expr[index];

		if (item == '(') {
			stack.add(item);
		} 
		
		if(item == ')' ) {			
			if (stack.pop() == '1') {
				isValidExpr = false;
			}
		}

		index += 1;
	}
	
	if (!stack.isEmpty() && isValidExpr) {
		isValidExpr = false;
	}

	return isValidExpr;
}