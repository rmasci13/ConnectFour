#pragma once
#include <iostream>

using namespace std;

class Checker
{
private:
	char pieceVal;

public:
	char getPieceVal(); //Piece value getter
	void setPieceVal(char val); //Piece value setter
	void render(); //Checker piece drawer
	Checker() : pieceVal(' ') {}; //Constructor sets default piece to blank space
};

