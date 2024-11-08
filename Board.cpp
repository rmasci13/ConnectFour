#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

void Board::render() {
	//Print top of board
	cout << "|  [1]  |  [2]  |  [3]  |  [4]  |  [5]  |  [6]  |  [7]  |" << endl << endl;
	cout << "|-------------------------------------------------------|" << endl << endl;
	//Print checkers grid
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			cout << "| ";
			mBoard.at(i).at(j).render();
			cout << " ";
		}
		cout << "|" << endl << endl;
	}
	//Print bottom board
	cout << "|-------------------------------------------------------|" << endl;
}

void Board::changeChecker(int column) {
	//Initialize to B as black goes first. Static so doesn't re-initialize every call
	static char val = 'B';
	int row = findRowPosition(column); //Find first open space in column
	mBoard.at(row).at(column).setPieceVal(val);
	val = val == 'B' ? 'R' : 'B'; //Change to opposite piece after placed
}

int Board::findRowPosition(int column) {
	for (int i = NUM_ROWS - 1; i >= 0; i--) {
		if (mBoard.at(i).at(column).getPieceVal() == ' ') {
			return i;
		}
	}
	return -1;
}

bool Board::checkAvailableSpace(int column) {
	//Used in Game to ensure column has an open space. Returns true if top space is still blank
	return mBoard.at(0).at(column).getPieceVal() == ' ' ? true : false;
}

bool Board::checkBoardFull() {
	for (int i = 0; i < Board::NUM_COLS; i++) {
		//Kick out if any column has an available space. 
		if (checkAvailableSpace(i)) {
			return false;
		}
	}
	return true;
}

bool Board::checkWin(int column, int row) {
	if (checkHorizontal(column, row)) {
		return true;
	}
	else if (checkVertical(column, row)) {
		return true;
	}
	else if (checkDiagonal1(column, row)) {
		return true;
	}
	else if (checkDiagonal2(column, row)) {
		return true;
	}
	return false;
}

bool Board::checkHorizontal(int column, int row) {
	int left = 0;
	int right = 0;
	int total = 1;

	char currentPiece = mBoard.at(row).at(column).getPieceVal();
	//First expression makes sure not checking past vector bounds
	if (column + 1 < Board::NUM_COLS && mBoard.at(row).at(column + 1).getPieceVal() == currentPiece) {
		right++;
		if (column + 2 < Board::NUM_COLS && mBoard.at(row).at(column + 2).getPieceVal() == currentPiece) {
			right++;
			if (column + 3 < Board::NUM_COLS && mBoard.at(row).at(column + 3).getPieceVal() == currentPiece) {
				right++;
			}
		}
	}
	if (column - 1 >= 0 && mBoard.at(row).at(column - 1).getPieceVal() == currentPiece) {
		left++;
		if (column - 2 >= 0 && mBoard.at(row).at(column - 2).getPieceVal() == currentPiece) {
			left++;
			if (column - 3 >= 0 && mBoard.at(row).at(column - 3).getPieceVal() == currentPiece) {
				left++;
			}
		}
	}
	total += right;
	total += left;
	if (total >= 4) {
		return true;
	}
	return false;
}

bool Board::checkVertical(int column, int row) {
	int left = 0;
	int right = 0;
	int total = 1;

	char currentPiece = mBoard.at(row).at(column).getPieceVal();
	//First expression makes sure not checking past vector bounds
	if (row + 1 < Board::NUM_ROWS && mBoard.at(row + 1).at(column).getPieceVal() == currentPiece) {
		right++;
		if (row + 2 < Board::NUM_ROWS && mBoard.at(row + 2).at(column).getPieceVal() == currentPiece) {
			right++;
			if (row + 3 < Board::NUM_ROWS && mBoard.at(row + 3).at(column).getPieceVal() == currentPiece) {
				right++;
			}
		}
	}
	if (row - 1 >= 0 && mBoard.at(row - 1).at(column).getPieceVal() == currentPiece) {
		left++;
		if (row - 2 >= 0 && mBoard.at(row - 2).at(column).getPieceVal() == currentPiece) {
			left++;
			if (row - 3 >= 0 && mBoard.at(row - 3).at(column).getPieceVal() == currentPiece) {
				left++;
			}
		}
	}
	total += right;
	total += left;
	if (total >= 4) {
		return true;
	}
	return false;
}

bool Board::checkDiagonal1(int column, int row) {
	int left = 0;
	int right = 0;
	int total = 1;

	char currentPiece = mBoard.at(row).at(column).getPieceVal();
	if (column + 1 > Board::NUM_COLS && row + 1 < Board::NUM_ROWS && mBoard.at(row + 1).at(column + 1).getPieceVal() == currentPiece) {
		right++;
		if (column + 2 > Board::NUM_COLS && row + 2 < Board::NUM_ROWS && mBoard.at(row + 2).at(column + 2).getPieceVal() == currentPiece) {
			right++;
			if (column + 3 > Board::NUM_COLS && row + 3 < Board::NUM_ROWS && mBoard.at(row + 3).at(column + 3).getPieceVal() == currentPiece) {
				right++;
			}
		}
	}
	if (column - 1 >= 0 && row - 1 >= 0 && mBoard.at(row - 1).at(column - 1).getPieceVal() == currentPiece) {
		left++;
		if (column - 2 >= 0 && row - 2 >= 0 && mBoard.at(row - 2).at(column - 2).getPieceVal() == currentPiece) {
			left++;
			if (column - 3 >= 0 && row - 3 >= 0 && mBoard.at(row - 3).at(column - 3).getPieceVal() == currentPiece) {
				left++;
			}
		}
	}
	total += right;
	total += left;
	if (total >= 4) {
		return true;
	}
	return false;
}

bool Board::checkDiagonal2(int column, int row) {
	int left = 0;
	int right = 0;
	int total = 1;

	char currentPiece = mBoard.at(row).at(column).getPieceVal();
	if (column - 1 >= 0 && row + 1 < Board::NUM_ROWS && mBoard.at(row + 1).at(column - 1).getPieceVal() == currentPiece) {
		right++;
		if (column - 2 >= 0 && row + 2 < Board::NUM_ROWS && mBoard.at(row + 2).at(column - 2).getPieceVal() == currentPiece) {
			right++;
			if (column - 3 >= 0 && row + 3 < Board::NUM_ROWS && mBoard.at(row + 3).at(column - 3).getPieceVal() == currentPiece) {
				right++;
			}
		}
	}
	if (column + 1 < Board::NUM_COLS && row - 1 >= 0 && mBoard.at(row - 1).at(column + 1).getPieceVal() == currentPiece) {
		left++;
		if (column + 2 < Board::NUM_COLS && row - 2 >= 0 && mBoard.at(row - 2).at(column + 2).getPieceVal() == currentPiece) {
			left++;
			if (column + 3 < Board::NUM_COLS && row - 3 >= 0 && mBoard.at(row - 3).at(column + 3).getPieceVal() == currentPiece) {
				left++;
			}
		}
	}
	total += right;
	total += left;
	if (total >= 4) {
		return true;
	}
	return false;
}