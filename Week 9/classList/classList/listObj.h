#pragma once
#include <string>
#include <iostream>

constexpr unsigned int MAX_SIZE = 20; // max size of the array

struct Player {
	int orderInGame;
	std::string nameP;
	std::string descP;
	bool isActivePlayer;
	std::string roleInGame;
};

class listObj
{
private:
	unsigned int indexer;
	Player playersList[MAX_SIZE];
	   
public:
	listObj();
	int size();
	void clear();
	bool isFull();
	bool isEmpty();
	void display();
	int search(std::string name);
	bool addToList(Player player);
	bool removeFromList(std::string name);
	bool modifyPlayer(std::string oldName, std::string newName);
};