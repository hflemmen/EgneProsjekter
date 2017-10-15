#pragma once
#include <string>
#include "Node.h"
#include <istream>

class Board {
private:
	char ** board;//Lagrer selve brettet for å kunne skrive det ut igjen.
	Pair<int> startNode;
	Pair<int> endNode;
	int linjeLength;
	int numOfLines;
public:
	Board(std::string filepath);//B;r gi error om lengden av filen ikke samsvarer med linjelengden. Kan hende jeg m[ ta hensyn til hvilke type fil det er.(Om det er bare vegger eller alsidig natur.
	Node getStartNode();//B;r legge hele brettet inn som sidenoder til sideoder osv. (Kan lage en intern 2D-liste for alle nodene for å finne naboene.)
	Pair<int> getGoalNode;//Gir bare posisjonen, vet ikke den eksakte noden.
	bool changeTile(Pair<int> pos, char newChar);//True hvis det var en valid bokstav, som det alltid skal være. False hvis du var utenfor brettet eller bokstaven var ugyldig.
	std::string toString();//Kan vurdere om jeg burde finne p[ andre tegn enn de som er default. De burde funke da.
	//Må lage en destruktør som bruker delete.
};

const char validchars[10] = { 'w','m','f','g','r','\n', '.','#' ,'A','B'};

bool verifyBoardFile(std::string filepath, int &lineLenght, int &numOfLines);