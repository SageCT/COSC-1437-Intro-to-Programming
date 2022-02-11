#include "taskList.h"

int taskList::findAvailablePosition()
{
	int pos = -1;
	for (int i = 0; i < MAXNUMBEROFTASKS; i++)
	{
		if (list[i] == nullptr)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

taskList::taskList()
{
	for (int i = 0; i < MAXNUMBEROFTASKS; i++)
		list[i] = nullptr;
}

taskList::~taskList()
{
	for (int i = 0; i < MAXNUMBEROFTASKS; i++)
	{
		if (list[i] != nullptr)
		{
			delete list[i];
			list[i] = nullptr;
		}
	}
}

taskList::taskList(const taskList &objToCopy)
{
	for (int i = 0; i < MAXNUMBEROFTASKS; i++)
	{
		if (objToCopy.list[i] != nullptr)
		{
			if (objToCopy.list[i]->getType() == "regular")
				list[i] = new task(*objToCopy.list[i]);
			else
				list[i] = new realTimeTask((realTimeTask &)*objToCopy.list[i]);
		}
		else
			list[i] = nullptr;
	}
}

taskList &taskList::operator=(const taskList &RHS)
{
	if (this != &RHS)
	{
		for (int i = 0; i < MAXNUMBEROFTASKS; i++)
		{
			if (list[i] != nullptr)
			{
				delete list[i];
				list[i] = nullptr;
			}
			if (RHS.list[i] != nullptr)
			{
				if (RHS.list[i]->getType() == "regular")
					list[i] = new task(*RHS.list[i]);
				else
					list[i] = new realTimeTask((realTimeTask &)*RHS.list[i]);
			}
		}
	}
	return *this;
}

// Write the implementation of the addTask member function here
void taskList::addTask(const task &tk)
{
	int pos = findAvailablePosition();
	list[pos] = new task(tk);
}
// Write the implementation of the removeTask member function here
void taskList::removeTask(int pos)
{

	if (list[pos] != nullptr)
	{
		list[pos] = nullptr;
		delete list[pos];
	}
}
// Write the implementation of the print member function here
void taskList::print() const
{
	for (int i = 0; i < MAXNUMBEROFTASKS; i++)
	{
		if (list[i] != nullptr)
			if (list[i]->getType() == "real-time")
			{
				realTimeTask *temp = new realTimeTask((realTimeTask &)*list[i]);
				temp->print();
			}
	}

	for (int i = 0; i < MAXNUMBEROFTASKS; i++)
	{
		if (list[i] != nullptr)
			if (list[i]->getType() == "regular")
			{
				task *temp2 = new task((task &)*list[i]);
				temp2->print();
			}
	}
}