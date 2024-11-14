#pragma once
#include <iostream>

using namespace std;

class Checker
{
private:
	char pieceVal;

public:
	Checker() : pieceVal(' ') {}; //Constructor sets default piece to blank space

	//Getter & Setter for piece color
	char getPieceVal();
	void setPieceVal(char val); 

	void render(); //Checker piece drawer
};

