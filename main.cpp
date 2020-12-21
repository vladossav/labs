#include "List.h"
#include "ArrayWork.h"
#include "StackArray.h"
#include "QueueArray.h"
using namespace std;

bool testInt() {
	List <int> list;
	int A[] = { -10,15,0,3999,67 };
	
	for (int i = 0; i < 5; i++) {
		list.add(A[i]);
	}
	for (int i = 0; i < 5; i++) {
		if (!(list.getData(i + 1) == A[i])) return 1;
	}
	return 0;
}

bool testDouble() {
	List <double> list;
	double A[] = { -10.54,15.32,0,3999.9223,67 };
	
	for (int i = 0; i < 5; i++) {
		list.add(A[i]);
	}
	for (int i = 0; i < 5; i++) {
		if (!(list.getData(i + 1) == A[i])) return 1;
	}
	return 0;
}

bool testArrayWork() {
	List <ArrayWork> list;
	int A[] = { -10,15,0,3999,67 };
	ArrayWork obj1(5,A);
	StackArray obj2;
	QueueArray obj3;

	list.add(obj1);
	list.add(obj2);
	list.add(obj3);
	if (!(list.getData(1) == obj1)) return 1;
	if (!(list.getData(2) == obj2)) return 1;
	if (!(list.getData(3) == obj3)) return 1;
	return 0;
}

int main() { 
	setlocale(LC_ALL, "Russian");
	
	cout << "  0 Successfully || 1 Failed";
	cout << "\ntest template <int>: "<<testInt();
	cout << "\ntest template <double>: " << testDouble();
	cout << "\ntest template <ArrayWork>: " << testArrayWork();
	cout << endl;

	return 0;
}