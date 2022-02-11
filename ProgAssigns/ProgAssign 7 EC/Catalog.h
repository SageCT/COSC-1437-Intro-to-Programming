#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Movie.h"

using namespace std;

template <typename T>
class Catalog
{
private:
	vector<Movie<T>> movies;

public:
	Catalog(vector<Movie<T>> movies);
	vector<Movie<T>> getCatalog() const;
	void printCatalog() const;
	// Write the definition of the sortMoviesByRating() function here
	void sortMoviesByRating();
	// Write te definition of the getBestMovie() function here
	Movie<T> getBestMovie() const;
	// Write the definition of the getWorstMovie() function here
	Movie<T> getWorstMovie() const;
	// Write the definition of the printMoviesWithRating() function here
	void printMoviesWithRating(const T value) const;
	// Write the definition of the getMovieInfo() function here
	void getMovieInfo(const string value) const;
	void swap(Movie<T> &m1, Movie<T> &m2);
};

template <typename T>
Catalog<T>::Catalog(vector<Movie<T>> movies)
{
	this->movies = movies;
}
template <typename T>
vector<Movie<T>> Catalog<T>::getCatalog() const
{
	return movies;
}
template <typename T>
void Catalog<T>::printCatalog() const
{
	for (Movie<T> m : movies)
	{
		m.printMovieInfo();
	}
}

// Write the implementation of the sortMoviesByRating() function here
template <typename T>
void Catalog<T>::sortMoviesByRating()
{
	// checks if the movies vector is empty
	if (movies.begin() == movies.end())
		throw std::runtime_error("No movies in catalog.");

	bool unsorted = false;
	do
	{
		for (int i = 0; i < movies.size() - 1; i++)
		{
			for (int j = i; j < movies.size() - 1; j++)
			{
				if (movies.at(i).getRating() > movies.at(j + 1).getRating())
				{
					swap(movies.at(i), movies.at(j + 1));
					unsorted = false;
				}

				else if (movies.at(j).getRating() == movies.at(j + 1).getRating() &&
						 movies.at(j).getName() > movies.at(j + 1).getName())
				{
					swap(movies.at(j), movies.at(j + 1));
					unsorted = false;
				}
			}
		}

		// check if sorted
		for (int i = 0; i < movies.size() - 1; i++)
		{
			if (movies.at(i).getRating() > movies.at(i + 1).getRating())
				unsorted = true;

			else if (movies.at(i).getRating() == movies.at(i + 1).getRating() && movies.at(i).getName() > movies.at(i + 1).getName())
				unsorted = true;
		}
	} while (unsorted);
}

template <typename T>
void Catalog<T>::swap(Movie<T> &m1, Movie<T> &m2)
{
	Movie<T> temp = m1;
	m1 = m2;
	m2 = temp;
}

// Write the implementation of the getBestMovie() function here
template <typename T>
Movie<T> Catalog<T>::getBestMovie() const
{
	if (movies.begin() == movies.end())
		throw std::runtime_error("No movies in catalog.");
	Movie<T> highest = movies.at(0);

	for (Movie<T> m : movies)
		if (highest.getRating() < m.getRating())
			highest = m;

	return highest;
}

// Write the implementation of the getWorstMovie() function here
template <typename T>
Movie<T> Catalog<T>::getWorstMovie() const
{
	if (movies.begin() == movies.end())
		throw std::runtime_error("No movies in catalog.");

	Movie<T> lowest = movies.at(0);

	for (Movie<T> m : movies)
		if (lowest.getRating() > m.getRating())
			lowest = m;
	return lowest;
}

// Write the implementation of the printMoviesWithRating() function here
template <typename T>
void Catalog<T>::printMoviesWithRating(const T value) const
{
	bool found = false;
	for (Movie<T> m : movies)
	{
		if (m.getRating() > value)
		{
			found = true;
			m.printMovieInfo();
		}
	}
	if (!found)
	{
		throw std::runtime_error("No movies in catalog.");
	}
}

// Write the implementation of the getMovieInfo() function here
template <typename T>
void Catalog<T>::getMovieInfo(const string value) const
{
	bool found = false;
	if (movies.begin() == movies.end())
		throw std::runtime_error("No movies in catalog.");

	for (Movie<T> m : movies)
	{
		if (m.getName() == value)
		{
			found = true;
			m.printMovieInfo();
		}
	}
	if (!found)
		throw std::runtime_error("Movie not found in catalog.");
}

#endif