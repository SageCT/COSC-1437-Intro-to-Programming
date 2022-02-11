#include <iostream>

using namespace std;

int main()
{
	// Write your program here

	int nums;

	int numer, denom, wholeNum, convNumer;

	cin >> nums;

	for (int x = 0; x < nums * 2; x++)
	{
		cin >> numer >> denom;
		wholeNum = numer / denom;
		convNumer = numer % denom;
		cout << numer << "/" << denom << " "
			 << "="
			 << " " << wholeNum << " " << convNumer << "/" << denom << endl;
	}

	// cout << numer / denom << endl;
	// cout << numer % denom << endl;

	return 0;
}