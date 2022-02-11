#include "realTimeTask.h"

// Call the overloaded constructor for the task class from the initialization section
// of the overloaded constructor for the realTimeTask class
realTimeTask::realTimeTask(int _tid, int _uid, int _serviceTime, int _deadline, bool _isPeriodic, bool _hasImplicitDeadline) : task(_tid, _uid, _serviceTime)
{

	deadline = _deadline;
	isPeriodic = _isPeriodic;
	hasImplicitDeadline = _hasImplicitDeadline;
}

string realTimeTask::getType() const
{
	return "real-time";
}

void realTimeTask::print() const
{
	cout << "tid = " << tid << ", uid = " << uid << ", WCET = " << serviceTime << ", Deadline = " << deadline << ", Real-time Task Type = ";
	if (isPeriodic == true)
		cout << "Periodic";
	else
		cout << "Aperiodic";
	cout << ", Implicit Deadline = ";
	if (hasImplicitDeadline == true)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}