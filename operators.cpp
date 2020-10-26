#include "Header.h"
#include <iostream>

ArrayWork operator+(ArrayWork& a, ArrayWork& b) {
	if (b.maxSize > a.maxSize) {
		ArrayWork c(b.maxSize, b.ptr);
			for (int i = 0; i < a.maxSize; i++) {
				c.ptr[i] = c.ptr[i] + a.ptr[i];
			}
			return c;
		}
	else {
		ArrayWork c(a.maxSize, a.ptr);
		for (int i = 0; i < b.maxSize; i++) {
			c.ptr[i] = c.ptr[i] + b.ptr[i];
		}
		return c;
	}
}

ArrayWork operator-(ArrayWork& a, ArrayWork& b) {
	if (b.maxSize > a.maxSize) {
		ArrayWork c(b.maxSize, b.ptr);
		for (int i = 0; i < a.maxSize; i++) {
			c.ptr[i] = a.ptr[i] - c.ptr[i];
		}
		return c;
	}
	else {
		ArrayWork c(a.maxSize, a.ptr);
		for (int i = 0; i < b.maxSize; i++) {
			c.ptr[i] = c.ptr[i] - b.ptr[i];
		}
		return c;
	}
}

int& ArrayWork::operator[](int index) {
	if (index >= maxSize) {
		index = index % maxSize;
	}

	int* ptrCpy = new int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		ptrCpy[i] = ptr[i];
	}
	
	return ptrCpy[index];
}

ArrayWork& ArrayWork::operator--() {
	for (int i = 0; i < this->maxSize; i++) {
		--this->ptr[i];
	}
	return *this;
}

ArrayWork& ArrayWork::operator-(int b) {
	if (b < 0) b = -b;
	for (;;) {
		if (b < this->maxSize) {
			int* temp = new int[maxSize];
			*temp = buffer(temp);

			maxSize = maxSize - 1;
			this->ptr = new int[maxSize];
			for (int i = 0; i < b; i++) {
				this->ptr[i] = temp[i];
			}
			for (int i = b; i < maxSize; i++) {
				this->ptr[i] = temp[i + 1];
			}
			delete[]temp;
			return *this;
			}
		else b = b % maxSize;
	}
}

ArrayWork& ArrayWork::operator=(const ArrayWork& other) {
	this->maxSize = other.maxSize;
	if (this->ptr != nullptr) {
		delete[] this->ptr;
	}
	this->ptr = new int[other.maxSize];
	for (int i = 0; i < other.maxSize; i++) {
		this->ptr[i] = other.ptr[i];
	}
	return *this;
}
