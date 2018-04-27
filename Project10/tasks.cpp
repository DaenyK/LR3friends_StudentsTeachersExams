#include "student.h"
#include "teacher.h"
#include "exam.h"

void main()
{
	setlocale(LC_ALL, "Russian");

	int bckr, t;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

	short nz, answer;
	do {
		student * s;
		int  studentNum;
		studentNum = 11;
		ifstream inFile("in.txt");
		s = new student[studentNum];
		for (int i = 0; i < studentNum; i++)
			inFile >> s[i];
		SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 46));
		cout << "name\tsurname\tage\tgender\tgroup\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		printStudents(s, studentNum);
		inFile.close();

		teacher *t;
		int  teacherNum;
		teacherNum = 4;
		inFile.open("teacher.txt");
		t = new teacher[teacherNum];
		for (int i = 0; i < teacherNum; i++)
		{
			inFile >> t[i];
		}
		SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));
		cout << "name\tsurname\tage\tgender\tdepartment\n";
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		printInfoTeachers(t, teacherNum);
		inFile.close();


		Exam *es;
		int examNum = teacherNum*studentNum;
		es = new Exam[examNum];
		string sub[4] = { "c++", "pholisophy", "python", "history" };
		double grade;


		cout << "\n-----------------------------------\n";
		cout << "1 - ��������� �������� ����" << endl
			<< "2 - ��������� �������� ����" << endl
			<< "3 - ������� ��������� �� �������" << endl
			<< "4 - ������ �������� �������������" << endl
			<< "5 - �������� �������������" << endl
			<< "6 - ������� �������������� �� ��������" << endl
			<< "7 - ������ ���������, ������� ����� ������� �� 5, � �������� ������������� � �� ������ ��������" << endl
			<< "8 - ������ ���������, ������� ����� ������� �� 2 � ������, � �������� ������������� � �� ������ ��������.\n\n";
		cin >> nz;
		switch (nz)
		{

		case 1:
		{
			cout << "����� ���������� � ��������� �������� ����\n";

			SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));
			cout << "name\tsurname\tage\tgender\tgroup\n";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			for (int i = 0; i < 11; i++)
			{
				if ("man" == s[i])
					s[i].printInfo();
			}
			cout << endl;
		}break;
		case 2:
		{
			cout << "����� ���������� � ��������� �������� ����\n";

			SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));
			cout << "name\tsurname\tage\tgender\tgroup\n";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			for (int i = 0; i < 11; i++)
			{
				if ("woman" == s[i])
					s[i].printInfo();
			}
			cout << endl;
		}break;

		case 3:
		{
			int groupNumber, count = 0;
			cout << "����� ���������� � ��������� �� �������\n";
			cout << "������� ����� ����� ������, ����� ������� ���������� � ���������: ";
			cin >> groupNumber;
			SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));
			cout << "\nname\tsurname\tage\tgender\tgroup\n";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			for (int i = 0; i < 11; i++)
			{
				if (groupNumber == s[i])
				{
					s[i].printInfo();
					count++;
				}
			}
			if (count == 0) cout << "���������� � ����� ��������� ���\n";
			cout << endl;
		}break;

		case 4:
		{
			int min = 75, minIndex;
			cout << "����� ���������� � ����� ������� �������������\n";
			SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));
			cout << "\nname\tsurname\tage\tgender\tdepartment\n";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			for (int i = 0; i < teacherNum; i++)
			{
				if (t[i].getAge() < min)
				{
					min = t[i].getAge();
					minIndex = i;
				}
			}
			t[minIndex].printInfo();
			cout << endl;
		}break;

		case 5:
		{
			int max = 0, maxIndex;
			cout << "����� ���������� � ����� ������� �������������\n";
			SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));
			cout << "\nname\tsurname\tage\tgender\tdepartment\n";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			for (int i = 0; i < teacherNum; i++)
			{
				if (t[i].getAge() > max)
				{
					max = t[i].getAge();
					maxIndex = i;
				}
			}
			t[maxIndex].printInfo();
			cout << endl;
		}break;

		case 6:
		{
			string caf;
			cout << "����� ���������� � �������������� �� ��������\n";
			cout << "������� �������� �������: ";
			cin >> caf;

			SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));
			cout << "\nname\tsurname\tage\tgender\tdepartment\n";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			for (int i = 0; i < teacherNum; i++)
			{
				if(t[i]==caf)
					t[i].printInfo();
			}
			cout << endl;
		}break;

		case 7:
		{
			int k = 0;
			cout << "c����� ���������, ������� ����� ������� �� 5\n";
			cout << "\nsubject\tStudSname\tTeacher\tgrade\n";
			for (int i = 0; i < teacherNum; i++)
			{
				for (int j = 0; j < studentNum; j++)
				{
					grade = 1.0 + rand() % 5;
					es[k].create_exam(sub[i], s[j], t[i], grade);
					if (grade == 5)
						es[k].printInfo();
					k++;
				}
			}
			//printExam(es, examNum);
		}break;

		case 8:
		{
			int k = 0;
			cout << "c����� ���������, ������� ����� ������� �� 2 ��� ������\n";
			cout << "\nsubject\tStudSname\tTeacher\tgrade\n";
			for (int i = 0; i < teacherNum; i++)
			{
				for (int j = 0; j < studentNum; j++)
				{
					grade = 1.0 + rand() % 5;
					es[k].create_exam(sub[i], s[j], t[i], grade);
					if (grade <= 2)
						es[k].printInfo();
					k++;
				}
			}
			//printExam(es, examNum);
		}break;

		}
		cout << "������ ����������?1/0 ";
		cin >> answer;

		system("cls");
	} while (answer == 1);
	system("pause");

}