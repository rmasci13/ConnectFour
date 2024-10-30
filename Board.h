#pragma once
#include <iostream>
#include <vector>
#include "Checker.h"

using namespace std;

class Board
{
public:
	//a
private:
	const int NUM_COLS = 7;
	const int NUM_ROWS = 6;
	
	vector<vector<Checker>> brd;
};

