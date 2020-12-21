#ifndef HEADER_H
#define HEADER_H
#include <fstream>
#include <iostream>
class ArrayWork {
public:
	ArrayWork(); //конструктор по умолчанию
	ArrayWork(int maxSize0, int* ptr0); //конструктор с параметрами
	ArrayWork(const ArrayWork& other); //конструктор копирования
	~ArrayWork(); //деструктор

	int getMaxSize(); //получение размера массива
	int* getPtr(); //получение массива
	char* toString(); //вывод 
	void add(int num); //int num - элемент, который добавляем
	void replace(int numPos, int number); //int num - порядковый номер элемента замены
										  //number - число для замены
	void sort();
	void remove(int numPos); //int num - порядковый номер элемента удаления
	int search(int num); //поиск элемента

	//перегрузки операторов
	friend ArrayWork operator+(ArrayWork& a, ArrayWork& b); 
	friend ArrayWork operator-(ArrayWork& a, ArrayWork& b); 
	int operator[](int index);
	ArrayWork& operator--();
	ArrayWork& operator-(int b); 	
	ArrayWork& operator=(const ArrayWork& other);
	bool operator == (const ArrayWork& other);
	friend std::ostream& operator<<(std::ostream& os, ArrayWork& obj);
	friend std::istream& operator>>(std::istream& is, ArrayWork& obj);

	void readFile(char name[]);
	void writeFile(char name[]);
protected:
	int maxSize;
	int* ptr;
	int buffer(int* temp); //буфер для изменения размера массива
private:
	static int nowCount;
	
};
#endif // !Header.h
