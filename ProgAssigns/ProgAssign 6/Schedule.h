#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "Birthday.h"
#include "Concert.h"
#include "Event.h"
#include <iostream>

using namespace std;

const int MAXNUMEVENTS = 100;

class Schedule{
    private:
        int size;
        int numBd;
        int numC;
        Event* events[MAXNUMEVENTS];
        Time time;
        Date date;
    public:
        Schedule(int numEvents, Time t, Date d);
        ~Schedule();
        Schedule(const Schedule &other);
        Schedule &operator=(const Schedule &other);
        void eventsFromInput();
        void setEvents(int s, Event * const newEvents[]);
        Event** getEvents();
        Time getTime() const;
        Date getDate() const;
        Date getFirstEventDate() const;
        Date getLastEventDate() const;
        int eventsPassed() const;
        void printSummary() const;
};

#endif