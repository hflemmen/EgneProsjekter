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
	//Den underliggende strukturen heapen legges p�. 1 indeksert. Element 0 er peker til dit neste element har plass.
	Bundle * data;//
	int size;
	//Disse to burde v�re mulig � f� til � kj�re rekursivt.
	bool upheap(int index);//Sammenligner to bundler(Den oppgitte og dens forelder. True hvis vi m� sjekke om den m� videre opp.
	int downheap(int index);//Gjennomf�rer et enkelt downhepsteg. Returnerer indeksen p� det neste elementet som m� sjekkes eller 0 om det er ferdig.
	int getChild(int index, bool leftChild);//Tar inn en index og gir ut end index. H�yre barn, hvis leftchild er false.
	int getParent(int index);//^
	void swap(int index1, int index2);
	int nextPlace;//Er en index i dataarrayet
public:
	PriorityQueueNode(int expectedSize);//Fordi dette proskjektet kan bestemme ganske riktig hvor stor heap vi trenger. M� initialisere den underliggende arrayen.
	Node pop();
	void push(Node newElement, int pri);
	std::string toString();
};

