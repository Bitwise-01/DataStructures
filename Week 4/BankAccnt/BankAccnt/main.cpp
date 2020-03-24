constexpr unsigned int max_columns = 2; // [accnt num, accnt balance]
constexpr int last_account_number = -99; 
constexpr unsigned int first_column = 0; // accnt num
constexpr unsigned int second_column = 1; // accnt balance
constexpr unsigned int max_accounts = 100; 
constexpr unsigned int accounts_at_a_time = 10;

#include <string>
#include <fstream>
#include <iostream>

using namespace std;
void write_to_file(string output_file, int total_rows, double accounts[max_accounts][max_columns]);
void add_accounts(int accounts_read, double accounts_chunks[accounts_at_a_time][max_columns], double(&accounts)[max_accounts][max_columns]);
double update_balance(int accnt_number, double balance, string transaction_types[max_accounts], double transaction_amounts[max_accounts][max_columns]);
int read_transactions_file(string transaction_file, string(&transaction_types)[max_accounts], double(&transaction_amounts)[max_accounts][max_columns]);
void read_accounts(string transaction_types[max_accounts], double transaction_amounts[max_accounts][max_columns], double(&accounts)[max_accounts][max_columns]);
void read_accounts_file(string accounts_file, string(&transaction_types)[max_accounts], int total_rows, double(&transactions_amounts)[max_accounts][max_columns], double(&accounts)[max_accounts][max_columns]);

int main() {
	int total_rows;
	string transaction_types[max_accounts];
	double accounts[max_accounts][max_columns];
	double transactions_amounts[max_accounts][max_columns];
	string output_file = "C:\\Users\\Mohamed\\Desktop\\Sep18endAcct.txt";
	string transactions_file = "C:\\Users\\Mohamed\\Desktop\\Sep18tx.txt";
	string accounts_file = "C:\\Users\\Mohamed\\Desktop\\Sep18begAcct.txt";

	total_rows = read_transactions_file(transactions_file, transaction_types, transactions_amounts);
	read_accounts_file(accounts_file, transaction_types, total_rows, transactions_amounts, accounts);
	
	cout << "Accnt number\t\tbalance" << endl;
	for (unsigned int row=0; row < total_rows; row++) {
		if(accounts[row][first_column] != last_account_number)
			cout << accounts[row][first_column] << "\t\t\t" << accounts[row][second_column] << endl;
	}
	
	write_to_file(output_file, total_rows, accounts);
	system("pause");
	return 0;
}

void write_to_file(string output_file, int total_rows, double accounts[max_accounts][max_columns]) {
	// this function writes the end balances to a file 

	ofstream outfile;
	outfile.open(output_file);
	outfile << "Accnt number\t\tbalance" << endl;
	for (unsigned int row = 0; row < total_rows; row++) {
		if (accounts[row][first_column] != last_account_number)
			outfile << accounts[row][first_column] << "\t\t\t\t" << accounts[row][second_column] << endl;
	}
}

void add_accounts(int accounts_read, double accounts_chunks[accounts_at_a_time][max_columns], double(&accounts)[max_accounts][max_columns]) {
	// this function takes 10 accounts at a time, and adds those accounts to bigger accounts array.

	unsigned int _row = 0;
	for (unsigned int row = accounts_read; row < accounts_read + accounts_at_a_time; row++) {
		accounts[row][first_column] = accounts_chunks[_row][first_column];
		accounts[row][second_column] = accounts_chunks[_row][second_column];
		_row += 1; // increment through the 10 accounts 
	}
}

double update_balance(int accnt_number, double balance, string transaction_types[max_accounts], double transaction_amounts[max_accounts][max_columns]) {
	// this function updates the the balance of a given account

	double amount; 
	string trans_type;
	int current_accnt_number;
	double new_balance = balance;
	double current_balance = balance;

	for (unsigned int row = 0; row < max_accounts; row++) {
		current_accnt_number = transaction_amounts[row][first_column];
		amount = transaction_amounts[row][second_column];
		trans_type = transaction_types[row];

		if (current_accnt_number == accnt_number) {

			if (trans_type == "dep") {
				new_balance += amount;
			}

			if (trans_type == "wd") {
				new_balance -= amount;
			}
		}
	}
	return new_balance;
}

void read_accounts_file(string accounts_file, string(&transaction_types)[max_accounts], int total_rows, double(&transactions_amounts)[max_accounts][max_columns], double(&accounts)[max_accounts][max_columns]) {
	// this function reads the accounts file 

	string str;
	ifstream infile;
	double balance;
	int accnt_number;
	infile.open(accounts_file);
	int total_accounts_read = 0;
	double account_chunks[accounts_at_a_time][max_columns];

	// get rid of the unwanted strings 
	for (int n = 0; n < 3; n++)
		infile >> str;

	while (total_accounts_read < max_accounts) {

		for (unsigned int row = 0; row < accounts_at_a_time; row++) {
			infile >> accnt_number;
			infile >> balance;

			account_chunks[row][first_column] = accnt_number;
			account_chunks[row][second_column] = balance;
		}

		add_accounts(total_accounts_read, account_chunks, accounts);
		total_accounts_read += accounts_at_a_time;
	}
	read_accounts(transaction_types, transactions_amounts, accounts);
}

void read_accounts(string transaction_types[max_accounts], double transaction_amounts[max_accounts][max_columns], double(&accounts)[max_accounts][max_columns]) {
	// this function manipulates the balance of a given account base on the transaction array

	double balance;
	int accnt_number;
	double new_balance;

	for (unsigned int row = 0; row < max_accounts; row++) {
		accnt_number = accounts[row][first_column];
		balance = accounts[row][second_column];

		for (unsigned int trans_row = 0; trans_row < max_accounts; trans_row++) {
			if (transaction_amounts[trans_row][first_column] == accnt_number) {
				new_balance = update_balance(accnt_number, balance, transaction_types, transaction_amounts);
				accounts[row][second_column] = new_balance;
			}
		}
	}
}

int read_transactions_file(string transaction_file, string(&transaction_types)[max_accounts], double(&transaction_amounts)[max_accounts][max_columns]) {
	// this function reads the transaction file and saves all of the transactions types into a 1D array and all of the account numbers and amount into a 2D array

	string str;
	int row = 0;
	double amount;
	ifstream infile;
	int accnt_number;
	string trans_type;

	infile.open(transaction_file);

	for (int n = 0; n < 4; n++)
		infile >> str;

	while (infile >> accnt_number) { // read until the EOF
		infile >> trans_type;
		infile >> amount;

		transaction_types[row] = trans_type;
		transaction_amounts[row][first_column] = accnt_number;
		transaction_amounts[row][second_column] = amount;
		row += 1; // increment the current row
	}
	return row;
}