#include <conio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)

using namespace std;

struct student
{
	char name[10]; // ��� ��������
	int num; // ����� ������
	double grade; // ������� ����
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");

	ofstream out;                                         // ���� .bin
	out.open(argv[1]);                                     

	out << "����� �� ����� : " << argv[0] << endl;
	out << "����� ������ �" << argv[2] << endl;

	ifstream in;                                          // ���� .txt
	in.open(argv[0], ios::in | ios :: binary);

	student stud;
	int n = 0;                                    // ���������� ��������� � ������ 
	double srball = 0, naim = 11, naib = -1;      // ������� ����, ����������, ����������
	char nameNaim[100], nameNaib[100];            // ��� � ����������, ��� � ����������

	while (!in.eof())
	{

		in.read((char*)(&stud), sizeof(student));
	
		if (stud.num == atoi(argv[2]))
		{

			n++;
			srball += stud.grade;           // ������� ����

			if (stud.grade > naib)          // ����� �����������
			{
				naib = stud.grade;
				strcpy(nameNaib, stud.name);
			}

			if (stud.grade < naim)         // ����� ����������� 
			{
				naim = stud.grade;
				strcpy(nameNaim, stud.name);
			}

		}

	}

	n--;
	srball -= stud.grade;

	out << "������� ���� �� ������: " << srball/n << endl;                      // �����
	out << "���������� ������� ����: " << nameNaim << " " << naim << endl;
	out << "���������� ������� ����: " << nameNaib << " " << naib << endl;

	out.close();

	_getch();
	return 0;
}