#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

void Board::render() {
	cout << "|  [1]  |  [2]  |  [3]  |  [4]  |  [5]  |  [6]  |  [7]  |" << endl << endl;
	cout << "|-------------------------------------------------------|" << endl << endl;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			cout << "| ";
			mBoard.at(i).at(j).render();
			cout << " ";
		}
		cout << "|" << endl << endl;
	}
	cout << "|-------------------------------------------------------|" << endl;
}

void Board::changeChecker(int column, char pieceColor) {
	column--;
	int row = findRowPosition(column);
	mBoard.at(row).at(column).setPieceVal(pieceColor);
}

int Board::findRowPosition(int column) {
	for (int i = NUM_ROWS - 1; i >= 0; i--) {
		if (mBoard.at(i).at(column).getPieceVal() == ' ') {
			return i;
		}
	}
}