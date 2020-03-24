#include <string>
#include <fstream> 
#include <iostream>

constexpr int EXIT_CODE = -99;
constexpr unsigned int MAX_ACCOUNTS = 250;
int findAccount(int accountNumber, int accounts[MAX_ACCOUNTS], int totalAccountsRead);
void readInAccounts(std::string path, int accounts[MAX_ACCOUNTS], int& totalAccounts);

int main() {

	std::string filePath;
	int totalAccountsRead = 0;
	int accounts[MAX_ACCOUNTS];

	std::cout << "Enter the path to your file: ";
	std::cin >> filePath;

	readInAccounts(filePath, accounts, totalAccountsRead);

	int index;
	int userInput;

	do {

		system("cls");
		std::cout << "Enter an account number to search for (enter " << EXIT_CODE << " to exit): ";
		std::cin >> userInput;

		if (userInput != EXIT_CODE) {

			index = findAccount(userInput, accounts, totalAccountsRead);

			if (index != -1) { // -1 means account was not found
				std::cout << "Account is located at the index: " << index << std::endl;  
			}
			else {
				std::cout << "Account is not in the file" << std::endl;
			}
			system("pause");
		}

	} while (userInput != EXIT_CODE);

	return 0;
}

void readInAccounts(std::string path, int accounts[MAX_ACCOUNTS], int& totalAccounts) {
	int accountNumber;

	std::ifstream infile;
	infile.open(path);

	while (infile >> accountNumber) {
		if (accountNumber != -1) {
			accounts[totalAccounts] = accountNumber;
			totalAccounts += 1;
		}
	}

	infile.close();
}

int findAccount(int accountNumber, int accounts[MAX_ACCOUNTS], int totalAccounts)
{
	for (unsigned int n = 0; n < totalAccounts; n++) {
		if (accounts[n] == accountNumber) {
			return n;
		}
	}

	return -1; // account was not found
}