#include "student.h"

student::student()
{
	name = "";
	surname = "";
	age = 0;
	gender = "man";
	group = 0;
}

student::student(string name, string surname, int age, string gender, int group)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->gender = gender;
	this->group = group;
}

student::student(const student &obj)
{
	this->name = obj.name;
	this->surname = obj.surname;
	this->age = obj.age;
	this->gender = obj.gender;
	this->group = obj.group;
}


void printStudents(student *ss, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ss[i].name << "\t" << ss[i].surname << "\t" << ss[i].age << "\t"
			<< ss[i].gender << "\t" << ss[i].group << endl;
	}
}

//
//void  operator >> (istream & in, student &s)
//{
//	in >> s.name >> s.surname >> s.age >> s.gender >> s.group;
//	//return in;
//}


void  operator >> (istream & in, student &s)
{
	//string str;
	//getline(in, str, '\n');
	//getline(in, s.name, '\\');
	//getline(in, s.surname, '\\');

	in >> s.name>> s.surname>>s.age >> s.gender >> s.group;
}


bool operator==(string male, student obj)
{
	return (male == obj.gender);
}

bool operator==(int numGroup, student obj)
{
	return  (numGroup == obj.group);
}


bool operator!=(string male, student obj)
{
	return (male != obj.gender);
}


bool operator>(int  age, student obj)
{
	return age > obj.age;
}
bool operator<(int  age, student obj)
{
	return age < obj.age;
}


bool student:: operator<(student obj)
{
	return (this->age < obj.age);
}
bool student:: operator>(student obj)
{
	return (this->age > obj.age);
}