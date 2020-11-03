#include "Header.h"
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

bool testTxtRecord(ArrayWork& test1) {
	ArrayWork test2;
	fstream flow;
	flow.open("testwork.txt", fstream::out | fstream::app);
	if (!flow.is_open()) {
		return 1;
	}
	else flow << test1;
	flow.close();

	flow.open("testwork.txt", fstream::in);
	if (!flow.is_open()) {
		return 1;
	}
	else flow >> test2;
	flow.close();

	if (test1.getMaxSize() != test2.getMaxSize()) return 1;
	for (int i = 0; i < test1.getMaxSize(); i++) {
		if (test2[i] != test1[i]) return 1;
	}
	
	return 0;
}

bool testTxtEmptyRead () {
	ArrayWork testExit1;
	fstream flow;
	flow.open("testworkEmpty.txt", fstream::in);
	if (!flow.is_open()) {
		return 1;
	}
	else {
		try {
			flow >> testExit1;
		}
		catch (runtime_error) {
			return 1;
		}
	}
	flow.close();

	remove("testworkEmpty.txt");
	return 0;
}

bool testDat(ArrayWork test1) {

	char name[] ="testDat.dat";
	ArrayWork buff;
	try {
		test1.writeFile(name);
		buff.readFile(name);
	}
	catch (runtime_error) {
		return 1;
	}

	if (test1.getMaxSize() != buff.getMaxSize()) return 1;
	for (int i = 0; i < test1.getMaxSize(); i++) {
		if (buff[i] != test1[i]) return 1;
	}

	remove(name);
	return 0;
}

bool testDatEmpty() {
	char name[] = "testDatEmpty.dat";
	ArrayWork buff;
	try {
		buff.readFile(name);
	}
	catch (runtime_error) {
		return 1;
	}

	return 0;
}

int main() { 
	const int N = 10;
	setlocale(LC_ALL, "Russian");
	int A[N] = { 1,25,3,33,5,-123,9999,0,-1000,543};

	ArrayWork test1(N, A);
	cout << "              0 Successfully || 1 Failed";
	cout << "\n----------------------------TXT test";
	cout << "\n          Тест записи/чтения объекта: "<<testTxtRecord(test1);
	cout << "\nТест чтения объекта из пустого файла: "<<testTxtEmptyRead();
	cout << "\n----------------------------DAT test";
	cout << "\n          Тест записи/чтения объекта: " << testDat(test1);
	cout << "\nТест чтения объекта из пустого файла: " << testDatEmpty();
	return 0;
}