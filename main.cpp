#include <iostream>
#include <ctime>
using namespace std;
#include "Header.h"

bool testOperPlus(ArrayWork mass1,ArrayWork mass2) {
	ArrayWork mass3 = mass1 + mass2;
	
	int* temp1 = new int[mass1.getMaxSize()];
	temp1 = mass1.getPtr();
	int* temp2 = new int[mass2.getMaxSize()];
	temp2 = mass2.getPtr();
	int* temp3 = new int[mass3.getMaxSize()];
	temp3 = mass3.getPtr();

	if (mass1.getMaxSize() < mass2.getMaxSize()) {
		if (mass2.getMaxSize() != mass3.getMaxSize()) return 1;
		for (int i = 0; i < mass1.getMaxSize(); i++) {
			if (temp3[i] != temp1[i] + temp2[i]) return 1;
		}
		for (int i = mass1.getMaxSize(); i < mass3.getMaxSize(); i++) {
			if (temp3[i] != temp2[i]) return 1;
		}
	}
	else {
		if (mass1.getMaxSize() != mass3.getMaxSize()) return 1;
		for (int i = 0; i < mass2.getMaxSize(); i++) {
			if (temp3[i] != temp1[i] + temp2[i]) return 1;
		}
		for (int i = mass2.getMaxSize(); i < mass3.getMaxSize(); i++) {
			if (temp3[i] != temp1[i]) return 1;
		}
	}

	return 0;
}

bool testOperMinus(ArrayWork mass1, ArrayWork mass2) {
	ArrayWork mass3 = mass1 - mass2;

	int* temp1 = new int[mass1.getMaxSize()];
	temp1 = mass1.getPtr();
	int* temp2 = new int[mass2.getMaxSize()];
	temp2 = mass2.getPtr();
	int* temp3 = new int[mass3.getMaxSize()];
	temp3 = mass3.getPtr();

	if (mass1.getMaxSize() < mass2.getMaxSize()) {
		if (mass2.getMaxSize() != mass3.getMaxSize()) return 1;
		for (int i = 0; i < mass1.getMaxSize(); i++) {
			if (temp3[i] != temp1[i] - temp2[i]) return 1;
		}
		for (int i = mass1.getMaxSize(); i < mass3.getMaxSize(); i++) {
			if (temp3[i] != temp2[i]) return 1;
		}
	}
	else {
		if (mass1.getMaxSize() != mass3.getMaxSize()) return 1;
		for (int i = 0; i < mass2.getMaxSize(); i++) {
			if (temp3[i] != temp1[i] - temp2[i]) return 1;
		}
		for (int i = mass2.getMaxSize(); i < mass3.getMaxSize(); i++) {
			if (temp3[i] != temp1[i]) return 1;
		}
	}
	return 0;
}

bool testOperIndex(ArrayWork mass1) {
	int* temp = new int[mass1.getMaxSize()];
	temp = mass1.getPtr();

	srand((unsigned)time(NULL));
	int num = -5 + rand() % (mass1.getMaxSize()+10);

	try {
		mass1[num];
	}
	catch(int ex) {
		return 1;
	}

	if (temp[num] == mass1[num]) return 0;
	else return 1;
}

bool testOperDecr(ArrayWork mass1) {
	int* temp = new int[mass1.getMaxSize()];
	temp = mass1.getPtr();

	--mass1;

	for (int i = 0; i < mass1.getMaxSize(); i++) {
		if (temp[i] - 1 != mass1[i]) return 1;
	}
	return 0;
}

bool testOperMinusNumber(ArrayWork mass1) {
	int* temp = new int[mass1.getMaxSize()];
	temp = mass1.getPtr();

	srand((unsigned)time(NULL));
	int num = 0 + rand() % mass1.getMaxSize();

	mass1 - num;

	for (int i = 0; i < num; i++) {
		if (mass1[i] != temp[i]) return 1;
	}
	for (int i = num; i < mass1.getMaxSize()-1; i++) {
		if (temp[i+1] != mass1[i]) return 1;
	}
	return 0;
}

bool testOperAssign(ArrayWork mass1) {
	ArrayWork mass3 = mass1;

	if (mass3.getMaxSize() != mass1.getMaxSize()) return 1;
	for (int i = 0; i < mass1.getMaxSize(); i++) {
		if (mass3[i] != mass1[i]) return 1;
	}
	return 0;
}

int main() { 
	const int N = 10;
	setlocale(LC_ALL, "Russian");
	int A[N] = { 1,25,3,33,5,-123,9999,0,-1000,543};

	ArrayWork mass1(N,A);
	ArrayWork mass2;

	cout << "-- 0 - Successfully || 1 - Failed --";
	cout << "\n Тест операции сложения объектов: " << testOperPlus(mass1, mass2);
	cout << "\nТест операции вычитания объектов: " << testOperMinus(mass1, mass2);
	cout << "\n    Тест операции индексирования: " << testOperIndex(mass1);
	cout << "\n        Тест операции декремента: " << testOperDecr(mass1);
	cout << "\n   Тест операции вычитания числа: " << testOperMinusNumber(mass1);
	cout << "\n      Тест операции присваивания: " << testOperAssign(mass1);
	return 0;
}