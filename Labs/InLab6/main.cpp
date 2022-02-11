#include <iostream>
#include "Car.h"
using namespace std;

int main(int argc, const char *argv[])
{
	int userYear;
	int userPrice;
	int userCurrentYear;
	Car myCar;

	cin >> userYear;
	cin >> userPrice;
	cin >> userCurrentYear;

	myCar.SetModelYear(userYear);
	myCar.SetPurchasePrice(userPrice);
	myCar.CalcCurrentValue(userCurrentYear);

	string parts[3] = {"engine", "door", "window"};
	myCar.setParts(3, parts);

	myCar.PrintInfo();

	return 0;
}