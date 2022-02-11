#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
// include necessary libraries

using namespace std;

// Define the structure "movie" here
struct movie
{
	string name;
	int year;
	string genre;
};

void printMenu()
{
	cout << endl;
	cout << "Menu:" << endl;
	cout << "A - Add Movie" << endl;
	cout << "R - Remove Movie" << endl;
	cout << "O - Output Movie Info" << endl;
	cout << "C - Output Catalog Info" << endl;
	cout << "F - Read file" << endl;
	cout << "W - Write file" << endl;
	cout << "Q - Quit Program" << endl;
	cout << "Choose an option: ";
}

void printMovieInfo(const string &nm, int yr, const string &gen)
{
	cout << endl;
	cout << "Name: " << nm << endl;
	cout << "Year: " << yr << endl;
	cout << "Genre: " << gen << endl;
}

// Write the definition and implementation of the printCatalog function here
void printCatalog(vector<movie> movies)
{
	for (int x = 0; x < movies.size(); x++)
	{
		printMovieInfo(movies.at(x).name, movies.at(x).year, movies.at(x).genre);
	}
}

// Write the definition and implementation of the findMovie function here
int findMovie(string selectedMovie, vector<movie> movies)
{
	for (int x = 0; x < movies.size(); x++)
		if (movies.at(x).name == selectedMovie)
			return x;

	return -1;
}
// Write the definition and implementation of the addMovie function here
void addMovie(string name, int year, string genre, vector<movie> &movies)
{
	movie newMovie;

	newMovie.name = name;
	newMovie.year = year;
	newMovie.genre = genre;

	movies.push_back(newMovie);
}

// Write the definition implementation of the removeMovie function here
bool removeMovie(string selectedMovie, vector<movie> movies)
{
	int movieFound = findMovie(selectedMovie, movies);

	if (movieFound > 0)
	{
		movies.erase(movies.begin() + movieFound);
		return true;
	}

	return false;
}

// Write the definition and implementation of the movieInfo function here
void movieInfo(string selectedMovie, vector<movie> movies)
{
	int movieFound = findMovie(selectedMovie, movies);
	if (movieFound > 0)
		printMovieInfo(movies.at(movieFound).name, movies.at(movieFound).year, movies.at(movieFound).genre);

	// You must use the following cout statement if the movie is not in the catalog:
	else
		cout << "Cannot find " << selectedMovie << endl;
}

// Write the definition and implementation of the readFromFile function here
bool readFromFile(string fileName, vector<movie> &movies)
{
	ifstream myFile;
	string line;
	int yr;
	movie tempMovie;

	myFile.open(fileName);
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			tempMovie.name = line;

			myFile >> yr;
			myFile.ignore(256, '\n');
			tempMovie.year = yr;

			getline(myFile, line);
			tempMovie.genre = line;

			movies.push_back(tempMovie);
		}
		myFile.close();
		return true;
	}
	return false;
}

// Write the definition and implementation of the writeToFile function here

bool writeToFile(string fileName, vector<movie> movies)
{
	ofstream myFile(fileName);
	if (myFile.is_open())
	{
		for (int x = 0; x < movies.size(); x++)
		{
			myFile << movies.at(x).name << '\n';
			myFile << movies.at(x).year << '\n';
			myFile << movies.at(x).genre << '\n';
		}
		myFile.close();

		return true;
	}
	return false;
}

#endif