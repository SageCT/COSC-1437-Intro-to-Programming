// Add the Include Guard
#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int moviesAdded;

void printMenu()
{
	std::cout << std::endl;
	std::cout << "Menu:" << std::endl;
	std::cout << "A - Add Movie" << std::endl;
	std::cout << "R - Remove Movie" << std::endl;
	std::cout << "S - Sort Movies" << std::endl;
	std::cout << "O - Output Movie Info" << std::endl;
	std::cout << "C - Output Catalog Info" << std::endl;
	std::cout << "Q - Quit Program" << std::endl
			  << std::endl;
	std::cout << "Choose an option: ";
}

void printMovieInfo(const string &mn, int yr, const string &gen)
{
	std::cout << std::endl;
	std::cout << "Name: " << mn << std::endl;
	std::cout << "Year: " << yr << std::endl;
	std::cout << "Genre: " << gen << std::endl;
}

// Write the definition and implementation of the printCatalog function here
void printCatalog(vector<string> &mn, vector<int> &yr, vector<string> &gen)
{
	for (int x = 0; x < moviesAdded; ++x)
	{
		printMovieInfo(mn[x], yr[x], gen[x]);
	}
}
// Write the definition and implementation of the findMovie function here
int findMovie(string selectedMovie, vector<string> nm)
{
	for (int x = 0; x < nm.size(); x++)
		if (nm.at(x) == selectedMovie)
			return x;

	return -1;
}
// Write the definition and implementation of the addMovie function here
void addMovie(string newMovie, int newYear, string newGenre, vector<string> &nm, vector<int> &yr, vector<string> &gen)
{
	nm.push_back(newMovie);
	yr.push_back(newYear);
	gen.push_back(newGenre);

	moviesAdded++;
}
// Write the definition and implementation of the removeMovie function here
bool removeMovie(string selectedMovie, vector<string> &nm, vector<int> &yr, vector<string> &gen)
{
	int movieFound = findMovie(selectedMovie, nm);
	if (movieFound >= 0)
	{
		nm[movieFound].erase();
		yr.erase(yr.begin() + movieFound);
		gen[movieFound].erase();
		moviesAdded--;
		return true;
	}
	return false;
}
// Write the definition and implementation of the movieInfo function here
void movieInfo(string selectedMovie, vector<string> &nm, vector<int> &yr, vector<string> &gen)
{
	int movieFound = findMovie(selectedMovie, nm);

	if (movieFound >= 0)
	{
		printMovieInfo(nm[movieFound], yr[movieFound], gen[movieFound]);
	}

	else
		std::cout << "Cannot find " << selectedMovie << std::endl;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap(string *x, string *y)
{
	string temp = *x;
	*x = *y;
	*y = temp;
}
// You must use the following std::cout statement if the movie is not in the catalog:
// std::cout << "Cannot find " << /*movie name variable identifier*/ << std::endl;

void sortCatalog(vector<string> &nm, vector<int> &yr, vector<string> &gen)
{
	vector<int> temp;
	int n = moviesAdded;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			if (yr[j] > yr[j + 1])
			{
				swap(&yr[j], &yr[j + 1]);
				swap(&nm[j], &nm[j + 1]);
				swap(&gen[j], &gen[j + 1]);
			}
	}
}
#endif