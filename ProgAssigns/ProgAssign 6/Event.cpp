#include "Event.h"

Event::Event(string de, string l, const Time &t, const Date &d) : time(t), date(d)
{
    description = de;
    location = l;
}

string Event::getDescription() const{
    return description;
}

void Event::setDescription(string s){
   description = s;   
}

string Event::getLocation() const{
    return location;
}
Time Event::getTime() const{
    return time;
}

Date Event::getDate() const{
    return date;
}

bool Event::operator > (const Event & RHS) const
{
    if (date > RHS.date || (date == RHS.date && time > RHS.time))
        return true;
    return false;
}

bool Event::operator < (const Event & RHS) const
{
    if (date < RHS.date || (date == RHS.date && time < RHS.time))
        return true;
    return false;
}

bool Event::hasPassed(Date d, Time t) const
{
    if (d > date)
    {
        return true;
    }
    else if (d < date)
    {
        return false;
    }
    else
    {
        if (t > time)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}