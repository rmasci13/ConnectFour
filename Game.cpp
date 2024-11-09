#include "Game.h"
#include "Board.h"
#include <string>

using namespace std;

void Game::playGame() {
	bool gameOver = false;
	while (!gameOver) {
		static bool blackTurn = true; //Initialized to black true because black moves first
		char input = Game::getUserInput();
		if (input == 'q') {
			gameOver = true;
			break;
		}
		else {
			int column = input - '1'; //convert the char column entered into int index number 
			int row = myBoard.findRowPosition(column);
			myBoard.changeChecker(column);
			myBoard.render();

			//Check if the board is full resulting in draw
			if (myBoard.checkBoardFull()) {
				gameOver = true;
				cout << "The board is full. The game is a draw." << endl;
				break;
			}

			//Check if piece played resulted in a win
			if (myBoard.checkWin(column, row)) {
				gameOver = true;
				if (blackTurn) {
					cout << "CONGRATULATIONS!! Black WINS!!" << endl;
				}
				else {
					cout << "CONGRATULATIONS!! Red WINS!!" << endl;
				}
				break;
			}
			blackTurn = !blackTurn; //Alternates after turn is over to track which color is moving during current turn
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
		
		//Immediately kick out if q
		if (input == 'q') {
			return input;
		}
		//Check if valid column (1-7)
		if (input < '1' || input > '7') {
			cout << "Invalid column entered. Try again" << endl;
		}
		else {
			tempInput = input - '1'; //change it to int index number while retaining char in original variable
			//Check if column has space available, if it doesn't it outputs error message and while loop restarts calling for input again
			if (myBoard.checkAvailableSpace(tempInput)) { 
				blackTurn = !blackTurn;
				return input;
			}
			else {
				cout << "Sorry that column is full. Try again" << endl;
			}
		}
	}
}

