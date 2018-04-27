#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "librarys.h"

class student
{
	string name;
	string surname;
	int age;
	string gender;
	int group;


public:
	student();
	student(string name, string surname, int age, string gender, int group);
	student(const student &obj);
	virtual ~student() {};

	string getSname() { return surname; }

	friend class Exam;

	bool operator<(student obj);
	bool operator>(student obj);

	friend void printStudents(student *ss, int size);
	void printInfo()
	{
		cout << name << "\t" << surname << "\t" << age << "\t" << gender << "\t" << group << endl;
	}
	friend void  operator >> (istream & in, student& s); // можно вместо istream & использовать void

	friend bool operator==(string male, student obj);
	friend bool operator==(int numGroup, student obj);

	friend bool operator!=(string male, student obj);

	friend bool operator>(int male, student obj);
	friend bool operator<(int male, student obj);



};

#endif