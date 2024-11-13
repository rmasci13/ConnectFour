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

	void render(); //Draw the board
	void placeCheckerPiece(int column); //Place piece
	bool checkAvailableSpace(int column); //Ensure the column has an open spot
	int lowestOpenRow(int column); //Find how deep the piece needs to fall
	bool checkBoardFull(); //Check to see if board is full resulting in draw

	bool checkWin(int column, int row); //Handles checking each of the 4 win conditions


private:
	//Private constants establishing rows and columns in the board. Changing these here allows for different board configurations.
	const int NUM_COLS = 7;
	const int NUM_ROWS = 6;
	
	vector<vector<Checker>> mBoard; //2D vector of checker pieces

	//Private variables to check specific win conditions
	bool checkHorizontal(int column, int row);
	bool checkVertical(int column, int row);
	bool checkDiagonalNE_SW(int column, int row);
	bool checkDiagonalNW_SE(int column, int row);
	
};

