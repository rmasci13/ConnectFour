#include "Checker.h"
#include <iostream>

using namespace std;

char Checker::getPieceVal() {
	return pieceVal;
}

void Checker::setPieceVal(char val) {
	if (val == 'R' || val == 'B') {
		pieceVal = val;
	}
}

void Checker::render() {
	cout << " (" << pieceVal << ") ";
}