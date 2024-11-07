#include "Game.h"
#include "Board.h"
#include <string>

using namespace std;

void Game::playGame() {
	bool gameOver = false;
	while (!gameOver) {
		char input = Game::getUserInput();
		if (input == 'q') {
			gameOver = true;
			break;
		}
		else {
			int column = input - '1'; //convert the char column entered into int index number 
			myBoard.changeChecker(column);
			myBoard.render();
		}
	}
}

char Game::getUserInput() {
	char input;
	static bool blackTurn = true;
	int tempInput;

	while (true) {
		if (blackTurn) {
			cout << "Black moves. Select column [1 - 7], 'q' to quit" << endl;
			cin >> input;
		}
		else {
			cout << "Red moves. Select column [1 - 7], 'q' to quit" << endl;
			cin >> input;
		}
		
		//immediately kick out if q
		if (input == 'q') {
			return input;
		}
		//Check if valid column or q
		if (input < 49 || input > 55) {
			cout << "Invalid column entered. Try again" << endl;
		}
		else {
			tempInput = input - '1'; //change it to int index number while retaining char in original variable
			if (!myBoard.checkColumnFull(tempInput)) { //if column not full return input
				blackTurn = !blackTurn;
				return input;
			}
			else {
				cout << "Sorry that column is full. Try again" << endl;
			}
		}
	}
}