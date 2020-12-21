#pragma once
#include "ArrayWork.h"
class Node {
	friend class List;
private:
	ArrayWork data;
	Node * next, * prev;
};

class List {
private:
	Node* head, * tail;
	int count;
public:
	List();
	~List();
	void add(ArrayWork data);
	void insert(int pos, ArrayWork data);
	void viewAll();
	void view(int pos);
	void delAll();
	void del(int pos);
	bool isEmpty();
	int search(int num);
	ArrayWork getData(int pos);
};