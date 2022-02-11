#include <iostream>

using namespace std;

double avg(int *scores, int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += scores[i];
	}
	return sum / size;
}

int main()
{
	int numScores = 0;
	cin >> numScores;
	int *scores = new int[numScores];

	for (int i = 0; i < numScores; i++)
	{
		cin >> scores[i];
	}
	cout << avg(scores, numScores);
}
