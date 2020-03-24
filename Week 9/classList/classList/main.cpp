#include <iostream>
#include "listObj.h"

constexpr int KILL_CODE = -99;
void displayMenu();

int main() {

	listObj list; // list object
	Player player; // used for creating players

	char choice;
	bool response;
	int userInput;
	int indexOfName;
    std::string name;
	std::string oldName;
	std::string newName;

	do { // loop until user enter the kill code

		displayMenu();
		std::cout << "Enter an option or enter " << KILL_CODE << " to exit: ";
		std::cin >> userInput;

		if (userInput != KILL_CODE) {

			system("cls");
			switch (userInput)
			{

			case 1: // check if the list is full
				if (list.isFull()) {
					std::cout << "The list is full" << std::endl;
				}
				else {
					std::cout << "The list is not full" << std::endl;
				}
				break;

			case 2: // modify

				std::cout << "Enter the old name: ";
				std::cin >> oldName;

				std::cout << "Enter the new name: ";
				std::cin >> newName;

				response = list.modifyPlayer(oldName, newName);

				if (!response) {
					std::cout << "Failed to modify" << std::endl;
				}
				else {
					std::cout << "Successfully modify" << std::endl;
				}

				break;

			case 3: // search the list

				std::cout << "Enter the name to search for: ";
				std::cin >> name;
				// search for name in the list
				indexOfName = list.search(name);

				if (indexOfName != -1) { // means the name was found
					std::cout << "The index of the name " << name << " is " << indexOfName << std::endl;
				}
				else {
					std::cout << "The name is not in the list" << std::endl;
				}
				break;

			case 4: // check empty
				if (list.isEmpty()) {
					std::cout << "The list is empty" << std::endl;
				}
				else {
					std::cout << "The list is not empty" << std::endl;
				}
				break;

			case 5: // add to list

				std::cout << "Enter the name of the player: ";
				std::cin >> player.nameP;

				std::cout << "Enter player's order in the game: ";
				std::cin >> player.orderInGame;

				std::cout << "Enter player's description: ";
				std::cin >> player.descP;

				std::cout << "Enter if player is active, Y for Yes and N for No: ";
				std::cin >> choice;
				
				if (choice == 'Y') {
					player.isActivePlayer = true;
				}
				else {
					player.isActivePlayer = false;
				}

				std::cout << "Enter player's role in the game: ";
				std::cin >> player.roleInGame;

				list.addToList(player);
				break;

			case 6: // display list
				list.display();
				break;

			case 7: // display list size
				std::cout << "The size of the list is " << list.size() << std::endl;
				break;

			case 8: // empty the list
				list.clear();
				break;

			case 9: // remove player from the list
				bool response;

				list.display();
				std::cout << "\nEnter the name of the player you wish to remove: ";
				std::cin >> name;

				response = list.removeFromList(name);

				if (!response) {
					std::cout << "Failed to remove player" << std::endl;
				}
				else {
					std::cout << "Remove player successfully" << std::endl;
				}

				break;
			default:
				break;
			}

			system("pause");
		}

	} while (userInput != KILL_CODE);
	system("pause");

	return 0;
}

void displayMenu() {

	system("cls");
	std::string menu[10] = {
		"IsFull",
		"Modify",
		"Search",
		"IsEmpty",
		"Add a player",
		"Display list",
		"Get list size",
		"Empty the list",
		"Remove a player",
	};

	for (int n = 0; n < 5; n++) {
		std::cout << (n + 1) << ". " << menu[n];

		if (menu[n + 5] != "") {
			std::cout << "\t " << (n + 6) << ". " << menu[n + 5];
		}
		
		std::cout << std::endl;
	}
	std::cout << std::endl;

}