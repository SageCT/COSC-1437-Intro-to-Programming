#include "Date.h"

// Default Constructor
Date::Date() : day(1), month(1), year(0) {}

// Constructor with parameters
Date::Date(int d, int m, int y)
{
	if (d < 1 || d > 31)
		d = 0;
	if (m < 1 || m > 12)
		m = 0;
	if (y < 0)
		y = 0;
	this->day = d;
	this->month = m;
	this->year = y;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date::setDay(int h) { day = h; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int s) { year = s; }

// dateToDays
int Date::dateToDays() const
{
	return (getDay() + getMonth() * 31 + getYear() * 372);
}

// daysToDate
const Date Date::daysToDate(int ndays) const
{
	Date temp;
	temp.year = ndays / 372;
	ndays %= 372;
	temp.month = ndays / 31;
	ndays %= 31;
	temp.day = ndays;
	if (temp.day == 0)
	{
		temp.month -= 1;
		temp.day = 31;
	}
	return temp;
}

// toString
string Date::toString() const
{
	string temp;
	temp.append(to_string(this->getDay()));
	temp.append("/");
	temp.append(to_string(this->getMonth()));
	temp.append("/");
	temp.append(to_string(this->getYear()));

	return temp;
}
// +
const Date Date::operator+(int ndays) const
{
	int totalD = this->dateToDays() + ndays;
	return daysToDate(totalD);
}

// -
const Date Date::operator-(int ndays) const
{
	return daysToDate(this->dateToDays() - ndays);
}

// <
bool Date::operator<(const Date &other) const
{
	return this->dateToDays() < other.dateToDays();
}

// >
bool Date::operator>(const Date &other) const
{
	return this->dateToDays() > other.dateToDays();
}

// ==
bool Date::operator==(const Date &other) const
{
	return this->dateToDays() == other.dateToDays();
}