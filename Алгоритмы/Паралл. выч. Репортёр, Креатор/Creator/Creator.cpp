#include <conio.h>
#include <fstream>
#include <iostream>
using namespace std;

struct student
{
	char name[10]; // имя студента
	int num; // номер группы
	double grade; // средний балл
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");
	ofstream out;
	out.open(argv[0], ios::out | ios::binary );

	int n;

	cout << "Количество записей: ";
	cin >> n;

	student* stud = new student[n];

	for(int i = 0; i < n; i++)
	{
		cout << "Фамилия студента: ";
		cin >> stud[i].name;

		cout << "Номер группы студента: ";
		cin >> stud[i].num;

		cout << "Средний балл студента: ";
		cin >> stud[i].grade;

		out.write((char*)(&stud[i]), sizeof(student));  // запись в бинарный файл
	}

	out.close();
	_getch();
	return 0;
}