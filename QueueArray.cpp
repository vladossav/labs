#include "QueueArray.h"
using namespace std;

void QueueArray::push(int num) {
	int* temp = new int[maxSize];
	*temp = buffer(temp);
	maxSize++;
	ptr = new int[maxSize];
	for (int i = 0; i < maxSize - 1; i++) {
		ptr[i] = temp[i];
	}
	ptr[maxSize - 1] = num;
	delete[]temp;
}

void QueueArray::pop() {
	if (isEmpty()) {
		throw runtime_error("Stack is empty!");
	}
	int* temp = new int[maxSize];
	*temp = buffer(temp);

	maxSize--;
	ptr = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		ptr[i] = temp[i + 1];
	}
	delete[]temp;
}

int QueueArray::front() {
	return ptr[0];
}

int QueueArray::back() {
	return ptr[maxSize - 1];
}

bool QueueArray::isEmpty() {
	if (maxSize == 0) return 1;
	else return 0;
}
