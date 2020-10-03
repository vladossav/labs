#ifndef HEADER_H
#define HEADER_H

class ArrayWork {
public:
	ArrayWork(); //êîíñòðóêòîð ïî óìîë÷àíèþ
	ArrayWork(int maxSize0, int* ptr0); //êîíñòðóêòîð ñ ïàðàìåòðàìè
	~ArrayWork(); //äåñòðóêòîð
	int getMaxSize(); //ïîëó÷åíèå ðàçìåðà ìàññèâà
	int* getPtr(); //ïîëó÷åíèå ìàññèâà
	char* toString(); //âûâîä 
	void add(int num); //int num - ýëåìåíò, êîòîðûé äîáàâëÿåì
	void replace(int numPos, int number); //int num - ïîðÿäêîâûé íîìåð ýëåìåíòà çàìåíû
										  //number - ÷èñëî äëÿ çàìåíû
	void sort();
	void remove(int numPos); //int num - ïîðÿäêîâûé íîìåð ýëåìåíòà óäàëåíèÿ
	int search(int num); //ïîèñê ýëåìåíòà
private:
	int maxSize;
	static int nowCount;
	int* ptr;
	int buffer(int* temp); //áóôåð äëÿ ìåòîäîâ add è toDelete
};
#endif // !Header.h
