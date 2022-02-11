#include <iostream>
#include "Event.h"
#include "Birthday.h"
#include "Schedule.h"

using namespace std;

int main(){
    int numEvents, hours, minutes, seconds, day, month, year;
    string blank;
    cin >> numEvents >> hours >> minutes >> seconds >> day >> month >> year;
    getline(cin, blank);
    Schedule schedule(numEvents, Time(hours,minutes,seconds), Date(day, month, year));
    schedule.eventsFromInput();
    schedule.printSummary();
}