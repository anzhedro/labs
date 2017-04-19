//Параллельное вычисление значения рациональной функции.
#include <iostream>
#include <windows.h>

DWORD WINAPI Polynom(int* iNum);

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	int n; // степень числителя
	int m; // степень знаменателя
	int num; // значение переменной
	HANDLE	hThread[2];
	DWORD	IDThread[2];

	cout << "Введите степень числителя: ";
	cin >> n;
	int	*chis = new int[n + 4];
	cout << "Введите коэффициенты числителя: ";
	for (int i = 2; i < n + 3; i++)
		cin >> chis[i];


	cout << "Введите степень знаменателя: ";
	cin >> m;
	int	*znam = new int[m + 4];
	cout << "Введите коэффициенты знаменателя: ";
	for (int i = 2; i < m + 3; i++)
		cin >> znam[i];

	cout << "Введите значение: ";
	cin >> num;

	chis[0] = n;      // cтепень числителя
	chis[1] = num;    // значение функции 
	chis[n + 3] = 0;  // значение полинома

	znam[0] = m;     // cтепень числителя
	znam[1] = num;   // значение функции 
	znam[m + 3] = 0; // значение полинома


	hThread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Polynom, (void*)chis, 0, &IDThread[0]);
	Sleep(10);
	hThread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Polynom, (void*)znam, 0, &IDThread[1]);

	WaitForMultipleObjects(2, hThread, 1, INFINITE);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);

	cout << "f(" << num << ") = " << (double)chis[n + 3]/znam[m + 3] << endl;

	return 0;
}