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

void Board::changeChecker(int column) {
	static char val = 'B';
	int row = findRowPosition(column);
	mBoard.at(row).at(column).setPieceVal(val);
	val = val == 'B' ? 'R' : 'B';
}

int Board::findRowPosition(int column) {
	for (int i = NUM_ROWS - 1; i >= 0; i--) {
		if (mBoard.at(i).at(column).getPieceVal() == ' ') {
			return i;
		}
	}
}

bool Board::checkColumnFull(int column) {
	return mBoard.at(0).at(column).getPieceVal() == ' ' ? false : true;
}