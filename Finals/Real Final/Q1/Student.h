#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class student
{
private:
	string fname;
	string lname;
	int age;
	int id;

public:
	student(const string &, const string &, int, int);
	string getfname() const;
	string getlname() const;
	int getage() const;
	int getid() const;
	void setfname(const string &);
	void setlname(const string &);
	void setage(int);
	void setid(int);
	friend ostream &operator<<(ostream &, const student &);
	bool operator<(const student &);
	bool operator>(const student &);
};

student::student(const string &fn, const string &ln, int newAge, int newId) : fname(fn), lname(ln), age(newAge), id(newId) {}

string student::getfname() const { return fname; }
string student::getlname() const { return lname; }
int student::getage() const { return age; }
int student::getid() const { return id; }
void student::setfname(const string &fn) { fname = fn; }
void student::setlname(const string &ln) { lname = ln; }
void student::setage(int newAge) { age = newAge; }
void student::setid(int newId) { id = newId; }

std::ostream &operator<<(std::ostream &out, const student &stud)
{
	out << "Name: " << stud.getfname() << " " << stud.getlname() << ", Age: " << stud.getage() << ", ID = " << stud.getid();
	return out;
}

bool student::operator<(const student &other)
{
	return (this->age != other.age) ? (this->age < other.age) : (this->id < other.id);
}

bool student::operator>(const student &other)
{
	return (this->age != other.age) ? (this->age > other.age) : (this->id > other.id);
}

#endif