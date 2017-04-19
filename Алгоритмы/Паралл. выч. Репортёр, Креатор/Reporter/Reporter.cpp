#include <conio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)

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

	ofstream out;                                         // файл .bin
	out.open(argv[1]);                                     

	out << "Отчет по файлу : " << argv[0] << endl;
	out << "Номер группы №" << argv[2] << endl;

	ifstream in;                                          // файл .txt
	in.open(argv[0], ios::in | ios :: binary);

	student stud;
	int n = 0;                                    // количество студентов в группе 
	double srball = 0, naim = 11, naib = -1;      // средний балл, наименьший, наибольший
	char nameNaim[100], nameNaib[100];            // имя с наименьшим, имя с наибольшим

	while (!in.eof())
	{

		in.read((char*)(&stud), sizeof(student));
	
		if (stud.num == atoi(argv[2]))
		{

			n++;
			srball += stud.grade;           // средний балл

			if (stud.grade > naib)          // поиск наибольшего
			{
				naib = stud.grade;
				strcpy(nameNaib, stud.name);
			}

			if (stud.grade < naim)         // поиск наименьшего 
			{
				naim = stud.grade;
				strcpy(nameNaim, stud.name);
			}

		}

	}

	n--;
	srball -= stud.grade;

	out << "Средний балл по группе: " << srball/n << endl;                      // вывод
	out << "Наименьший средний балл: " << nameNaim << " " << naim << endl;
	out << "Наибольший средний балл: " << nameNaib << " " << naib << endl;

	out.close();

	_getch();
	return 0;
}