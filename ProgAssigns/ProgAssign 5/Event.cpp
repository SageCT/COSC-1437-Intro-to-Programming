#include "Event.h"

// Default constructor
Event::Event() : description(""), location(""), time(), date() {}

// Non-default constructor
Event::Event(string d, string l, Time t, Date dt) : description(d), location(l), time(t), date(dt) {}

// hasPassed
bool Event::hasPassed(const Date eDate, const Time eTime) const
{
	if (this->date < eDate)
		return true;
	if (this->date == eDate && (this->time < eTime || this->time == eTime))
		return true;
	return false;
}
