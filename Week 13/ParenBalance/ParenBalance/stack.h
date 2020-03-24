#pragma once

const unsigned int size = 100;

class Stack
{
private:
	char getChar();
	char stack[size];
	unsigned int sSize;	

public:
	Stack();
	~Stack();

	char pop();
	bool isEmpty();
	void add(char item);
};
