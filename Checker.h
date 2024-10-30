#pragma once
#include <iostream>

using namespace std;

class Checker
{
private:
	char pieceVal;

public:
	char getPieceVal();
	void setPieceVal(char val);
	void render();
	Checker() : pieceVal(32) {};
};

