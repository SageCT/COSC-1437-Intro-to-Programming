#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::iostream;
using std::vector;

int main()
{
	//Write your solution here

	//Declaring the vectors for the strings
	vector<string> catalogName;
	vector<string> catalogYear;
	vector<string> catalogGenre;

	//Declaring the necessary variables for each case
	char userImp;
	string stringImp;
	string selectedMovie;
	int count;
	int moviesAdded = 0;
	bool running = true;

	std::cout << endl;

	while (running)
	{
		std::cout << "Menu:\nA - Add Movie\nR - Remove Movie\nO - Output Movie Info\nC - Output Catalog Info\nQ - Quit Program\n\n";
		std::cout << "Choose an option: ";
		std::cin >> userImp;

		switch (userImp)
		{
		case 'A':
		case 'a':
			std::cout << "Movie Name: ";
			std::cin >> stringImp;
			catalogName.push_back(stringImp);

			std::cout << "Year: ";
			std::cin >> stringImp;
			catalogYear.push_back(stringImp);

			std::cout << "Genre: ";
			std::cin >> stringImp;
			catalogGenre.push_back(stringImp);

			moviesAdded++;
			std::cout << "Added " << catalogName.back() << " to the catalog\n"
					  << endl;

			break;

		case 'R':
		case 'r':
			std::cout << "Movie Name:";
			std::cin >> selectedMovie;

			count = 0;

			for (int x = 0; x < moviesAdded; x++)
			{
				if (catalogName[x] == selectedMovie && count < 1)
				{
					catalogName[x].erase();
					catalogYear[x].erase();
					catalogGenre[x].erase();
					count++;
					moviesAdded--;
				}
			}
			if (count == 1)
				std::cout << "Removed " << selectedMovie << " from catalog\n\n";
			else
				std::cout << "Cannot find " << selectedMovie << "\n\n";

			break;

		case 'O':
		case 'o':
			std::cout << "Movie Name: \n";
			std::cin >> selectedMovie;
			count = 0;

			for (int x = 0; x < catalogName.size(); x++)
			{
				if (catalogName[x] == selectedMovie && count < 1)
				{
					std::cout << "Name: " << catalogName[x] << endl;
					std::cout << "Year: " << catalogYear[x] << endl;
					std::cout << "Genre: " << catalogGenre[x] << "\n\n";

					count++;
				}
			}
			if (count == 0)
				std::cout << "Cannot find " << selectedMovie << "\n\n";

			break;

		case 'C':
		case 'c':
			std::cout << "There are " << moviesAdded << " movies in the catalog\n\n";
			for (int x = 0; x < catalogName.size(); ++x)
			{
				if (catalogName[x] != "")
				{
					std::cout << "Name: " << catalogName[x] << endl;
					std::cout << "Year: " << catalogYear[x] << endl;
					std::cout << "Genre: " << catalogGenre[x] << "\n\n";
				}
			}

			break;

		case 'Q':
		case 'q':
			std::cout << "Quitting Program";
			running = false;

			break;
		}
	}
	return 0;
}