#pragma once
#include <iostream>
#include "Board.h"

class Game
{
public:
	void playGame(); //Handles running the game
private:
	Board myBoard;

	char getUserInput(); //Handles getting user input ensuring its valid input and calls board function to ensure column has open space
};

