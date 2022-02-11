#include <iostream>

using namespace std;

int main()
{
	// write your program here
	int numbers[6];
	int evens[6];
	int y;

	int size = sizeof(numbers) / sizeof(*numbers);
	for (int x = 0; x < 6; x++)
		cin >> numbers[x];

	y = 0;
	for (int x = 0; x < 6; x++)
	{
		if (numbers[x] % 2 == 0)
		{
			evens[y] = numbers[x];
			y++;
		}
	}

	for (int x = 0; x < sizeof(numbers) / sizeof(*numbers); x++)
	{
		if (evens[x] != 0)
			cout << evens[x] << " ";
	}

	return 0;
}