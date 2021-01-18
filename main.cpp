#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
#include "ArrayWork.h"
#include <set>
#include <deque>
#include <algorithm>

//deque int 
double testAddDequeInt() {
	deque<int> q;
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.push_front(i);
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testDeleteDequeInt() {
	deque<int> q;
	for (int i = 0; i < 100000; i++) {
		q.push_front(i);
	}
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.pop_front();
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testFindDequeInt() {
	deque<int> q;
	for (int i = 0; i < 100000; i++) {
		q.push_front(i);
	}
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		if (q.at(i) == 50000) break;
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testSortDequeInt() {
	deque<int> q;
	for (int i = 0; i < 100000; i++) {
		q.push_front(i);
	}
	clock_t timeStart = clock();
	sort(q.begin(), q.end(), std::greater<int>());
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

//deque arr
double testAddDequeArr() {
	deque<ArrayWork> q;
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		int A[] = { i,i + 1 ,i + 2,i + 3,i + 4 };
		ArrayWork mass(5, A);
		q.push_front(mass);
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testDeleteDequeArr() {
	deque<ArrayWork> q;
	for (int i = 0; i < 100000; i++) {
		int A[] = { i,i + 1 ,i + 2,i + 3,i + 4 };
		ArrayWork mass(5, A);
		q.push_front(mass);
	}
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.pop_front();
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testFindDequeArr() {
	deque<ArrayWork> q;
	for (int i = 0; i < 100000; i++) {
		int A[] = { i,i + 1 ,i + 2,i + 3,i + 4 };
		ArrayWork mass(5, A);
		q.push_front(mass);
	}
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
			if (q.at(i).search(5000) != -1) break;
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testSortDequeArr() {
	deque<ArrayWork> q;
	for (int i = 0; i < 100000; i++) {
		int A[] = { i,i + 1 ,i + 2,i + 3,i + 4 };
		ArrayWork mass(5, A);
		q.push_front(mass);
	}
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.at(i).sort();
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

//set int
double testAddSetInt() {
	set<int> q;
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.insert(i);
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testDeleteSetInt() {
	set<int> q;
	for (int i = 0; i < 100000; i++) {
		q.insert(i);
	}
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.clear();
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testFindSetInt() {
	set<int> q;
	for (int i = 0; i < 100000; i++) {
		q.insert(i);
	}
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.find(50000);
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testSortSetInt() {
	set<int> q;

	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.insert(100000-i);
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

//set arr

double testAddSetArr() {

	set <ArrayWork> q;
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		int A[] = { i,i + 1,i + 2,i + 3,i + 4 };
		ArrayWork mass(5,A);
		q.insert(mass);
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testDelSetArr() {
	set <ArrayWork> q;
	for (int i = 0; i < 100000; i++) {
		int A[] = { i,i + 1,i + 2,i + 3,i + 4 };
		ArrayWork mass(5, A);
		q.insert(mass);
	}
	set<ArrayWork>::const_iterator it;
	it = q.begin();

	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		q.erase(it);
		it = q.begin();
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testFindSetArr() {
	set <ArrayWork> q;
	for (int i = 0; i < 100000; i++) {
		int A[] = { i,i + 1,i + 2,i + 3,i + 4 };
		ArrayWork mass(5, A);
		q.insert(mass);
	}
	int A[] = { 50000, 50001, 50002 , 50003 , 50004 };
	ArrayWork mass(5, A);
	clock_t timeStart = clock();
	q.find(mass);
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

double testSortSetArr() {
	set <ArrayWork> q;
	clock_t timeStart = clock();
	for (int i = 0; i < 100000; i++) {
		int A[] = { i+5,i + 8,i - 6,i + 2,i + 1 };
		ArrayWork mass(5, A);
		q.insert(mass);
	}
	clock_t timeEnd = clock() - timeStart;
	return (double)timeEnd / CLOCKS_PER_SEC;
}

int main() { 
	setlocale(LC_ALL, "Russian");

	cout << "Временной анализ";
	cout << "\nДвусторонняя очередь для типа <int>";
	cout << "\nДобавление: " << testAddDequeInt() <<" sec";
	cout << "\n  Удаление: " << testDeleteDequeInt() << " sec";
	cout << "\n     Поиск: " << testFindDequeInt()<< " sec";
	cout << "\nСортировка: " << testSortDequeInt()<<" sec";

	cout << "\n\nДвусторонняя очередь для типа <ArrayWork>";
	cout << "\nДобавление: " << testAddDequeArr()<< " sec";
	cout << "\n  Удаление: "<< testDeleteDequeArr()<< " sec";
	cout << "\n     Поиск: " << testFindDequeArr() << " sec";
	cout << "\nСортировка: " << testSortDequeArr() << " sec";

	cout << "\n\nМножество для типа <int>";
	cout << "\nДобавление: " << testAddSetInt()<< " sec";
	cout << "\n  Удаление: " << testDeleteSetInt()<<" sec";
	cout << "\n     Поиск: " << testFindSetInt()<<" sec";
	cout << "\nСортировка: " << testSortSetInt()<<" sec";

	cout << "\n\nМножество для типа <ArrayWork>";
	cout << "\nДобавление: "<< testAddSetArr() << " sec";
	cout << "\n  Удаление: "<< testDelSetArr() << " sec";
	cout << "\n     Поиск: " << testFindSetArr()<<" sec";
	cout << "\nСортировка: " << testSortSetArr()<<" sec";

	return 0;
}