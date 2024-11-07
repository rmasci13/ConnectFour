#pragma once
#include <iostream>
#include "Board.h"

class Game
{
public:
	void playGame();
private:
	Board myBoard;

	char getUserInput();
};

