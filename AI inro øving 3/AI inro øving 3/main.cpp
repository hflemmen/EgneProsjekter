#include "Board.h"
#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
;
int main() {
	std::cout << "Start" << std::endl;

	//PriorityQueue<int> pq(9);
	//pq.push('d', 4);
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
	
	Board b = Board("boards/board-1-1.txt");
	std::cout << b.toString();

}