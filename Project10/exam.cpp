#include"Exam.h"

Exam::Exam(string subject, string student_sname, string teacher_sname, double grade) {
	this->subject = subject;
	this->student_sname = student_sname;
	this->teacher_sname = teacher_sname;
	this->grade = grade;
}

Exam::Exam(string Subject, student sobj, teacher tobj, double grade) {
	this->subject = subject;
	this->student_sname = sobj.surname;
	this->teacher_sname = tobj.surname;
	this->grade = grade;
}
Exam::Exam(const Exam& obj) {
	this->subject = obj.subject;
	this->student_sname = obj.student_sname;
	this->teacher_sname = obj.teacher_sname;
	this->grade = obj.grade;

}
void Exam::create_exam(string Subject, student sobj, teacher tobj, double grade) {
	this->subject = Subject;
	this->student_sname = sobj.surname;
	this->teacher_sname = tobj.surname;
	this->grade = grade;
}
Exam:: ~Exam() {

}

void printExam(Exam*es, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << es[i].subject << "\t" << es[i].student_sname << "\t"
			<< es[i].teacher_sname << "\t" << es[i].grade << endl;

		/*cout << setw(30) << es[i].subject << setw(15) << es[i].student_sname
			<< setw(15) << es[i].teacher_sname << setw(7) << es[i].grade << endl;*/
	}
}
