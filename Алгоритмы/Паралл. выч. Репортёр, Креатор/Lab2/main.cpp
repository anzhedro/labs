// Лабараторная раота №2

#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	char lpszAppName1[] = "Z:\\ОСИ\\Lab2\\Debug\\Creator.exe";
	char lpszAppName2[] = "Z:\\ОСИ\\Lab2\\Debug\\Reporter.exe";

	STARTUPINFO si;
	PROCESS_INFORMATION piApp;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	char Bin[25]; // параметр в reporter
	
	cout << "Бинарный файл: ";
	cin >> Bin;
	
	// создаем новый консольный процесс Creator
	if (!CreateProcess(lpszAppName1, Bin, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
	{
		_cputs("Новый процесс не создан.\n");
		_getch();
		return 0;
	}
	_cputs("Новый процесс создан.\n");


	WaitForSingleObject(piApp.hProcess, INFINITE); // ждем завершения созданного прцесса
	
	CloseHandle(piApp.hThread); // закрываем дескрипторы этого процесса в текущем процессе
	CloseHandle(piApp.hProcess);


	char Txt[10];
	char Group[2];

	cout << "Выходной файл: ";
	cin >> Txt;
	cout << "Номер группы: ";
	cin >> Group;

	strcat_s(Bin, " ");
	strcat_s(Bin, Txt);
	strcat_s(Bin, " ");
	strcat_s(Bin, Group);

	cout << Bin;   // параметр в репортер

	// создаем новый консольный процесс Reporter
	if (!CreateProcess(lpszAppName2, Bin, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
	{
		_cputs("\nНовый процесс не создан\n");
		_getch();
		return 0;
	}
	_cputs("\nНовый процесс создан.\n");

	WaitForSingleObject(piApp.hProcess, INFINITE); // ждем завершения созданного прцесса
	
	CloseHandle(piApp.hThread); // закрываем дескрипторы этого процесса в текущем процессе
	CloseHandle(piApp.hProcess);

	return 0;
}