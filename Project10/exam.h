#pragma once
#include "librarys.h"
#include "student.h"
#include "teacher.h"

class student;
class teacher;

class Exam {
	string subject;
	string teacher_sname;
	string student_sname;
	double grade;
public:
	Exam() = default;
	Exam(string, string, string, double);
	Exam(string, student sobj, teacher tobj, double);
	Exam(const Exam&);
	void printInfo()
	{
		cout << subject << "\t" << student_sname << "\t\t" << teacher_sname << "\t" << grade << endl;
	}
	void create_exam(string Subject, student sobj, teacher tobj, double grade);
	virtual ~Exam();

	friend void printExam(Exam*, int);
};

