#include <iostream>
#include <fstream>

using namespace std;
struct movie
{
	string name;
	int year;
	string genre;
};

struct student
{
	string name;
	unsigned int id;
	string major;
	double gpa;
};

int main()
{
	movie catalog2;
	movie catalog;
	catalog.name = "Carlos";
	catalog.year = 1234;
	catalog.genre = "Horror";
	catalog2 = catalog;
	return 0;
}