#pragma once
#include "ArrayWork.h"

class StackArray : public ArrayWork {
public:
	StackArray() : ArrayWork() {}
	StackArray(int maxSize0, int* ptr0) : ArrayWork(maxSize0, ptr0) {}

	void push(int num);
	int pop();
	int peek();
	bool isEmpty();
	char* toString();

	~StackArray() {}
};