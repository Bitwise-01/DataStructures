#include "ListNode.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
}

void LinkedList::add(double x) {
	if (head != nullptr) {
		if (head->nextNode != nullptr) {
			ListNode* newNode = new ListNode(x);

			newNode->nextNode = head->nextNode;
			head->nextNode = newNode;
		}
		else {
			head->nextNode = new ListNode(x);
		}
	}
	else {
		head = new ListNode(x);
	}
}

bool LinkedList::isMember(double numIn) {
	bool isFound = false;
	bool isLastNode = false;
	ListNode* node = head;

	while (!isFound && !isLastNode) {

		if (node->value == numIn) {
			isFound = true;
		}
		else {
			if (node->nextNode != nullptr) {
				node = node->nextNode;
			}
			else {
				isLastNode = true;
			}
		}

	}

	return isFound;
}