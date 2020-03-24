#pragma once
#include <string>
#include <iostream>

constexpr int O = 0;
constexpr int X = 1;
constexpr int EMPTY_CELL = -1;
constexpr int WINNING_NUMBER = 3;
constexpr unsigned int MAX_SIZE = 3; // 3X3 array

class Board
{
private:

	// attributes
	bool isXTurn; 
	bool isTerminated; // keeps track of the state of the game
	int board[MAX_SIZE][MAX_SIZE];

	// methods
	void setBoard();
	bool isFullBoard();
	bool playerWon(int signOfPlayer);
	bool isPositionPlayed(unsigned int x, unsigned int y);

public:
	Board();
	void display();
	bool isActive();
	std::string getPlayerSign();
	void play(unsigned int x, unsigned int y);
};