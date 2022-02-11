#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

int main()
{

	vector<movie> movies;
	char option;

	while (true)
	{
		printMenu();
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 'A':
		{
			string nm;
			int year;
			string genre;
			cout << "Movie Name: ";
			getline(cin, nm);
			cout << "Year: ";
			cin >> year;
			cout << "Genre: ";
			cin >> genre;

			addMovie(nm, year, genre, movies); // call you addMovie() here
			cout << "Added " << nm << " to the catalog" << endl;
			break;
		}
		case 'R':
		{
			string mn;
			cout << "Movie Name:";
			getline(cin, mn);
			bool found;
			found = removeMovie(mn, movies); // call you removeMovie()here
			if (found == false)
				cout
					<< "Cannot find " << mn << endl;
			else
				cout << "Removed " << mn << " from catalog" << endl;
			break;
		}
		case 'O':
		{
			string mn;
			cout << "Movie Name: ";
			getline(cin, mn);
			cout << endl;
			movieInfo(mn, movies); // call you movieInfo function here
			break;
		}
		case 'C':
		{
			cout << "There are " << movies.size() << " movies in the catalog" << endl;
			printCatalog(movies); // Call the printCatalog function here
			break;
		}
		case 'F':
		{
			string inputFile;
			bool isOpen;
			cin >> inputFile;
			cout << "Reading catalog info from " << inputFile << endl;
			isOpen = readFromFile(inputFile, movies); // call you readFromFile() in here
			if (isOpen == false)
				cout
					<< "File not found" << endl;
			break;
		}
		case 'W':
		{
			string outputFile;
			bool isOpen;
			cin >> outputFile;
			cout << "Writing catalog info to " << outputFile << endl;
			isOpen = writeToFile(outputFile, movies); // call you writeToFile() in here
			if (isOpen == false)
				cout
					<< "File not found" << endl;
			break;
		}
		}
		if (option == 'Q')
		{
			cout << "Quitting Program";
			break;
		}
	}
}
