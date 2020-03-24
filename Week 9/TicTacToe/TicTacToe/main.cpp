#include "Board.h"
#include <iostream>

int main() {

	Board board;
	unsigned int x;
	unsigned int y;

	while (board.isActive()) {

		// display the board
		board.display();

		// ask for input
		std::cout << "It's " << board.getPlayerSign() << "'s turn, enter coords x y: ";
		std::cin >> x >> y;

		// play
		board.play(x, y);
	}
	
	system("pause");
	return 0;
}