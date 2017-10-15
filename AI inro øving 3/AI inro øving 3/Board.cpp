#include <fstream>
#include <iostream>
#include "Board.h"
#include <sstream>


Board::Board(std::string filepath)
{
	int lineLength;
	int numOfLines;
	std::ifstream file(filepath);
	if (verifyBoardFile(filepath, lineLength, numOfLines)){
		this->board = new char*[lineLength];
		for (int e = 0; e < lineLength; e++) {
			board[e] = new char[numOfLines];
			for (int u = 0; u < numOfLines; u++) {
				file >> board[e][u];
			}
		}
	}
	else {
		std::cerr << "Fant ikke filen";
		throw 404;
	}

}

std::string Board::toString()
{
	std::ostringstream res;
	for (int y = 0; y < numOfLines; y++) {
		for (int x = 0; x < linjeLength; x++) {
			res << board[x][y];
		}
		res << '\n';
	}
	return res.str();
}

bool verifyBoardFile(std::string filepath,int & lineLength, int & numOfLines)
{
	std::ifstream board;
	board.open(filepath, std::ios::in);
	numOfLines = 0;
	char temp;
	lineLength = 0;
	int counter = 0;
	while (board.get(temp)) {
		std::cout << temp;

		if (std::find(std::begin(validchars), std::end(validchars), temp) == std::end(validchars)) {
			//Vi har en ikke godtatt bokstav.
			std::cout << "Filen inneholdt en ugyldig bokstav: " << temp;
			throw 53;
		}
		if (temp == '\n' && lineLength == 0) {
			lineLength = counter;
		}
		if (temp == '\n') {
			numOfLines++;
		}
		if (temp == '\n' && lineLength != 0 && counter % lineLength - numOfLines +1 !=0) {
			std::cout << "Vi hAr en feil i antall bokstaver per linje. P[ linje>" << counter / lineLength << " numOfLines:" << numOfLines << " Linenlength: " << lineLength << " counter: " << counter << " symbolet her var " << temp;
			throw 54;
		}

		counter++;
	}
	if (counter % lineLength != 0 && counter / lineLength != numOfLines) {
		std::cout << "Vi har en feil med antall lijer og tegn";
		throw 55;
	}
	board.close();
	return true;
}
