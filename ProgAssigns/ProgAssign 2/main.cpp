#include <iostream>

using namespace std;

int main()
{
	int rHumi, cTime, tTemp;
	bool change = false;
	cout << "Enter the current relative humidity: ";
	cin >> rHumi;
	cout << "Enter the current time: ";
	cin >> cTime;

	if (cTime >= 6 && cTime < 8)
		tTemp = 76;

	else if (cTime >= 8 && cTime < 18)
		tTemp = 78;

	else if (cTime >= 18 && cTime < 21)
		tTemp = 75;

	else if (cTime >= 21 && cTime < 6)
		tTemp = 72;
	cout << "The current target temperature is " << tTemp << "F" << endl;

	if (rHumi > 65 && tTemp == 78)
	{
		tTemp = 73;
		change = true;
	}
	else if (rHumi >= 60 && rHumi <= 65 && tTemp == 78)
	{
		tTemp = 76;
		change = true;
	}
	else if (rHumi < 60 && tTemp == 76)
	{
		tTemp = 78;
		change = true;
	}
	if (change)
		cout << "Changing target temperature to " << tTemp << "F" << endl;

	return 0;
}