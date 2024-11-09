#include "Checker.h"
#include <iostream>

using namespace std;

char Checker::getPieceVal() {
	return pieceVal;
}

void Checker::setPieceVal(char val) {
	//Check to ensure only R or B. Not really necessary but public function so technically possible
	if (val == 'R' || val == 'B') {
		pieceVal = val;
	}
}

void Checker::render() {
	//Draw the checker using its member pieceVal
	cout << " (" << pieceVal << ") ";
}