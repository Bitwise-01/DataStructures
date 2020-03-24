#include <string>
#include <iostream>

struct MovieData{
	int yearReleased;
	std::string title;
	double runningTime;
	std::string director;

	MovieData(std::string mTitle, std::string mDirec, int mYR, double mTime) {
		if (mTitle == "" || mTitle == " ") {
			title = "No title";
		}
		else {
			title = mTitle;
		}

		if (mDirec == "" || mDirec == " ") {
			 director = "No director";
		}
		else {
			director = mDirec;
		}

		if (mYR <= 0) {
			mYR = 2001;
		}
		else {
			mYR = mYR;
		}

		if (mTime <= 0) {
			mTime = 120;
		}
		else {
			runningTime = mTime;
		}
	}; 
};

void displayMovie(MovieData movie);

int main() {

	MovieData movie1("The Martian", "My Dad", 2015, 106.9);
	MovieData movie2("Need for speed", "My Dad", 2014, 107.98);
	
	displayMovie(movie1);
	displayMovie(movie2);
		
	system("pause");
	return 0;
}

void displayMovie(MovieData movie) {
	std::cout << "Title: " << movie.title << std::endl;
	std::cout << "Director: " << movie.director << std::endl;
	std::cout << "Year Released: " << movie.yearReleased << std::endl;
	std::cout << "Run Time: " << movie.runningTime << std::endl;
}