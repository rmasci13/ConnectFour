#pragma once
#include <iostream>
#include "Board.h"

class Game
{
public:
	Game() : blackTurn(true) {}; //Default constructor
	void playGame(); //Handles running the game
private:
	Board myBoard;
	const int WIN_CONDITION = 4; //Number of pieces in a row needed to win
	bool blackTurn; //Used to know which color wins. Alternates after move completed without win

	char getUserInput(); //Handles getting user input ensuring its valid input and calls board function to ensure column has open space

	bool checkWin(int column, int row); //Checks if the last piece placed resulted in a win. Returns true if win
	
	bool checkDirection(int column, int row, int changeRow, int changeCol); //Checks a specific direction for a win. Returns true if win in that direction
};

