#include "Board.h"

Board::Board()
{
	setBoard();
	isXTurn = true;
	isTerminated = false;
}

void Board::setBoard() {
	// set every cell to empty

	for (unsigned int x = 0; x < MAX_SIZE; x++) {
		for (unsigned int y = 0; y < MAX_SIZE; y++) {
			board[x][y] = EMPTY_CELL;
		}
	}
}

void Board::play(unsigned int x, unsigned int y) {
	// play a certain position on the board

	// get the sign
	int sign;
	std::string strSign;

	if (isXTurn) {
		sign = X;
		strSign = "X";
	}
	else {
		sign = O;
		strSign = "O";
	}

	// check if the position is avaible
	if ((x < MAX_SIZE) && (y < MAX_SIZE)) { // btw, x and y can never be less than zero because they're unsigned

		// check if the position is available
		if (!isPositionPlayed(x, y)) {

			// play the position
			board[x][y] = sign;

			// check if the player won
			if (playerWon(sign)) {
				display();
				isTerminated = true;
				std::cout << "Game over, " << strSign << " won the game" << std::endl;
			}
			else {

				// check if the board is full
				if (isFullBoard()) {
					display();
					isTerminated = true;
					std::cout << "It's a draw" << std::endl;
				}
				else {
					// toggling X's turn
					isXTurn = !isXTurn; // !true => false; !false => true
				}
			}						
		}
	}
}

void Board::display() {

	system("cls"); // clear screen

	std::string strSign;

	for (unsigned int x = 0; x < MAX_SIZE; x++) {
		for (unsigned int y = 0; y < MAX_SIZE; y++) {

			if (board[x][y] == X) {
				strSign = " X ";
			}
			else if (board[x][y] == O) {
				strSign = " O ";
			}
			else {
				strSign = "   ";
			}
			
			std::cout << " " << strSign;
			
			if (y < (MAX_SIZE - 1)) {
				if (!y) {
					std::cout << " ";
				}
				std::cout << " |";
			}
		}

		// new line
		std::cout << std::endl;

		if (x < (MAX_SIZE - 1)) {
			// draw three consecutive lines
			for (int n = 0; n < MAX_SIZE; n++) {
				if (!n) {
					std::cout << " ";
				}

				std::cout << "------";
			}

			// new line
			std::cout << std::endl;
		}
		else {
			std::cout << "\n" << std::endl;
		}
	}
}

bool Board::isPositionPlayed(unsigned int x, unsigned int y) {
	// checks if a certain position is played

	if (board[x][y] == EMPTY_CELL) {
		return false;
	}
	else {
		return true;
	}
}

bool Board::isFullBoard() {
	// loop through every cell in the board and see if they are all played

	for (unsigned int x = 0; x < MAX_SIZE; x++) {
		for (unsigned int y = 0; y < MAX_SIZE; y++) {
			if (!isPositionPlayed(x, y)) {
				return false;
			}
		}
	}

	return true;
}

bool Board::playerWon(int signOfPlayer) {
	// check if the current player won

	unsigned int row = 0; // used for diagonals
	int signsFound; // the signs that are equal to the sign to search for
	
	// rows
	for (unsigned int x = 0; x < MAX_SIZE; x++) {

		signsFound = 0; // rest the counter for each row
		for (unsigned int y = 0; y < MAX_SIZE; y++) {

			// check if the given position has the sign of the current user
			if (board[x][y] == signOfPlayer) {
				signsFound += 1;
			}

			// Tic-Tac-Toe 3 in a row
			if (signsFound == WINNING_NUMBER) {
				return true;
			}
		}
	}	
	
	// columns
	for (unsigned int y = 0; y < MAX_SIZE; y++) {

		signsFound = 0;
		for (unsigned int x = 0; x < MAX_SIZE; x++) {

			if (board[x][y] == signOfPlayer) {
				signsFound += 1;
			}

			if (signsFound == WINNING_NUMBER) {
				return true;
			}
		}
	}

	// diag1
	signsFound = 0;

	for (unsigned int y = 0; y < MAX_SIZE; y++) {
		if (board[row][y] == signOfPlayer) {
			signsFound += 1;
		}

		if (signsFound == WINNING_NUMBER) {
			return true;
		}

		row += 1;
	}

	//diag2
	signsFound = 0;
	row = (MAX_SIZE - 1);

	for (unsigned int y = 0; y < MAX_SIZE; y++) {
		if (board[row][y] == signOfPlayer) {
			signsFound += 1;
		}

		if (signsFound == WINNING_NUMBER) {
			return true;
		}

		row -= 1;
	}
	
	return false;
}

bool Board::isActive() {
	if (isTerminated) {
		return false;
	}
	else {
		return true;
	}
}

std::string Board::getPlayerSign() {
	// return the sign of the current active player

	if (isXTurn) {
		return "X";
	}
	else {
		return "O";
	}
}