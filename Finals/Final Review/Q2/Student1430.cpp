#include "Student1430.h"

// Write the implementation of the Student1430 class here
Student1430::Student1430()
{
	firstName = "";
	lastName = "";
	average = 0;
	for (int x = 0; x < 3; x++)
		exams[x] = {0};
	updateAverage();
}

Student1430::Student1430(string f, string l, int e[])
{
	firstName = f;
	lastName = l;
	for (int x = 0; x < 3; x++)
		exams[x] = e[x];
	updateAverage();
}

string Student1430::getFirstName() { return firstName; }
string Student1430::getLastName() { return lastName; }
double Student1430::getAverage()
{
	updateAverage();
	return average;
}
void Student1430::setFirstName(string name) { firstName = name; }
void Student1430::setLastName(string l) { lastName = l; }
void Student1430::setExamGrade(int grade, int pos) { exams[pos - 1] = grade; }

void Student1430::updateAverage()
{
	double avg = 0;
	for (int x = 0; x < 4; x++)
		avg += exams[x];
	avg /= 4;
	average = avg;
}
string Student1430::finalGrade()
{
	updateAverage();
	if (average >= 90)
		return "A";
	else if (average < 90 && average >= 80)
		return "B";
	else if (average < 80 && average >= 70)
		return "C";
	else if (average < 70 && average >= 60)
		return "D";
	return "F";
}
