#ifndef BIRTHDAY
#define BIRTHDAY
#include "Event.h"

class Birthday : public Event
{
private:
	string gifts;

public:
	Birthday(string de, string l, const Time &t, const Date &d, string g);
	virtual ~Birthday() {}
	string getGifts() const;
	virtual string getType() const;
	virtual void printSummary() const;
};

#endif