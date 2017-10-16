#pragma once
#pragma once
#include <string>
#include "Node.h"
#include <sstream>



struct Bundle
{
public:
	int priority;
	Node element;
	Bundle(int p,Node e) :priority(p), element(e) {};
	Bundle() :priority(0), element(Node()) {};
	std::string toString() {
		std::ostringstream ss;
		ss << "Bundle " << this->element.getValues().x<<','<<element.getValues().y << " with " << priority << " priority.\n";
		return ss.str();
	}
};


class PriorityQueueNode {
private:
	//Den underliggende strukturen heapen legges på. 1 indeksert. Element 0 er peker til dit neste element har plass.
	Bundle * data;//
	int size;
	//Disse to burde være mulig å få til å kjøre rekursivt.
	bool upheap(int index);//Sammenligner to bundler(Den oppgitte og dens forelder. True hvis vi må sjekke om den må videre opp.
	int downheap(int index);//Gjennomfører et enkelt downhepsteg. Returnerer indeksen på det neste elementet som må sjekkes eller 0 om det er ferdig.
	int getChild(int index, bool leftChild);//Tar inn en index og gir ut end index. Høyre barn, hvis leftchild er false.
	int getParent(int index);//^
	void swap(int index1, int index2);
	int nextPlace;//Er en index i dataarrayet
public:
	PriorityQueueNode(int expectedSize);//Fordi dette proskjektet kan bestemme ganske riktig hvor stor heap vi trenger. Må initialisere den underliggende arrayen.
	Node pop();
	void push(Node newElement, int pri);
	std::string toString();
};

