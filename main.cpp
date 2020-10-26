#include <iostream>
#include <ctime>
using namespace std;
#include "Header.h"

bool testAdd(ArrayWork & test) {
	srand((unsigned)time(0));
	int num = -100 + rand() % 100;
	test.add(num);
	int* ptr = test.getPtr();
	int n = test.getMaxSize();
	if (ptr[n - 1] == num) return 0;
	else return 1;
}

bool testReplace(ArrayWork& test) {
	int n = test.getMaxSize();
	srand((unsigned)time(0));
	int number = -100 + rand() % 100;
	int numPos=0+rand()% (test.getMaxSize() - 1);
	test.replace(numPos, number);
	int* ptr = test.getPtr();
	if (ptr[numPos] == number) return 0;
	else return 1;
}

bool testDelete(ArrayWork& test) {
	int *ptr= test.getPtr();
	int numPos = 0 + rand() % (test.getMaxSize() - 1);
	int temp = ptr[numPos];
	test.remove(numPos);
	ptr = test.getPtr();
	if (ptr[numPos] == temp) return 1;
	else return 0;
}

bool testSort(ArrayWork& test) {
	test.sort();
	int* ptr = test.getPtr();
	for (int i = 0; i < test.getMaxSize()-1; i++) {
		if (ptr[i + 1] < ptr[i]) return 1;
	}
	return 0;
}

bool testSearch(ArrayWork& test) {
	int n = test.getMaxSize();
	int* ptr = test.getPtr();
	srand((unsigned)time(0));
	int number = -100 + rand() % 100;
	if (test.search(number) == -1) return 0;
	if (test.search(number) >= 0 && test.search(number) < n) {
		if (ptr[test.search(number)] == number) return 0;
	}
	return 1;
}

void test(ArrayWork& mass) {
	cout << "--------- 0 - successful || 1 - failed ----------";
	cout << "\nÐåçóëüòàò òåñòà íà äîáàâëåíèå ýëåìåíòà: " << testAdd(mass);
	cout << "\n    Ðåçóëüòàò òåñòà íà çàìåíó ýëåìåíòà: " << testReplace(mass);
	cout << "\n  Ðåçóëüòàò òåñòà íà óäàëåíèå ýëåìåíòà: " << testDelete(mass);
	cout << "\n Ðåçóëüòàò òåñòà íà ñîðòèðîâêó ìàññèâà: " << testSort(mass);
	cout << "\n     Ðåçóëüòàò òåñòà íà ïîèñê ýëåìåíòà: " << testSearch(mass);
}

int main() {
	setlocale(LC_ALL, "Russian");
	ArrayWork mass1;
	cout << "Ïðîâåðêà ðàáîòû êîíñòðóêòîðà ïî óìîë÷àíèþ" << endl;
	test(mass1);

	int A[5] = { -100,2,0,-54,25 };
	ArrayWork mass2(5,A);
	cout << "\n\nÏðîâåðêà ðàáîòû êîíñòðóêòîðà ñ ïàðàìåòðàìè" << endl;
	test(mass2);
	
	return 0;
}
