// ������������ ����� �2

#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	char lpszAppName1[] = "Z:\\���\\Lab2\\Debug\\Creator.exe";
	char lpszAppName2[] = "Z:\\���\\Lab2\\Debug\\Reporter.exe";

	STARTUPINFO si;
	PROCESS_INFORMATION piApp;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	char Bin[25]; // �������� � reporter
	
	cout << "�������� ����: ";
	cin >> Bin;
	
	// ������� ����� ���������� ������� Creator
	if (!CreateProcess(lpszAppName1, Bin, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
	{
		_cputs("����� ������� �� ������.\n");
		_getch();
		return 0;
	}
	_cputs("����� ������� ������.\n");


	WaitForSingleObject(piApp.hProcess, INFINITE); // ���� ���������� ���������� �������
	
	CloseHandle(piApp.hThread); // ��������� ����������� ����� �������� � ������� ��������
	CloseHandle(piApp.hProcess);


	char Txt[10];
	char Group[2];

	cout << "�������� ����: ";
	cin >> Txt;
	cout << "����� ������: ";
	cin >> Group;

	strcat_s(Bin, " ");
	strcat_s(Bin, Txt);
	strcat_s(Bin, " ");
	strcat_s(Bin, Group);

	cout << Bin;   // �������� � ��������

	// ������� ����� ���������� ������� Reporter
	if (!CreateProcess(lpszAppName2, Bin, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
	{
		_cputs("\n����� ������� �� ������\n");
		_getch();
		return 0;
	}
	_cputs("\n����� ������� ������.\n");

	WaitForSingleObject(piApp.hProcess, INFINITE); // ���� ���������� ���������� �������
	
	CloseHandle(piApp.hThread); // ��������� ����������� ����� �������� � ������� ��������
	CloseHandle(piApp.hProcess);

	return 0;
}