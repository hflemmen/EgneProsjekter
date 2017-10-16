#include "PriorityQueueNode.h"
#include <math.h>
#include <sstream>
#include <iostream>



bool PriorityQueueNode::upheap(int index)
{
	if (data[index].priority > data[getParent(index)].priority) {
		swap(index, getParent(index));
		return upheap(getParent(index));
	}
	else {
		return false;
	}
}

 
int PriorityQueueNode::downheap(int index)
{
	if (data[index].priority < data[getChild(index, true)].priority) {//er forelderen mindre enn det ene barnet?
			if (data[getChild(index, true)].priority < data[getChild(index, false)].priority) {//Er det store barnet mindre enn det andre barnet?
				swap(index, getChild(index, false));
				return downheap(getChild(index, false));
			}
		else {
			swap(index, getChild(index, true));
			return downheap(getChild(index, true));
		}
	}else {
		if (data[index].priority < data[getChild(index, false)].priority) {//er forelderen mindre enn det andre barnet?
			swap(index, getChild(index, false));
			return downheap(getChild(index, false));
		}
		else {
			return 0;
		}
	}
}

 
int PriorityQueueNode::getChild(int index, bool leftChild)
{
return 2 * index + !leftChild;//Negert fordi venstre barn er 2n.
}

 
int PriorityQueueNode::getParent(int index)
{
return (int) floor( index/2);
}

 
void PriorityQueueNode::swap(int index1,int index2)
{
Bundle temp = data[index1];
data[index1] = data[index2];
data[index2] = temp;

}

 
PriorityQueueNode::PriorityQueueNode(int expectedSize)
{
size = 2 ^ (int)floor(log2(expectedSize));
data = new Bundle[size + 1];//+1 for å kunne ha den 1 indeksert.
std::cout << "Lagde en heap med dette antall noder: " << size << '\n';
}

 
inline Node PriorityQueueNode::pop()
{
Node res = data[1].element;
data[1] = data[--nextPlace];//nextPlace er neste ledige plass å legge et nytt barn. Dekrementeres fordi denne nå forsvinner.
downheap(1);//Ordner datastrukturen rekursivt.
return res;
}

 
void PriorityQueueNode::push(Node newElement, int pri)
{
data[nextPlace] = Bundle(pri,newElement);//nextPlace må inkrementeres for å være konsistent. Utsetter det til neste linje for å kunne bruke den en gang til.
upheap(nextPlace++);//^
}

 
/*std::string PriorityQueueNode::toString()
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