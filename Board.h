#pragma once
#include <iostream>
#include <vector>
#include "Checker.h"

using namespace std;

class Board
{
public:
	Board() : mBoard(Board::NUM_ROWS, vector<Checker>(Board::NUM_COLS)) {};
	void render();
	void changeChecker(int column);
private:
	const int NUM_COLS = 7;
	const int NUM_ROWS = 6;
	
	vector<vector<Checker>> mBoard;

	int findRowPosition(int column);
};

