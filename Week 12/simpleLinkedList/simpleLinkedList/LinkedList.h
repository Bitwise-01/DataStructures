#pragma once
#include "ListNode.h"

class LinkedList
{
private: 
	ListNode* head;

public:
	LinkedList();
	
	void add(double x);
	bool isMember(double x);
};