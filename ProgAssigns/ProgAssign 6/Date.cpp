#include "Date.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 0;
}

Date::Date(int d, int m, int y)
{
    if (d >= 1 && d <= 31)
    {
        day = d;
    }
    else
    {
        day = 0;
    }
    if (m >= 1 && m <= 12)
    {
        month = m;
    }
    else
    {
        month = 0;
    }
    if (y >= 0)
    {
        year = y;
    }
    else
    {
        year = 0;
    }
}

string Date::toString() const
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date::setDay(int h) { day = h; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int s) { year = s; }

int Date::dateToDays() const
{
    return (getDay()-1 + (getMonth()-1) * 31 + getYear() * 372);
}

const Date Date::daysToDate(int ndays) const
{
    int yearD = ndays / 372;
    ndays = ndays % 372;
    int monthD = ndays / 31;
    ndays = ndays % 31;
    int dayD = ndays;
    return Date(dayD+1, monthD+1, yearD);
}

const Date Date::operator+(const int ndays) const
{

    return (daysToDate(dateToDays() + ndays));
}

const Date Date::operator-(const int ndays) const
{
    return (daysToDate(dateToDays() - ndays));
}

bool Date::operator<(const Date &other) const
{
   return (dateToDays() < other.dateToDays());
}

bool Date::operator>(const Date &other) const
{
   return (dateToDays() > other.dateToDays());
}

bool Date::operator==(const Date &other) const
{
    return (dateToDays() == other.dateToDays());
}