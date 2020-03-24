#include "stack.h"

Stack::Stack() {
	sSize = 0;
}

Stack::~Stack() {
}

void Stack::add(char item) {
	stack[sSize] = item;
	sSize += 1;
}

char Stack::pop() {
	return getChar();
}

char Stack::getChar() {
	char item;

	if (sSize > 0) {
		item = stack[sSize - 1];
		sSize -= 1;
	}
	else {
		item = '1';
	}

	return item;
}

bool Stack::isEmpty() {
	return (sSize == 0);
}