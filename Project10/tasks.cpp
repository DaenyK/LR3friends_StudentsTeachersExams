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
		cout << "1 - Студентов мужского пола" << endl
			<< "2 - Студентов женского пола" << endl
			<< "3 - Вывести студентов по группам" << endl
			<< "4 - Самого молодого преподавателя" << endl
			<< "5 - Старшего преподавателя" << endl
			<< "6 - Вывести преподавателей по кафедрам" << endl
			<< "7 - Список студентов, которые сдали экзамен на 5, у которого преподавателя и по какому предмету" << endl
			<< "8 - Список студентов, которые сдали экзамен на 2 и меньше, у которого преподавателя и по какому предмету.\n\n";
		cin >> nz;
		switch (nz)
		{

		case 1:
		{
			cout << "вывод информации о студентах мужского пола\n";

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
			cout << "вывод информации о студентах женского пола\n";

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
			cout << "вывод информации о студентах по группам\n";
			cout << "введите номер любой группы, чтобы вывести информацию о студентах: ";
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
			if (count == 0) cout << "информации о таких студентах нет\n";
			cout << endl;
		}break;

		case 4:
		{
			int min = 75, minIndex;
			cout << "вывод информации о самом молодом преподавателе\n";
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
			cout << "вывод информации о самом старшем преподавателе\n";
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
			cout << "вывод информации о преподавателях по кафедрам\n";
			cout << "введите название кафедры: ";
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
			cout << "cписок студентов, которые сдали экзамен на 5\n";
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
			cout << "cписок студентов, которые сдали экзамен на 2 или меньше\n";
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
		cout << "хотите продолжить?1/0 ";
		cin >> answer;

		system("cls");
	} while (answer == 1);
	system("pause");

}