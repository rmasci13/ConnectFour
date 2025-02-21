#include "Checker.h"
#include <iostream>

using namespace std;

//Getter and Setter for pieceVal. Only R or B allowed
char Checker::getPieceVal() {
	return pieceVal;
}
void Checker::setPieceVal(char val) {
	//Check to ensure only R or B. Not really necessary but public function so technically possible
	if (val == 'R' || val == 'B') {
		pieceVal = val;
	}
}

//Render the piece to the console. If blank space, render as blank space
void Checker::render() {
	cout << " (" << pieceVal << ") ";
}