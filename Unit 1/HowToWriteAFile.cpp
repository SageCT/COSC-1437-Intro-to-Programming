// write to an ASCII file
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("test.txt");

	myfile << "I am writing to the file.\n";

	myfile.close();
	return 0;
}
