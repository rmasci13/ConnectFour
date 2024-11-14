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

void Board::placeCheckerPiece(int column) {
	static bool blackTurn = true; //Initialize to true as black goes first. Static so doesn't re-initialize every call. Alternate at end
	char pieceColor = blackTurn ? 'B' : 'R';
	int row = lowestOpenRow(column); //Find lowest open space in column
	mBoard.at(row).at(column).setPieceVal(pieceColor);
	blackTurn = !blackTurn;
}

int Board::lowestOpenRow(int column) {
	//Another function already handled checking if the column is full. If it was full, this function wouldn't have even been called as user reprompted for input.
	for (int i = NUM_ROWS - 1; i >= 0; i--) {
		if (mBoard.at(i).at(column).getPieceVal() == ' ') {
			return i;
		}
	}
	return -1;
}

bool Board::checkAvailableSpace(int column) {
	//Used in Game to ensure column has an open space. Returns true if top space is still blank
	return mBoard.at(0).at(column).getPieceVal() == ' ';
}

bool Board::checkBoardFull() {
	for (int i = 0; i < Board::NUM_COLS; i++) {
		//Kick out if any column has an available space. If get through all columns without available space board is full
		if (checkAvailableSpace(i)) { 
			return false; 
		}
	}
	return true;
}

bool Board::checkWin(int column, int row) {
	//Check if any of the win checks returns true
	return (checkHorizontal(column, row) || checkVertical(column, row) || checkDiagonalNE_SW(column, row) || checkDiagonalNW_SE(column, row));
}

bool Board::checkHorizontal(int column, int row) {
	int left = 0;
	int right = 0;
	int total = 1;

	char currentPiece = mBoard.at(row).at(column).getPieceVal();

	//First expression makes sure not checking past vector bounds, second checks if adjacent checker same as placed
	if (column + 1 < Board::NUM_COLS && mBoard.at(row).at(column + 1).getPieceVal() == currentPiece) {
		right++;
		//Only continues checking next piece if adjacent one was the same
		if (column + 2 < Board::NUM_COLS && mBoard.at(row).at(column + 2).getPieceVal() == currentPiece) {
			right++;
			if (column + 3 < Board::NUM_COLS && mBoard.at(row).at(column + 3).getPieceVal() == currentPiece) {
				right++;
			}
		}
	}
	//Same checks as above but to left
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
	//Same ideas as notes describe in checkHorizontal, but for verticals
	int down = 0;
	int total = 1;

	char currentPiece = mBoard.at(row).at(column).getPieceVal();
	if (row - 1 >= 0 && mBoard.at(row - 1).at(column).getPieceVal() == currentPiece) {
		down++;
		if (row - 2 >= 0 && mBoard.at(row - 2).at(column).getPieceVal() == currentPiece) {
			down++;
			if (row - 3 >= 0 && mBoard.at(row - 3).at(column).getPieceVal() == currentPiece) {
				down++;
			}
		}
	}
	total += down;
	if (total >= 4) {
		return true;
	}
	return false;
}

bool Board::checkDiagonalNE_SW(int column, int row) {
	//Same ideas as notes describe in checkHorizontal, but for diagonally up-right and down-left
	int left = 0;
	int right = 0;
	int total = 1;

	char currentPiece = mBoard.at(row).at(column).getPieceVal();
	//Check north-east
	if (column + 1 > Board::NUM_COLS && row + 1 < Board::NUM_ROWS && mBoard.at(row + 1).at(column + 1).getPieceVal() == currentPiece) {
		right++;
		if (column + 2 > Board::NUM_COLS && row + 2 < Board::NUM_ROWS && mBoard.at(row + 2).at(column + 2).getPieceVal() == currentPiece) {
			right++;
			if (column + 3 > Board::NUM_COLS && row + 3 < Board::NUM_ROWS && mBoard.at(row + 3).at(column + 3).getPieceVal() == currentPiece) {
				right++;
			}
		}
	}
	//Check south-west
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

bool Board::checkDiagonalNW_SE(int column, int row) {
	//Same ideas as notes describe in checkHorizontal, but for diagonally up-left and down-right
	int left = 0;
	int right = 0;
	int total = 1;

	char currentPiece = mBoard.at(row).at(column).getPieceVal();
	//Check north-west
	if (column - 1 >= 0 && row + 1 < Board::NUM_ROWS && mBoard.at(row + 1).at(column - 1).getPieceVal() == currentPiece) {
		right++;
		if (column - 2 >= 0 && row + 2 < Board::NUM_ROWS && mBoard.at(row + 2).at(column - 2).getPieceVal() == currentPiece) {
			right++;
			if (column - 3 >= 0 && row + 3 < Board::NUM_ROWS && mBoard.at(row + 3).at(column - 3).getPieceVal() == currentPiece) {
				right++;
			}
		}
	}
	//Check south-east
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