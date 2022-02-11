#ifndef CONCERT
#define CONCERT
#include "Event.h"

class Concert : public Event
{
private:
	int tickets;

public:
	Concert(string de, string l, const Time &t, const Date &d, int ti);
	virtual ~Concert() {}
	int getTickets() const;
	virtual string getType() const;
	virtual void printSummary() const;
};

#endif