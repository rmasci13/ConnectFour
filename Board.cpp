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

void Board::placeCheckerPiece(int column, bool blackTurn) {
	char pieceColor = blackTurn ? 'B' : 'R';
	int row = lowestOpenRow(column); //Find lowest open space in column
	mBoard.at(row).at(column).setPieceVal(pieceColor);
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

char Board::getPieceVal(int row, int column) {
	return mBoard.at(row).at(column).getPieceVal();
}