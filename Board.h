#pragma once
#include <iostream>
#include <vector>
#include "Checker.h"

using namespace std;

class Board
{
public:
	//Constructor to establish the 2D vector
	Board() : mBoard(Board::NUM_ROWS, vector<Checker>(Board::NUM_COLS)) {};

	void render(); //draw the board
	void changeChecker(int column); //Place piece
	bool checkColumnFull(int column); //Ensure the column has an open spot
	int findRowPosition(int column); //Find how deep the piece needs to fall

	bool checkWin(int column, int row);


private:
	const int NUM_COLS = 7;
	const int NUM_ROWS = 6;
	
	vector<vector<Checker>> mBoard;

	bool checkHorizontal(int column, int row);
	bool checkVertical(int column, int row);
	bool checkDiagonal1(int column, int row);
	bool checkDiagonal2(int column, int row);
	
};

