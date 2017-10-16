#include "Board.h"
#include <iostream>
#include <fstream>
#include "PriorityQueueNode.h"
#include "Node.h"
;
int main() {
	std::cout << "Start" << std::endl;

	Node n = Node(1, 1, 1);
	std::cout << n;
	Node n2 = Node(1, 0, 0);

	PriorityQueueNode pq(9);
	pq.push(n, 4);
	pq.push(n2, 54);
	pq.push(Node(2, 4, 1), 2);
	

	//std::cout << pq.pop();
	//std::cout << pq.pop();
	//std::cout << pq.pop();
	/*std::ofstream testfil;
	testfil.open("boards\\Testfil.txt", std::ios::out);
	if (testfil.is_open()) {
		std::cout << "Great sucsess";
	}
	else {
		std::cout << "not sucsess";
	}
	testfil << "Test\ntestmer.";
	testfil.close();*/
	/*Teste verifiboardgile
	int lineLength;
	int numOfLines;
	bool res = verifyBoardFile("boards/board-1-1.txt", lineLength, numOfLines);
	std::cout << "numofLines: " << numOfLines << ", lineLength: " << lineLength << " validfile: " << res<< '\n';*/
	
	//Board b = Board("boards/board-1-1.txt");
	//std::cout << b.toString();

}