#include <conio.h>
#include <fstream>
#include <iostream>
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
	ofstream out;
	out.open(argv[0], ios::out | ios::binary );

	int n;

	cout << "���������� �������: ";
	cin >> n;

	student* stud = new student[n];

	for(int i = 0; i < n; i++)
	{
		cout << "������� ��������: ";
		cin >> stud[i].name;

		cout << "����� ������ ��������: ";
		cin >> stud[i].num;

		cout << "������� ���� ��������: ";
		cin >> stud[i].grade;

		out.write((char*)(&stud[i]), sizeof(student));  // ������ � �������� ����
	}

	out.close();
	_getch();
	return 0;
}