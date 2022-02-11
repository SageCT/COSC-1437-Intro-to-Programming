#ifndef DATE
#define DATE

#include <string>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    int dateToDays() const;
    const Date daysToDate(int ndays) const;

public:
    Date();
    Date(int d, int m, int y);
    string toString() const;
    int getDay() const;
    void setDay(int d);
    int getMonth() const;
    void setMonth(int m);
    int getYear() const;
    void setYear(int y);
    const Date operator+(int ndays) const;
    const Date operator-(int ndays) const;
    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator==(const Date &other) const;
};

#endif