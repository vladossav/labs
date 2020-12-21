#pragma once
#include <iostream>
#include "ArrayWork.h"
using namespace std;

template <typename T>
class List;

template <typename T>
class Node {
	friend class List<T>;
private:
	T data;
	Node<T>* next, * prev;
};

template <typename T>
class List {
private:
	Node<T>* head, * tail;
	int count;
public:
	List() {
		head = tail = NULL;
		count = 0;
	}
	~List() {
		delAll();
	}

	void add(T data) {
		Node<T>* temp = new Node<T>;
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

	void insert(int pos, T data) {
		if (pos < 1 || pos > count + 1) {
			throw runtime_error("Wrong position");
		}

		Node<T>* temp = new Node<T>;
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
		Node<T>* Ins = head;
		while (i < pos) {
			Ins = Ins->prev;
			i++;
		}
		Node<T>* NextIns = Ins->next;
		NextIns->prev = temp;
		temp->next = NextIns;
		temp->prev = Ins;
		Ins->next = temp;
		temp->data = data;
		count++;
	}

	void viewAll() {
		if (count == 0) {
			throw runtime_error("List is empty");
		}
		Node<T>* temp = head;
		for (int i = 1; i < count; i++) {
			cout << temp->data << endl;
			temp = temp->prev;
		}
		cout << temp->data << endl;
	}

	void view(int pos) {
		Node<T>* temp;
		temp = head;
		int i = 1;

		while (i < pos) {
			temp = temp->prev;
			i++;
		}
		cout << temp->data << endl;
	}

	void delAll() {
		while (count != 0)
			del(1);
	}

	void del(int pos) {
		if (pos < 1 || pos > count + 1) {
			throw runtime_error("Wrong position");
		}
		if (count == 1) {
			Node<T>* del = head;
			delete del;
			count--;
			return;
		}

		if (pos == 1) {
			Node<T>* del = head;
			Node<T>* prevdel = del->prev;
			Node<T>* nextdel = del->next;
			prevdel->next = nextdel;
			nextdel->prev = prevdel;
			head = prevdel;
			delete del;
			count--;
			return;
		}

		if (pos == count + 1) {
			Node<T>* del = tail;
			Node<T>* nextdel = del->next;
			Node<T>* prevdel = del->prev;
			prevdel->next = nextdel;
			nextdel->prev = prevdel;
			head = nextdel;
			delete del;
			count--;
			return;
		}

		int i = 1;
		Node<T>* del = head;
		while (i < pos) {
			del = del->prev;
			i++;
		}

		Node<T>* prevdel = del->prev;
		Node<T>* nextdel = del->next;
		prevdel->next = nextdel;
		nextdel->prev = prevdel;
		delete del;
		count--;
	}

	bool isEmpty() {
		if (count == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int search(int num) {
		Node<T>* temp;
		temp = head;
		T buff;
		for (int i = 1; i < count; i++) {
			buff = temp->data;

			if (buff.search(num) == -1)
				temp = temp->prev;
			else
				return i;
		}
		return -1;
	}
	T getData(int pos) {
		Node<T>* temp;
		temp = head;
		int i = 1;

		while (i < pos) {
			temp = temp->prev;
			i++;
		}
		return temp->data;
	}
};
