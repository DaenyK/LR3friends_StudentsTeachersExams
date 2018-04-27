#ifndef _TEACHER_H_
#define _TEACHER_H_
#include "librarys.h"

class teacher
{
private:
	string surname;
	string name;
	int age;
	string gender;
	string pulpit;

public:
	teacher();
	teacher(string surname, string name, int age, string gender, string pulpit);
	teacher(const teacher & obj);
	virtual ~teacher() {};

	int getAge() { return age; }
	string getSname() { return surname; }
	void printInfo();

	friend class Exam;

	friend void printInfoTeachers(teacher *t, int size);


	friend bool operator==(teacher t, string pulpit);

	bool operator>(teacher obj);

	friend void  operator >> (istream & is, teacher& t);
};


#endif#

