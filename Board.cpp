#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

//Render the board to the console
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

//Place a piece in the board. Takes column and bool to determine if black or red turn
void Board::placeCheckerPiece(int column, bool blackTurn) {
	char pieceColor = blackTurn ? 'B' : 'R';
	int row = lowestOpenRow(column); //Find lowest open space in column
	mBoard.at(row).at(column).setPieceVal(pieceColor);
}

//Finds the lowest open space in a column. Returns the row number of the lowest open space
int Board::lowestOpenRow(int column) {
	//Another function already handled checking if the column is full. If it was full, this function wouldn't have even been called as user reprompted for input.
	for (int i = NUM_ROWS - 1; i >= 0; i--) {
		if (mBoard.at(i).at(column).getPieceVal() == ' ') {
			return i;
		}
	}
	return -1; //This should never be reached as the function is only called if there is an open space
}

//Checks if the column has an open space. Used in Game to ensure column has an open space before placing a piece
bool Board::checkAvailableSpace(int column) {
	//Used in Game to ensure column has an open space. Returns true if top space is still blank
	return mBoard.at(0).at(column).getPieceVal() == ' ';
}

//Checks if the board is full. Used in Game to check for draw condition
bool Board::checkBoardFull() {
	for (int i = 0; i < Board::NUM_COLS; i++) {
		//Kick out if any column has an available space. If get through all columns without available space board is full
		if (checkAvailableSpace(i)) { 
			return false; 
		}
	}
	return true;
}
//Returns the piece value at a specific location
char Board::getPieceVal(int row, int column) {
	return mBoard.at(row).at(column).getPieceVal();
}