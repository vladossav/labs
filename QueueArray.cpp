#define _CRT_SECURE_NO_WARNINGS
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

int QueueArray::pop() {
	if (isEmpty()) {
		throw runtime_error("Stack is empty!");
	}
	int* temp = new int[maxSize];
	*temp = buffer(temp);

	int popObj = temp[0];

	maxSize--;
	ptr = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		ptr[i] = temp[i + 1];
	}
	delete[]temp;
	return popObj;
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

char* QueueArray::toString() {
	char* string = new char[maxSize * 10];
	for (int i = 0; i < maxSize; i++) {

		int k = 0;
		int number = ptr[i];
		if (ptr[i] < 0) {
			k++;
			number = -ptr[i];
		}
		while (number > 0) {
			k++;
			number = number / 10;
		}
		char* buffer = new char[k];

		sprintf(buffer, "%d ", ptr[i]);
		if (i == 0) {
			strcpy(string, "Queue: ");
			strcat(string, buffer);
		}
		else {
			strcat(string, buffer);
		}

	}
	throw -3;
	return string;
}
