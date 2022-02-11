// Simple class to hold student information
#include "Student.h"

#include <iostream>
#include <string>

using namespace std;

Student::Student()
{
	SetName("Louie");
	SetGPA(1.0);
	// complete the constructor
}

void Student::SetName(string newName)
{
	name = newName;
	// FIXME: complete SetName function
}

string Student::GetName()
{
	return name;
}

void Student::SetGPA(double newGPA)
{
	gpa = newGPA;
}

double Student::GetGPA()
{
	return gpa;
}
// FIXME: Add 3 more functions