#include "ArrayWork.h"
#include <iostream>
#include <fstream>

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

int ArrayWork::operator[](int index) {

	if (index < 0 || index >= maxSize)
		throw std::range_error("Exit for limits of array!");

	int temp;
	temp = ptr[index];
	
	return temp;
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

std::ostream& operator << (std::ostream& os, ArrayWork& obj) {
	os <<"("<<obj.maxSize<<") "<< obj.toString();
	return os;
}

#include <cstdlib>
std::istream& operator>>(std::istream& is, ArrayWork& obj) {
	if (is.peek() == EOF) throw std::runtime_error("No elements to read!");

	char* buff=new char[10];
	char c;

	while (is.get(c)) {
		if (c == '(') break;
		if (is.peek() == EOF) return is;
	}
	is.get(buff, 10, ')');
	is.ignore(2);
	int value = atoi(buff); //maxSize
	delete[]buff;

	obj.maxSize = value;
	delete[]obj.ptr;
	obj.ptr = new int[value];

	//std::cout << "\n(" << value << ")"; //check maxsize
	
	for (int i = 0; i < value; i++) {
		int flag = 0;
		int s = 0;
		while (is.get(c)) {
			if (c == ' ') break;
			if (c == '-') flag = 1;
			s = s * 10;
			if (c-'0'>=0 && c-'0' <=9) s = s + (c - '0');
		}
		if (flag == 1) s = -s;

	 //std::cout << s<<" "; //check ptr[]

	 obj.ptr[i] = s;		
	}
	
	return is;
}

bool ArrayWork::operator == (const ArrayWork& other) {
	if (this->maxSize != other.maxSize) {
		return 0;
	}
	for (int i = 0; i < this->maxSize; i++) {
		if (this->ptr[i] != other.ptr[i]) {
			return 0;
		}
	}
	return 1;
}