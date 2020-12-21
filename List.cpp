#include "List.h"
#include "ArrayWork.h"
#include "QueueArray.h"
#include "StackArray.h"
#include <iostream>
using namespace std;

List::List() {
	head = tail = NULL;
	count = 0;
}

List::~List() {
	delAll();
}
void List::add(ArrayWork data) {
	Node* temp = new Node;
	if (head == NULL || tail == NULL) {
		temp->next = temp;
		temp->prev = temp;
		temp->data = data;
		head = tail = temp;
		count++;
		return;
	}
	temp->next = tail;
	temp->data = data;
	temp->prev = head;
	tail->prev = temp;
	head->next = temp;
	tail = temp;
	count++;
	return;
}

void List::insert(int pos, ArrayWork data) {
	if (pos < 1 || pos > count + 1) {
		throw runtime_error("Wrong position");
	}
	Node* temp = new Node;
	if (head == NULL || tail == NULL) {
		temp->next = temp;
		temp->prev = temp;
		temp->data = data;
		head = tail = temp;
		count++;
		return;
	}

	if (pos == 1 && head != NULL && tail != NULL) {
		temp->next = tail;
		temp->data = data;
		temp->prev = head;
		head->next = temp;
		tail->prev = temp;
		head = temp;
		count++;
		return;
	}

	if (pos == count + 1) {
		temp->next = tail;
		temp->data = data;
		temp->prev = head;
		tail->prev = temp;
		head->next = temp;
		tail = temp;
		count++;
		return;
	}

	int i = 1;
	Node* Ins = head;
	while (i < pos) {
		Ins = Ins->prev;
		i++;
	}
	Node* NextIns = Ins->next;
	NextIns->prev = temp;
	temp->next = NextIns;
	temp->prev = Ins;
	Ins->next = temp;
	temp->data = data;
	count++;
}

void List::viewAll() {
	if (count == 0) {
		throw runtime_error("List is empty");
	}
	Node* temp = head;
	for (int i = 1; i < count; i++) {
		cout<<temp->data.toString() << endl;
		temp = temp->prev;
	}
	cout<<temp->data.toString();
}

void List::view(int pos) {
	Node* temp;
	temp = head;
	int i = 1;

	while (i < pos) {
		temp = temp->prev;
		i++;
	}
	cout<<temp->data.toString();
}

void List::delAll() {
	while (count != 0)
		del(1);
}

void List::del(int pos) {
	if (pos < 1 || pos > count + 1) {
			throw runtime_error("Wrong position");
	}
	if (count == 1) {
		Node* del = head;
		delete del;
		count--;
		return;
	}

	if (pos == 1) {
		Node* del = head;
		Node* prevdel = del->prev;
		Node* nextdel = del->next;
		prevdel->next = nextdel;
		nextdel->prev = prevdel;
		head = prevdel;
		delete del;
		count--;
		return;
	}

	if (pos == count + 1) {
		Node* del = tail;
		Node* nextdel = del->next;
		Node* prevdel = del->prev;
		prevdel->next = nextdel;
		nextdel->prev = prevdel;
		head = nextdel;
		delete del;
		count--;
		return;
	}

	int i = 1;
	Node* del = head;
	while (i < pos) {
		del = del->prev;
		i++;
	}

	Node* prevdel = del->prev;
	Node* nextdel = del->next;
	prevdel->next = nextdel;
	nextdel->prev = prevdel;
	delete del;
	count--;
}

bool List::isEmpty() {
	if (count == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

ArrayWork List::getData(int pos) {
	Node* temp;
	temp = head;
	int i = 1;

	while (i < pos) {
		temp = temp->prev;
		i++;
	}
	return temp->data;
}

int List::search(int num) {
	Node* temp;
	temp = head;
	ArrayWork buff;
	for (int i = 1; i < count; i++) {
		buff = temp->data;

		if (buff.search(num) == -1)
			temp = temp->prev;
		else
			return i;
	}
	return -1;
}