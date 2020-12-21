#pragma once
#include "ArrayWork.h"

class QueueArray : public ArrayWork {
public:
	QueueArray() : ArrayWork() {}
	QueueArray(int maxSize0, int* ptr0) : ArrayWork(maxSize0, ptr0) {}

	void push(int num);
	int pop();
	int front();
	int back();
	bool isEmpty();

	~QueueArray() {}
};