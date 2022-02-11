#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Catalog
{
private:
	vector<Movie<T>> movies;

public:
	Catalog(vector<Movie<T>> movies);
	vector<Movie<T>> getCatalog();
	void printCatalog();
	// Write the definition of the sortMoviesByRating() function here
	void sortMoviesByRating();
	// Write the definition of the getBestMovie() function here
	Movie<T> getBestMovie();
	// Write the definition of the getWorstMovie() function here
	Movie<T> getWorstMovie();
	// Write the definition of the printMoviesWithRating() function here
	void printMoviesWithRating(T);
	// Write the definition of the getMovieInfo() function here
	void getMovieInfo(string);

	void swap(Movie<T> &m1, Movie<T> &m2);
};

template <typename T>
Catalog<T>::Catalog(vector<Movie<T>> movies)
{
	this->movies = movies;
}
template <typename T>
vector<Movie<T>> Catalog<T>::getCatalog()
{
	return movies;
}
template <typename T>
void Catalog<T>::printCatalog()
{
	for (Movie<T> m : movies)
	{
		m.printMovieInfo();
	}
}

// Write the implementation of the getBestMovie() function here
template <typename T>
Movie<T> Catalog<T>::getBestMovie()
{
	if (movies.size() == 0)
		throw runtime_error("No movies in catalog.");

	Movie<T> Max = movies.at(0);
	unsigned int index;
	for (unsigned int i = 0; i < movies.size(); i++)
	{
		if (movies.at(i).getRating() > Max.getRating())
			Max = movies.at(i);
	}
	for (unsigned int i = 0; i < movies.size(); i++)
	{
		if (Max.getRating() == movies.at(i).getRating())
		{
			index = i;
			break;
		}
	}
	return movies.at(index);
}

// Write the implementation of the getWorstMovie() function here
template <typename T>
Movie<T> Catalog<T>::getWorstMovie()
{
	if (movies.size() == 0)
	{
		throw runtime_error("No movies in catalog.");
	}
	unsigned int index;
	Movie<T> Min = movies.at(0);
	for (unsigned int i = 0; i < movies.size(); i++)
	{
		if (Min.getRating() > movies.at(i).getRating())
			Min = movies.at(i);
	}
	for (unsigned int i = 0; i < movies.size(); i++)
	{
		if (Min.getName() == movies.at(i).getName())
		{
			index = i;
		}
	}
	return movies.at(index);
}
// Write the implementation of the printMoviesWithRating() function here
template <typename T>
void Catalog<T>::printMoviesWithRating(T Rating_search)
{
	if (movies.size() == 0)
		throw runtime_error("No movies in catalog.");
	for (unsigned int i = 0; i < movies.size(); i++)
	{
		if (movies.at(i).getRating() >= Rating_search)
			movies.at(i).printMovieInfo();
	}
}
// Write the implementation of the getMovieInfo() function here
template <typename T>
void Catalog<T>::getMovieInfo(string nm)
{
	if (movies.size() == 0)
	{
		throw runtime_error("No movies in catalog.");
	}
	bool Not_found = true;
	for (unsigned int i = 1; i < movies.size(); i++)
	{
		if (movies.at(i).getName() == nm)
		{
			movies.at(i).printMovieInfo();
			Not_found = false;
		}
	}
	if (Not_found)
	{
		throw runtime_error("Movie not found in catalog.");
	}
}

///**************************
template <typename T>
void Catalog<T>::sortMoviesByRating()
{
	// checks if the movies vector is empty
	if (movies.begin() == movies.end())
		throw runtime_error("No movies in catalog.");
	bool Not_Sorted = true;
	do
	{
		// for_loop Bubble Sorting
		for (unsigned int i = 0; i < movies.size() - 1; i++)
		{
			for (unsigned int j = i; j < movies.size() - 1; j++)
			{
				if (movies.at(j).getRating() > movies.at(j + 1).getRating())
				{
					swap(movies.at(j), movies.at(j + 1));
					Not_Sorted = false;
				}

				else if (movies.at(j).getRating() == movies.at(j + 1).getRating() &&
						 movies.at(j).getName() > movies.at(j + 1).getName())
				{
					swap(movies.at(j), movies.at(j + 1));
					Not_Sorted = false;
				}
			}
		}
		// check if sorted or Not
		for (unsigned int i = 0; i < movies.size() - 1; i++)
		{
			if (movies.at(i).getRating() > movies.at(i + 1).getRating())
			{
				Not_Sorted = true;
			}
			else if (movies.at(i).getRating() == movies.at(i + 1).getRating() && movies.at(i).getName() > movies.at(i + 1).getName())
				Not_Sorted = true;
		}

	} while (Not_Sorted);
}

template <typename T>
void Catalog<T>::swap(Movie<T> &m1, Movie<T> &m2) // should pass
{
	Movie<T> temp = m1;
	m1 = m2;
	m2 = temp;
}
#endif
