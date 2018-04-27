#include "teacher.h"

teacher::teacher()
{
	surname = "";
	name = "";
	age = 0;
	gender = "";
	pulpit = "";
}

teacher::teacher(string surname, string name, int age, string gender, string pulpit)
{
	this->surname = surname;
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->pulpit = pulpit;
}


teacher::teacher(const teacher & obj)
{
	this->surname = obj.surname;
	this->name = obj.name;
	this->age = obj.age;
	this->gender = obj.gender;
	this->pulpit = obj.pulpit;
}

void teacher::printInfo()
{
		cout << name << "\t" << surname << "\t" << age << "\t" << gender << "\t" << pulpit << endl;
}

void printInfoTeachers(teacher *t, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << t[i].name << "\t" << t[i].surname << "\t" << t[i].age << "\t"
			<< t[i].gender << "\t" << t[i].pulpit << endl;
	}
}

bool operator==(teacher t, string pulpit)
{
	return (t.pulpit == pulpit);
}

bool teacher :: operator>(teacher obj)
{
	return (this->pulpit == obj.pulpit);

}

void  operator >> (istream & is, teacher&ts)
{
	//string str;
	//getline(is, str, '\n');
	//getline(is, ts.name, '\\');
	//getline(is, ts.surname, '\\');
	is >> ts.name >> ts.surname >> ts.age >> ts.gender;
	getline(is, ts.pulpit, ' ');
	getline(is, ts.pulpit, '\\');

}
