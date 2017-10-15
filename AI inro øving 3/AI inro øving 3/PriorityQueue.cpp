#include "PriorityQueue.h"
#include <math.h>
#include <sstream>
/*

template<typename T>
bool PriorityQueue<T>::upheap(int index)
{
	if (data[index].priority > data[getParent(index)]) {
		swap(index, getParent(index));
	}
	else {
		return false;
	}
}

template<typename T>
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
	}else {
		if (data[index].priority < data[getChild(index, false)].priority) {//er forelderen mindre enn det andre barnet?
			swap(index, getChild(index, false));
			downheap(getChild(index, false))
		}
		else {
			return 0;
		}
	}
}

template<typename T>
int PriorityQueue<T>::getChildOf(int index, bool leftChild)
{
	return 2 * index + !leftChild;//Negert fordi venstre barn er 2n.
}

template<typename T>
int PriorityQueue<T>::getParentOf(int index)
{
	return (int) floor( index/2);
}

template<typename T>
void PriorityQueue<T>::swap(int index1,int index2)
{
	Bundle temp = data[index1];
	data[index] = data[index2];
	data[index2] = temp;
	
}

template<typename T>
PriorityQueue<T>::PriorityQueue(int expectedSize)
{
	size = 2 ^ (int)floor(log2(expectedSize));
	data = new Bundle[size + 1];//+1 for å kunne ha den 1 indeksert.
	std::cout << "Lagde en heap med dette antall noder: " << size << '\n';
}

template<typename T>
inline T PriorityQueue<T>::pop()
{
	T res = data[1];
	data[1] = data[--data[0]];//data[0] er neste ledige plass å legge et nytt barn. Dekrementeres fordi denne nå forsvinner.
	downheap(1);//Ordner datastrukturen rekursivt.
	return res;
}

template<typename T>
void PriorityQueue<T>::push(T newElement, int pri)
{
	data[data[0]] = Bundle<T>(pri,newElement);//data[0] må inkrementeres for å være konsistent. Utsetter det til neste linje for å kunne bruke den en gang til.
	upheap(data[0]++)//^
}

template<typename T>
std::string PriorityQueue<T>::toString()
{
	std::ostringstream ss;
	for (int e = 0; e <=log2(size); e++) {
		for (int u = 1; u <= e; u++) {
			ss << data[u];
		}
		ss << '\n';
	}
	return ss.str();
}
*/