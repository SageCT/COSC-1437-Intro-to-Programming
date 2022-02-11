#include "Time.h"

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(int h, int m, int s)
{
	if (h >= 0 && h <= 23)
	{
		hour = h;
	}
	else
	{
		hour = 0;
	}
	if (m >= 0 && m <= 59)
	{
		minute = m;
	}
	else
	{
		minute = 0;
	}
	if (s >= 0 && s <= 59)
	{
		second = s;
	}
	else
	{
		second = 0;
	}
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

string Time::toString() const
{
	return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}

const Time Time::operator+(const Time &other) const
{
	return (secondsToTime(timeToSeconds() + other.timeToSeconds()));
}

const Time Time::operator-(const Time &other) const
{
	int lhsSeconds = timeToSeconds();
	int rhsSeconds = other.timeToSeconds();
	if (lhsSeconds < rhsSeconds)
		lhsSeconds = lhsSeconds + 86400;
	return (secondsToTime(lhsSeconds - rhsSeconds));
}

bool Time::operator<(const Time &other) const
{
	return (timeToSeconds() < other.timeToSeconds());
}

bool Time::operator>(const Time &other) const
{
	return (timeToSeconds() > other.timeToSeconds());
}

bool Time::operator==(const Time &other) const
{
	return (timeToSeconds() == other.timeToSeconds());
}
