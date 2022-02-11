#include <iostream>

using namespace std;

int main()
{
	// Write your program here
	int num;
	int multiple = 1;
	int counter = 0;
	int divide = 10;
	cin >> num;

	while (num % 10 != 0)
	{
		if (num > 0)
		{
			counter++;
			multiple *= num % 10;
		}
		num /= 10;
	}

	cout << "Number of digits different than zero = " << counter << endl;
	cout << "Multiplication of the digits different than zero = " << multiple;
	return 0;
}