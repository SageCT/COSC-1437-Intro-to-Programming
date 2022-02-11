#ifndef EVENT
#define EVENT

#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;

// Add the virtual qualifier and change member functions to pure virtual functions when needed.

class Event
{
protected:
	string description;
	string location;
	Time time;
	Date date;
	string type;

public:
	Event(string de, string l, const Time &t, const Date &d);
	virtual ~Event() {}
	string getDescription() const;
	void setDescription(string s);
	string getLocation() const;
	Time getTime() const;
	Date getDate() const;
	virtual string getType() const = 0;
	bool operator>(const Event &RHS) const;
	bool operator<(const Event &RHS) const;
	bool hasPassed(Date d, Time t) const;
	virtual void printSummary() const = 0;
};

#endif