#pragma once

using namespace std;

class Checker
{
public:
	Checker() : pieceVal(' ') {}; //Constructor sets default piece to blank space

	//Getter & Setter for piece color
	char getPieceVal();
	void setPieceVal(char val); 

	void render(); //Checker piece drawer

private:
	char pieceVal; //Piece value. Only R or B allowed
};

