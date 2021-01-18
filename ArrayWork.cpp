#define _CRT_SECURE_NO_WARNINGS
#include "ArrayWork.h"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>

ArrayWork::ArrayWork() { 
	srand((unsigned)time(NULL));
	maxSize = 2+rand()%20;
	ptr = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		ptr[i] = -100+rand()%101;
	}
}

ArrayWork::ArrayWork(int maxSize0, int* ptr0) { 
	maxSize = maxSize0;
	ptr = new int[maxSize];
	for (int i=0; i < maxSize; i++) {
		ptr[i] = ptr0[i];
	}
}

int ArrayWork::nowCount = 0;

ArrayWork::~ArrayWork() {
	//delete[]ptr;
}

int ArrayWork::getMaxSize() {
	return maxSize;
}

int* ArrayWork::getPtr() {
	int* ptrCpy = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		ptrCpy[i] = ptr[i];
	}
	return ptrCpy;
}

char* ArrayWork::toString() {
	char* string = new char[maxSize*10];
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
		if (i == 0) strcpy(string, buffer);
		else
		strcat(string, buffer);
	}
	return string;
}

int ArrayWork::buffer(int *temp) {
	for (int i = 0; i < maxSize; i++) {
		temp[i] = ptr[i];
	}
	delete[]ptr;
	return *temp;
}

void ArrayWork::add(int num) {
	int* temp = new int[maxSize];
	*temp=buffer(temp);
	maxSize++;
	ptr = new int[maxSize];
	for (int i = 0; i < maxSize - 1; i++) {
		ptr[i] = temp[i];
	}
	ptr[maxSize-1]= num;
	delete[]temp;
}

void ArrayWork::remove(int numPos) {
	int* temp = new int[maxSize];
	*temp = buffer(temp);

	maxSize = maxSize - 1;
	ptr = new int[maxSize];
	for (int i = 0; i < numPos; i++) {
		ptr[i] = temp[i];
	}
	for (int i = numPos; i < maxSize; i++) {
		ptr[i] = temp[i + 1];
	}
	delete[]temp;
}

void ArrayWork::replace(int numPos, int number) {
	ptr[numPos] = number;
}

void ArrayWork::sort() {
	for (int j = 1; j < maxSize; j++)
		for (int i = 0; i < maxSize-1; i++)
			if (ptr[i] > ptr[i + 1]) {
				int x = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = x;
			}
}

int ArrayWork::search(int num) {
	for (int i = 0; i < maxSize; i++)
		if (ptr[i] == num) {
			return i;
	}
		return -1;
}

int ArrayWork::operator[](int index) {

	if (index < 0 || index >= maxSize)
		throw std::range_error("Exit for limits of array!");

	int temp;
	temp = ptr[index];

	return temp;
}

bool ArrayWork::operator<(const ArrayWork& other) const {
	return ptr<other.ptr;
}
