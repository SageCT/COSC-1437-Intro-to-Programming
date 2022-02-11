#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string filename;
	ifstream fileI; // Define an ifstream variable
	cin >> filename;
	fileI.open(filename); // Open the file here

	// Check if the file is open
	if (fileI.is_open())
	{
		cout << "The file " << filename << " is now open." << endl;
		fileI.close();
	}
	else
		cout << "The file " << filename << " does not exist." << endl;
	return 0;
}