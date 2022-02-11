#ifndef REALTIMETASK_H
#define REALTIMETASK_H

#include "task.h"

class realTimeTask : public task // Implement public inheritance from the task class
{
private:
	int deadline;
	bool isPeriodic;
	bool hasImplicitDeadline;

public:
	realTimeTask(int, int, int, int, bool, bool);
	~realTimeTask() {}
	virtual string getType() const;
	virtual void print() const;
};

#endif