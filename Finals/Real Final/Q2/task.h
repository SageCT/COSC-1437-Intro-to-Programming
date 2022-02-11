#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

using namespace std;

// Use the virtual qualifier when needed.

class task
{
protected:
	int tid;
	int uid;
	int serviceTime;

public:
	task(int, int, int);
	~task() {}
	int getTID() const;
	virtual string getType() const;
	virtual void print() const;
};

#endif