#include "StackArray.h"
using namespace std;

void StackArray::push(int num) {
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

int StackArray::pop() {
	if (isEmpty()) {
		throw runtime_error("Stack is empty!");
	}
	int* temp = new int[maxSize];
	*temp = buffer(temp);

	int popObj = temp[maxSize - 1];
	maxSize--;
	ptr = new int[maxSize];
	
	for (int i = 0; i < maxSize; i++) {
		ptr[i] = temp[i];
	}
	delete[] temp;
	return popObj;
}

int StackArray::peek() {
	return ptr[maxSize - 1];
}

bool StackArray::isEmpty() {
	if (maxSize == 0) return 1;
	else return 0;
}