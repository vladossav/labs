#ifndef HEADER_H
#define HEADER_H

class ArrayWork {
public:
	ArrayWork(); //конструктор по умолчанию
	ArrayWork(int maxSize0, int* ptr0); //конструктор с параметрами
	~ArrayWork(); //деструктор
	int getMaxSize(); //получение размера массива
	int* getPtr(); //получение массива
	void toString(); //вывод 
	void add(int num); //int num - элемент, который добавляем
	void replace(int numPos, int number); //int num - порядковый номер элемента замены
										  //number - число для замены
	void sort();
	void remove(int numPos); //int num - порядковый номер элемента удаления
	int search(int num); //поиск элемента
private:
	int maxSize;
	static int nowCount;
	int* ptr;
	int buffer(int* temp); //буфер для методов add и toDelete
};
#endif // !Header.h
