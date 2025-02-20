#include "Game.h"
#include "Board.h"
#include <string>

using namespace std;

void Game::playGame() {
	while (true) {
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

			//Check if piece played resulted in a win
			if (checkWin(column, row)) {
				blackTurn ? cout << "CONGRATULATIONS!! Black WINS!!" << endl : cout << "CONGRATULATIONS!! Red WINS!!" << endl;
				break;
			}

			//Check if the board is full resulting in draw. Must be after check win because last piece can be a winning move
			if (myBoard.checkBoardFull()) {
				cout << "The board is full. The game is a draw." << endl;
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

bool Game::checkWin(int column, int row) {
	vector<pair<int, int>> directions = { {0,1}, {1,0}, {1,1}, {1,-1} }; //4 directions to check for win
	for (auto& direction : directions) {
		int changeRow = direction.first;
		int changeCol = direction.second;
		if (checkDirection(column, row, changeRow, changeCol)) {
			return true;
		}
	}
	return false;
}

bool Game::checkDirection(int column, int row, int changeRow, int changeCol) {
	int count = 1; //Start at 1 as the piece just played counts as 1
	char pieceColor = myBoard.getPieceVal(row, column); //Get the piece color of the piece just played

	//Check in the positive direction
	for (int i = 1; i < Game::WIN_CONDITION; i++) {
		int newRow = row + (changeRow * i);
		int newCol = column + (changeCol * i);
		if (newRow >= 0 && newRow < myBoard.getNumRows() && newCol >= 0 && newCol < myBoard.getNumCols()) {
			if (myBoard.getPieceVal(newRow, newCol) == pieceColor) {
				count++;
			}
			else {
				break;
			}
		}
	}

	//Check in the negative direction
	for (int i = 1; i < Game::WIN_CONDITION; i++) {
		int newRow = row - (changeRow * i);
		int newCol = column - (changeCol * i);
		if (newRow >= 0 && newRow < myBoard.getNumRows() && newCol >= 0 && newCol < myBoard.getNumCols()) {
			if (myBoard.getPieceVal(newRow, newCol) == pieceColor) {
				count++;
			}
			else {
				break;
			}
		}
	}
	//If count is 4 or more, return true
	return count >= Game::WIN_CONDITION;
}