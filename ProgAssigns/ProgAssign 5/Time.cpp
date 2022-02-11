#include "Time.h"

// Default Constructor
Time::Time() : hour(0), minute(0), second(0) {}

// Constructor with parameters
Time::Time(int hour, int minute, int second)
{
	if (hour < 0 || hour > 23)
		hour = 0;
	if (minute < 0 || minute > 59)
		minute = 0;
	if (second < 0 || second > 59)
		second = 0;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }
void Time::setHour(int h) { hour = h; }
void Time::setMinute(int m) { minute = m; }
void Time::setSecond(int s) { second = s; }

int Time::timeToSeconds() const
{
	return (getSecond() + getMinute() * 60 + getHour() * 3600);
}

const Time Time::secondsToTime(int s) const
{
	int resultS = s % 60;
	s /= 60;
	int resultM = s % 60;
	s /= 60;
	int resultH = s % 24;
	return Time(resultH, resultM, resultS);
}

// toString
string Time::toString() const
{
	string temp;
	temp.append(to_string(this->getHour()));
	temp.append(":");
	temp.append(to_string(this->getMinute()));
	temp.append(":");
	temp.append(to_string(this->getSecond()));
	return temp;
}
//  +
const Time Time::operator+(const Time &other) const
{
	return secondsToTime(this->timeToSeconds() + other.timeToSeconds());
}

// -
const Time Time::operator-(const Time &other) const
{
	Time temp = secondsToTime(this->timeToSeconds() - other.timeToSeconds());
	if (this->timeToSeconds() > other.timeToSeconds())
		return temp;
	return (secondsToTime(this->timeToSeconds() - other.timeToSeconds() + 24 * 3600));
}

// <
bool Time::operator<(const Time &other) const
{
	return this->timeToSeconds() < other.timeToSeconds();
}

// >
bool Time::operator>(const Time &other) const
{
	return this->timeToSeconds() > other.timeToSeconds();
}

// ==
bool Time::operator==(const Time &other) const
{
	return this->timeToSeconds() == other.timeToSeconds();
}