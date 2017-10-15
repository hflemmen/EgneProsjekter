#pragma once
#include <string>


template<typename E>
struct Bundle
{
public:
	int priority;
	E element;
	Bundle(int p, E e):priority(p), element(e) {};
};

template<typename T>
class PriorityQueue {
private:
	Bundle<T> * data;//Den underliggende strukturen heapen legges på. 1 indeksert. Element 0 er peker til dit neste element har plass.
	const int size;
					 //Disse to burde være mulig å få til å kjøre rekursivt.
	bool upheap(int index);//Sammenligner to bundler(Den oppgitte og dens forelder. True hvis vi må sjekke om den må videre opp.
	int downheap(int index);//Gjennomfører et enkelt downhepsteg. Returnerer indeksen på det neste elementet som må sjekkes eller 0 om det er ferdig.
	int getChildOf(int index, bool leftChild);//Tar inn en index og gir ut end index. Høyre barn, hvis leftchild er false.
	int getParentOf(int index);//^
	void swap(int index1,int index2);
public:

	PriorityQueue(int expectedSize);//Fordi dette proskjektet kan bestemme ganske riktig hvor stor heap vi trenger. Må initialisere den underliggende arrayen.
	T pop();
	void push(T newElement, int pri);
	std::string toString();
};