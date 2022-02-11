#include <iostream>
#include "Student.h"
int main()
{
	int option;
	cin >> option;
	switch (option)
	{
	case 0:
	{
		student S1("", "", 0, 0);
		S1.setfname("Veronica");
		S1.setlname("Rincon");
		S1.setage(15);
		S1.setid(1234);
		cout << S1.getfname() << " " << S1.getlname() << ", " << S1.getage() << " " << S1.getid() << endl;
		break;
	}
	case 1:
	{
		student S1("Carlos", "Rincon", 45, 1234);
		cout << S1 << endl;
		break;
	}
	case 2:
	{
		student S1("Carlos", "Rincon", 45, 1234);
		student S2("Laura", "Fereira", 45, 1233);
		if (S1 > S2 == false)
		{
			cout << "Incorrect implementation of the > operator" << endl;
			return 1;
		}
		if (S1 < S2 == true)
		{
			cout << "Incorrect implementation of the < operator" << endl;
			return 1;
		}
		cout << "Correct implementation of the < and > operators" << endl;
		break;
	}
	}
	return 0;
}