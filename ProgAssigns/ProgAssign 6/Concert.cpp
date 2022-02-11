#include "Concert.h"
#include <iostream>

Concert::Concert(string de, string l, const Time &t, const Date &d, int ti) : Event(de, l, t, d), tickets(ti)
{
	type = "concert";
}

int Concert::getTickets() const
{
	return tickets;
}

string Concert::getType() const
{
	return type;
}

// Implement the printSummary function
void Concert::printSummary() const
{
	cout << description << "\n"
		 << location << "\n"
		 << "Time: " << time.toString() << "\n"
		 << "Date: " << date.toString() << "\n"
		 << "Tickets: " << tickets << endl;
}