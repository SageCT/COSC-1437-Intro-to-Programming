#ifndef TASKLIST_H
#define TASKLIST_H

#include <iostream>
#include <string>
#include "task.h"
#include "realTimeTask.h"

using namespace std;

const int MAXNUMBEROFTASKS = 100;

class taskList
{
    private:
        task *list[100];
        int findAvailablePosition();
    public:
        taskList();
        ~taskList();
        taskList(const taskList &);
        taskList & operator = (const taskList &);
        void addTask(const task &);
        void removeTask(int);
        void print() const;
};

#endif