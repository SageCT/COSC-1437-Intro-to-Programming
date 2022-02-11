#ifndef TIME
#define TIME

#include <string>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
    int timeToSeconds() const;
    const Time secondsToTime(int s) const;

public:
    Time();
    Time(int h, int m, int s);
    string toString() const;
    int getHour() const;
    void setHour(int h);
    int getMinute() const;
    void setMinute(int m);
    int getSecond() const;
    void setSecond(int s);
    const Time operator+(const Time &other) const;
    const Time operator-(const Time &other) const;
    bool operator<(const Time &other) const;
    bool operator>(const Time &other) const;
    bool operator==(const Time &other) const;
};

#endif