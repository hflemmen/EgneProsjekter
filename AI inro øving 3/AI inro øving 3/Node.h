#pragma once
#include<vector>
#include"util.h"
#include<iostream>

class Node {
private:
	Node **neibours;//Har lengde 4. 0 er nord, 1 er vest, 2 er s;r og 3 er ;st. Må være pekere til pekere, fordi vi skal bare lagre pekerene til objektene, ikke objektene selv.
	Pair<int> values;//Koordinatene til noden.
	bool isPasable;//Kan endres til en enum med status når det blir forsjell på rutene. Eventuellt kan jeg bare lagre charsene og lagre et map til kostnaddene.
public:
	Node(int x, int y,bool isPasable);//Må initialisere neigbours(Enten med verdier eller i det minste tom.
	Node() { Node(-1, -1, 0); }
	Pair<int> getValues();
	bool getIsPasable();
	bool hasNeigbour(int dir);//0<= dir <= 4 Er retningen til naboen du vil sjekke om er der.
	Node getNeigbour(int dir);//0<= dir <= 4 Er retningen til naboen du vil ha.
	void addNeigbour(int dir, Node newNeigbour);//0<= dir <= 4 Er retningen til naboen du vil legge til. Kan overskrive eksiterende noder.
friend std::ostream& operator<<(std::ostream& os, Node n)
	{
		os <<  n.values.toString() << "isPasable: " << n.isPasable << '\n';
		return os;
	}

};
