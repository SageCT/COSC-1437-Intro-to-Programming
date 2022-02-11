#include "Schedule.h"
#include <iostream>
#include "Birthday.h"
#include "Concert.h"

using namespace std;

Schedule::Schedule(int numEvents, Time t, Date d)
{
	size = numEvents;
	numBd = 0;
	numC = 0;
	for (int i = 0; i < MAXNUMEVENTS; i++)
		events[i] = nullptr;
	time = t;
	date = d;
}

// Implement the destructor
Schedule::~Schedule()
{
	for (int i = 0; i < size; i++)
		if (events[i] != nullptr)
			delete events[i];
}

// Implement the copy constructor
Schedule::Schedule(const Schedule &other)
{
	size = other.size;
	numBd = other.numBd;
	numC = other.numC;
	time = other.time;
	date = other.date;

	for (int i = 0; i < MAXNUMEVENTS; i++)
		events[i] = nullptr;
		
	setEvents(size, other.events);
}

// Implement the copy assignment operator
Schedule &Schedule::operator=(const Schedule &other)
{
	for (int i = 0; i < MAXNUMEVENTS; i++)
	{
		if (events[i] != nullptr)
		{
			delete events[i];
			events[i] = nullptr;
		}
	}
	size = other.size;
	numBd = other.numBd;
	numC = other.numC;

	setEvents(other.size, other.events);
	return *this;
}

// Implement the setEvents function
void Schedule::setEvents(int s, Event *const newEvents[])
{
	size = s; // have to add this, it would be used when it's not for copy constructor or copy assignment
	for (int i = 0; i < s; i++)
	{
		events[i] = nullptr;
		if (newEvents[i] != nullptr)
		{
			if (newEvents[i]->getType() == "birthday")
				events[i] = new Birthday((Birthday &)*newEvents[i]);

			else if (newEvents[i]->getType() == "concert")
				events[i] = new Concert((Concert &)*newEvents[i]);
		}
	}
}

Event **Schedule::getEvents()
{
	return events;
}

void Schedule::eventsFromInput()
{
	string type;
	string description;
	string location;
	string blank;
	int hr, m, s;
	int d, mt, y;
	string unique;
	int tickets;
	for (int i = 0; i < size; i++)
	{
		getline(cin, type);
		getline(cin, description);
		getline(cin, location);
		cin >> hr >> m >> s >> d >> mt >> y;
		getline(cin, blank);
		if (type == "birthday")
		{
			getline(cin, unique);
			events[i] = new Birthday(description, location, Time(hr, m, s), Date(d, mt, y), unique);
			numBd++;
		}
		else
		{
			cin >> tickets;
			getline(cin, blank);
			events[i] = new Concert(description, location, Time(hr, m, s), Date(d, mt, y), tickets);
			numC++;
		}
	}
}

Time Schedule::getTime() const
{
	return time;
}

Date Schedule::getDate() const
{
	return date;
}

Date Schedule::getFirstEventDate() const
{
	int index = 0;
	Event *firstEvent = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (events[i] != nullptr)
		{
			index = i;
			break;
		}
	}
	if (index < size)
	{
		firstEvent = events[index];
		for (int i = index + 1; i < size; i++)
		{
			if (events[i] != nullptr)
			{
				if (*events[i] < *firstEvent)
					firstEvent = events[i];
			}
		}
	}
	if (firstEvent != nullptr)
		return firstEvent->getDate();
	else
		return Date();
}

// Implement the getLastEventDate function
Date Schedule::getLastEventDate() const
{
	int index = 0;
	Event *lastEvent = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (events[i] != nullptr)
		{
			index = i;
			break;
		}
	}
	if (index < size)
	{
		lastEvent = events[index];
		for (int i = index + 1; i < size; i++)
		{
			if (events[i] != nullptr)
			{
				if (*events[i] > *lastEvent)
					lastEvent = events[i];
			}
		}
	}
	if (lastEvent != nullptr)
		return lastEvent->getDate();
	else
		return Date();
}

// Implement the eventsPassed funciton
int Schedule::eventsPassed() const
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (events[i] != nullptr)
		{
			if (events[i]->getDate() < getDate())
				count++;
			else if (events[i]->getDate() > getDate())
				continue;
			else if (events[i]->getTime() < getTime() || events[i]->getTime() == getTime())
				count++;
		}
	}
	return count;
}

// Implement the printSummary function
void Schedule::printSummary() const
{
	cout << "Today is " << date.toString() << " " << time.toString() << "\n"
		 << getFirstEventDate().toString() << "---" << getLastEventDate().toString() << "\n"
		 << eventsPassed() << " events have passed."
		 << "\n"
		 << endl;

	for (int i = 0; i < size; i++)
	{
		if (events[i]->getType() == "birthday")
		{
			Birthday bd = (Birthday &)*events[i];
			bd.printSummary();
			cout << endl;
		}

		else if (events[i]->getType() == "concert")
		{
			Concert ct = (Concert &)*events[i];
			ct.printSummary();
			cout << endl;
		}
	}
}