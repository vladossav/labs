#include "List.h"
#include "ArrayWork.h"
#include "StackArray.h"
#include "QueueArray.h"
#include <iostream>
#include <ctime>
using namespace std;

bool testAdd() {	
	List list;
	ArrayWork obj1;
	list.add(obj1);
	if (list.getData(1) == obj1) return 0;
	else return 1;
}

bool testInsert() {
	int A[] = { 8,-2,56,4 };
	List list;
	StackArray obj(4, A);
	StackArray obj1;
	QueueArray obj2;
	ArrayWork obj3;
	list.add(obj1);
	list.add(obj2);
	list.add(obj3);
	list.insert(2, obj);
	if (list.getData(2) == obj)
		if (list.getData(3) == obj2)
			return 0;		
	return 1;
}

bool testEmpty() {
	List list;
		if (list.isEmpty() != 0) return 1;
	ArrayWork obj;
	list.add(obj);
	if (list.isEmpty() != 1) return 1;
	return 0;
}

bool testDelete() {
	List list;
	ArrayWork obj;
	StackArray obj1;
	QueueArray obj2;
	list.add(obj1);
	list.add(obj);
	list.add(obj2);
	list.del(2);
	if (!(list.getData(1) == obj1)) return 1;
	if (!(list.getData(2) == obj2)) return 1;
	return 0;
}

bool testSearch() {
	List list;
	int A[] = { 8,-2,77777,4 };
	ArrayWork obj1;
	StackArray obj2(4,A);
	QueueArray obj3;
	list.add(obj1);
	list.add(obj2);
	list.add(obj3);
	
	if (list.search(77777) != 2) return 1;
	if (list.search(91919119) != -1) return 1;
	return 0;
}

int main() { 
	setlocale(LC_ALL, "Russian");
	
	cout << "  0 Successfully || 1 Failed";
	cout << "\ntest add: " << testAdd();
	cout << "\ntest insert: " << testInsert();
	cout<< "\ntest empty: " << testEmpty();
	cout << "\ntest del: " << testDelete();
	cout << "\ntest search: " << testSearch();
	cout << endl;

	return 0;
}