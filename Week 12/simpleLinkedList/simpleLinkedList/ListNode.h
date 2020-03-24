#pragma once

struct ListNode {
	double value;
	ListNode* nextNode;

	ListNode(double valueIn) {
		value = valueIn;
		nextNode = nullptr;
	};

	ListNode() {
		nextNode = nullptr;
	};
};
