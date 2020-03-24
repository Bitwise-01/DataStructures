#include "listObj.h"

listObj::listObj()
{
	indexer = 0;
}

bool listObj::addToList(Player player) {

	if (!isFull()) {
		playersList[indexer] = player;
		indexer += 1;
		return true;
	}

	return false;
}

void listObj::display() {
	Player player;
	
	for (unsigned int n = 0; n < indexer; n++) {
		player = playersList[n];
		std::cout << "Name: " << player.nameP << "; ";
		std::cout << "Desc: " << player.descP << "; ";
		std::cout << "Role: " << player.roleInGame << "; ";

		if (player.isActivePlayer) {
			std::cout << "isActive: " << "Yes" << std::endl;
		}
		else {
			std::cout << "isActive: " << "No" << std::endl;
		}
	}
}

bool listObj::removeFromList(std::string name) {

	int index = search(name);
	
	if(index != -1) {
		for (unsigned int n = index; n < indexer; n++) {
			playersList[n] = playersList[n + 1];
		}

		indexer -= 1;
		return true;
	}

	return false;
}

bool listObj::modifyPlayer(std::string oldName, std::string newName) {
	int index = search(oldName); // if it returns a -1 it means the name wasn't found

	if (index != -1) {
		playersList[index].nameP = newName;
		return true;
	}

	return false;
}

int listObj::search(std::string name) {
	for (unsigned int n = 0; n < indexer; n++) {
		if (playersList[n].nameP == name) {
			return n; 
		}
	}

	return -1;
}

bool listObj::isEmpty() {
	if (!indexer) {
		return true;
	}
	else {
		return false;
	}
}

bool listObj::isFull() {
	if (indexer == MAX_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

void listObj::clear() {
	indexer = 0;
}

int listObj::size() {
	return indexer;
}