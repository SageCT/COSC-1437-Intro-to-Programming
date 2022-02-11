#include "functions.h"

using namespace std;

int main()
{
	char option;
	vector<string> movieName;
	vector<int> movieYear;
	vector<string> movieGenre;
	while (true)
	{
		printMenu();
		std::cin >> option;
		std::cin.ignore();
		switch (option)
		{
		case 'A':
		case 'a':
		{
			string nm;
			int year;
			string genre;
			std::cout << "Movie Name: ";
			getline(std::cin, nm);
			std::cout << "Year: ";
			std::cin >> year;
			std::cout << "Genre: ";
			std::cin >> genre;
			addMovie(nm, year, genre, movieName, movieYear, movieGenre); // Call the addMovie function here
			std::cout << "Added " << nm << " to the catalog" << std::endl;
			break;
		}
		case 'R':
		case 'r':
		{
			string mn;
			std::cout << "Movie Name:";
			std::getline(std::cin, mn);
			bool found;
			found = removeMovie(mn, movieName, movieYear, movieGenre);
			if (found == false)
				std::cout << "Cannot find " << mn << std::endl;
			else
				std::cout << "Removed " << mn << " from catalog" << std::endl;
			break;
		}
		case 'S':
		case 's':
		{
			sortCatalog(movieName, movieYear, movieGenre); // Call the sortCatalog function here
			std::cout << "Movies have been sorted by year." << std::endl;
			break;
		}
		case 'O':
		case 'o':
		{
			string mn;
			std::cout << "Movie Name: ";
			std::getline(std::cin, mn);
			std::cout << std::endl;
			movieInfo(mn, movieName, movieYear, movieGenre); // Call the movieInfo function here
			break;
		}
		case 'C':
		case 'c':
		{
			std::cout << "There are " << movieName.size() << " movies in the catalog" << std::endl;
			printCatalog(movieName, movieYear, movieGenre); // Call the printCatalog function here
			break;
		}
		}
		if (option == 'Q' || option == 'q')
		{
			std::cout << "Quitting Program";
			break;
		}
	}
}
