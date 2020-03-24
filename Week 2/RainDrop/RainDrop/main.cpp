#include <string>
#include <fstream>
#include <iostream>

int main()
{
	double data;
	double average;
	double total = 0; 
	std::string month2;
	std::string month1;
	std::ifstream infile;
	double total_amt = 0;
	std::string file_path;
	std::ofstream outfile;
	std::string out_path = "C:\\Users\\Mohamed\\Desktop\\Rainfall_results.txt";

	std::cout << "Enter path to file: " << std::flush;
	std::cin >> file_path;

	// infile.open("C:\Users\Mohamed\Desktop\Rainfall.txt");
	infile.open(file_path);
	outfile.open(out_path);
	
	infile >> month1;
	infile >> month2;

	while (infile >> data)
	{
		total += data;
		total_amt += 1;
	}

	average = total / total_amt;
	std::cout << "Rain fall for months " << month1 << " - " << month2 << "\n" << std::endl;
	outfile << "Rain fall for months " << month1 << " - " << month2 << "\n" << std::endl;


	std::cout << "Total: " << total << std::endl;
	outfile << "Total: " << total << std::endl;

	std::cout << "Average: " << average << std::endl;
	outfile << "Average: " << average << std::endl;
	
	outfile.close();
	infile.close();
	system("pause");
	return 0;
}