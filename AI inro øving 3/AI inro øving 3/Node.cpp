#include "Node.h"

Node::Node(int x, int y, bool isPasable):isPasable(isPasable),values(Pair<int>(x,y))
{
	neibours = new Node*[4];
	for (int i = 0; i < 4; i++) {
		neibours[i] =  nullptr;
	}
}

Pair<int> Node::getValues()
{
	return values;//Pari burde ikke vært mutable.
}

bool Node::getIsPasable()
{
	return isPasable;
}

bool Node::hasNeigbour(int dir)
{
	return neibours[dir] != nullptr;//Sjekker om pointene
}

Node Node::getNeigbour(int dir)
{
	if (this->hasNeigbour(dir)) {
		return *neibours[dir];
	}else{
		std::cout << "Fant ikke naboen i:" << dir;
		throw 404;
	}
}

void Node::addNeigbour(int dir, Node newNeigbour)
{
	*this->neibours[dir] = newNeigbour;
}
