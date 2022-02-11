#include <iostream>
#include <vector>
#include "Movie.h"
#include "Catalog.h"

using namespace std;

int main()
{
   int numMovies;
	cin >> numMovies;
	string ratingType;
	cin >> ratingType;
	string name, genre;
	int year;
	if (ratingType == "int") {
		vector<Movie<int>> catalog;
		int rating;
		for (int i = 0; i < numMovies; i++) {
		   cin.ignore();
		   getline(cin, name);
			cin >> year >> genre >> rating;
			catalog.push_back(Movie<int>(name, year, genre, rating));
		}
		Catalog<int> c(catalog);
		cout << "getBestMovie()" << endl;
		try {
		   c.getBestMovie().printMovieInfo();
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		cout << "\ngetWorstMovie()" << endl;
		try {
		   c.getWorstMovie().printMovieInfo();
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}	
		cout << "\ngetMovieInfo()" << endl;
		try {
		   c.getMovieInfo("Error");
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		try {
		   c.getMovieInfo("Free Guy");
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		cout << "\nprintMoviesWithRating()" << endl;
		try {
		   c.printMoviesWithRating(5);
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		vector<Movie<int>> m = c.getCatalog();
		if (m.size() != 0) {
		   cout << "\naddRating()" << endl;
		   try {
		      m[0].addRating(-10);
		      cout << m[0].getRating() << endl;
		   }
   		catch (runtime_error &e) {
   			cout << e.what() << endl;
   		}
   		try {
		      m[0].addRating(2);
		      cout << m[0].getRating() << endl;
		   }
   		catch (runtime_error &e) {
   			cout << e.what() << endl;
   		}
	   }
	   cout << "\nsortMoviesByRating()" << endl;
	   try {
		   c.sortMoviesByRating();
	   }
      catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		 c.printCatalog();
	}
	else if (ratingType == "double") {
		vector<Movie<double>> catalog;
		double rating;
		for (int i = 0; i < numMovies; i++) {
		   cin.ignore();
		   getline(cin, name);
			cin >> year >> genre >> rating;
			catalog.push_back(Movie<double>(name, year, genre, rating));
		}
		Catalog<double> c(catalog);
		cout << "getBestMovie()" << endl;
		try {
		   c.getBestMovie().printMovieInfo();
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		cout << "\ngetWorstMovie()" << endl;
		try {
		   c.getWorstMovie().printMovieInfo();
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}	
		cout << "\ngetMovieInfo()" << endl;
		try {
		   c.getMovieInfo("Error");
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		try {
		   c.getMovieInfo("Free Guy");
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		cout << "\nprintMoviesWithRating()" << endl;
		try {
		   c.printMoviesWithRating(7.1);
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		vector<Movie<double>> m = c.getCatalog();
		if (m.size() != 0) {
		   cout << "\naddRating()" << endl;
		   try {
		      m[0].addRating(-10.9);
		      cout << m[0].getRating() << endl;
		   }
   		catch (runtime_error &e) {
   			cout << e.what() << endl;
   		}
   		try {
		      m[0].addRating(2.3);
		      cout << m[0].getRating() << endl;
		   }
   		catch (runtime_error &e) {
   			cout << e.what() << endl;
   		}
	   }
	   cout << "\nsortMoviesByRating()" << endl;
	   try {
		   c.sortMoviesByRating();
	   }
      catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		 c.printCatalog();
	}
	else {
		vector<Movie<char>> catalog;
		char rating;
		for (int i = 0; i < numMovies; i++) {
		   cin.ignore();
		   getline(cin, name);
			cin >> year >> genre >> rating;
			catalog.push_back(Movie<char>(name, year, genre, rating));
		}
		Catalog<char> c(catalog);
		cout << "getBestMovie()" << endl;
		try {
		   c.getBestMovie().printMovieInfo();
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		cout << "\ngetWorstMovie()" << endl;
		try {
		   c.getWorstMovie().printMovieInfo();
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}	
		cout << "\ngetMovieInfo()" << endl;
		try {
		   c.getMovieInfo("Error");
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		try {
		   c.getMovieInfo("Free Guy");
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		cout << "\nprintMoviesWithRating()" << endl;
		try {
		   c.printMoviesWithRating('F');
		}
		catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		vector<Movie<char>> m = c.getCatalog();
		if (m.size() != 0) {
		   cout << "\naddRating()" << endl;
   		try {
		      m[0].addRating(char(1));
		      cout << m[0].getRating() << endl;
		   }
   		catch (runtime_error &e) {
   			cout << e.what() << endl;
   		}
	   }
	   cout << "\nsortMoviesByRating()" << endl;
	   try {
		   c.sortMoviesByRating();
	   }
      catch (runtime_error &e) {
			cout << e.what() << endl;
		}
		 c.printCatalog();
	}
   return 0;
}