#include "task.h"

task::task(int _tid, int _uid, int _serviceTime)
{
	tid = _tid;
	uid = _uid;
	serviceTime = _serviceTime;
}

int task::getTID() const
{
	return tid;
}

string task::getType() const
{
	return "regular";
}

void task::print() const
{
	cout << "tid = " << tid << ", uid = " << uid << ", Service Time = " << serviceTime << endl;
}