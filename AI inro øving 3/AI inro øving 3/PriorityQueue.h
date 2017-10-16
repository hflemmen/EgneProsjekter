#pragma once
#include <string>

/*
template<typename E>
struct Bundle
{
public:
	int priority;
	E element;
	Bundle(int p, E e):priority(p), element(e) {};
	//Bundle() :priority(0), element(E()) {};
};

template<class T>
class PriorityQueue {
private:
//Den underliggende strukturen heapen legges p�. 1 indeksert. Element 0 er peker til dit neste element har plass.
	Bundle<T> ** data;//Todimensjonal for � bare ha pekere der. Da klarer kompilatoren � lage arrayet.
	int size;
					 //Disse to burde v�re mulig � f� til � kj�re rekursivt.
	bool upheap(int index);//Sammenligner to bundler(Den oppgitte og dens forelder. True hvis vi m� sjekke om den m� videre opp.
	int downheap(int index);//Gjennomf�rer et enkelt downhepsteg. Returnerer indeksen p� det neste elementet som m� sjekkes eller 0 om det er ferdig.
	int getChildOf(int index, bool leftChild);//Tar inn en index og gir ut end index. H�yre barn, hvis leftchild er false.
	int getParentOf(int index);//^
	void swap(int index1,int index2);
public:

	PriorityQueue(int expectedSize);//Fordi dette proskjektet kan bestemme ganske riktig hvor stor heap vi trenger. M� initialisere den underliggende arrayen.
	T pop();
	void push(T newElement, int pri);
	std::string toString();
};


template<class T>
bool PriorityQueue<T>::upheap(int index)
{
	if (data[index].priority > data[getParent(index)]) {
		swap(index, getParent(index));
	}
	else {
		return false;
	}
}

template<class T>
int PriorityQueue<T>::downheap(int index)
{
	if (data[index].priority < data[getChild(index, true)].priority) {//er forelderen mindre enn det ene barnet?
		if (data[getChild(index, true)].priority < data[getChild(index, false)].priority) {//Er det store barnet mindre enn det andre barnet?
			swap(index, getChild(index, false));
			downheap(getChild(index, false))
		}
		else {
			swap(index, getChild(index, true));
			downheap(getChild(index, true))
		}
	}
	else {
		if (data[index].priority < data[getChild(index, false)].priority) {//er forelderen mindre enn det andre barnet?
			swap(index, getChild(index, false));
			downheap(getChild(index, false))
		}
		else {
			return 0;
		}
	}
}

template<class T>
int PriorityQueue<T>::getChildOf(int index, bool leftChild)
{
	return 2 * index + !leftChild;//Negert fordi venstre barn er 2n.
}

template<class T>
int PriorityQueue<T>::getParentOf(int index)
{
	return (int)floor(index / 2);
}

template<class T>
void PriorityQueue<T>::swap(int index1, int index2)
{
	Bundle temp = data[index1];
	data[index] = data[index2];
	data[index2] = temp;

}

template<class T>
PriorityQueue<T>::PriorityQueue(int expectedSize)
{
	size = (int) pow( 2 , floor(log2(expectedSize)));
	data = new  Bundle<T>*[size + 1];//+1 for � kunne ha den 1 indeksert.
	std::cout << "Lagde en heap med dette antall noder: " << size << '\n';
}

template<class T>
inline T PriorityQueue<T>::pop()
{
	T res = data[1];
	data[1] = data[--data[0]];//data[0] er neste ledige plass � legge et nytt barn. Dekrementeres fordi denne n� forsvinner.
	downheap(1);//Ordner datastrukturen rekursivt.
	return res;
}

template<class T>
void PriorityQueue<T>::push( newElement, int pri)
{
	data[data[0]]* = Bundle(pri, newElement);//data[0] m� inkrementeres for � v�re konsistent. Utsetter det til neste linje for � kunne bruke den en gang til.
	upheap(data[0]++)//^
}

template<class T>
std::string PriorityQueue<T>::toString()
{
	std::ostringstream ss;
	for (int e = 0; e <= log2(size); e++) {
		for (int u = 1; u <= e; u++) {
			ss << data[u];
		}
		ss << '\n';
	}
	return ss.str();
}
*/