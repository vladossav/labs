#include "ArrayWork.h"
#include "StackArray.h"
#include "QueueArray.h"
#include <iostream>
#include <ctime>
using namespace std;

bool testPush(StackArray test) {
	int N = 7583;
	test.push(N);
	if (test[test.getMaxSize() - 1] == N) return 0;
	else return 1;
}

bool testPop(StackArray test) {
	try {
		test.pop();
	}
	catch (runtime_error) {
		return 1;
	}
	return 0;
}

bool testLast(StackArray test) {
	if (test.peek() == test[test.getMaxSize() - 1]) return 0;
	else return 1;
	}

bool testAdd(QueueArray test) {
	int N = 7583;
	test.push(N);
	if (test[test.getMaxSize() - 1] == N) return 0;
	else return 1;
}

bool testDel(QueueArray test) {
	try {
		test.pop();
	}
	catch (runtime_error) {
		return 1;
	}
	return 0;
}

int main() { 
	setlocale(LC_ALL, "Russian");
	
	StackArray test1;
	StackArray test2(0, NULL);
	QueueArray test3;

	cout << "  0 Successfully || 1 Failed";
	cout << "\nДобавление элемента в стек: "<<testPush(test1);
	cout << "\nУдаление из стека: "<< testPop(test1);
	cout << "\nУдаление из пустого стека: " << testPop(test2);
	cout << "\nТекущий элемент стека: "<< testLast(test1);
	cout << "\nДобавление элемента в очередь: " << testAdd(test3);
	cout << "\nУдаление из очереди: " << testDel(test3);
	return 0;
}