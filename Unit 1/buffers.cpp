#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	ifstream inputFile;
	int content;
	char c;
	inputFile.open("test.txt");
	if (inputFile.is_open())
	{
		while (inputFile >> content)
		{
			cout << content << " ";
			inputFile >> c;
		}
	}
	inputFile.close();

	return 0;
}