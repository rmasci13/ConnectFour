#include "Game.h"
#include "Board.h"
#include <string>

using namespace std;

void Game::playGame() {
	while (true) {
		static bool blackTurn = true; //Used to know which color wins. Alternates after move completed without win
		char input = Game::getUserInput();
		if (input == 'q') {
			break;
		}
		else {
			//Place piece and draw board
			int column = input - '1'; //convert the char column entered into int index number 
			int row = myBoard.lowestOpenRow(column);
			myBoard.placeCheckerPiece(column);
			myBoard.render();

			//Check if the board is full resulting in draw
			if (myBoard.checkBoardFull()) {
				cout << "The board is full. The game is a draw." << endl;
				break;
			}

			//Check if piece played resulted in a win
			if (myBoard.checkWin(column, row)) {
				blackTurn ? cout << "CONGRATULATIONS!! Black WINS!!" << endl : cout << "CONGRATULATIONS!! Red WINS!!" << endl;
				break;
			}
			blackTurn = !blackTurn;
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
		//Check if not valid column (not 1-7)
		else if (input < '1' || input > '7') {
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

