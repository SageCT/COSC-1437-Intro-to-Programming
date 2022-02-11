#ifndef EVENT
#define EVENT

#include <string>
#include "Date.h"
#include "Time.h"

using namespace std;

class Event
{
private:
	string description;
	string location;
	Time time;
	Date date;

public:
	Event();
	Event(string d, string l, Time t, Date dt);
	bool hasPassed(const Date eDate, const Time eTime) const;
};

#endif