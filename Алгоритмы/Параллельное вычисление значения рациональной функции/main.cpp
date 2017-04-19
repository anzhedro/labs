//������������ ���������� �������� ������������ �������.
#include <iostream>
#include <windows.h>

DWORD WINAPI Polynom(int* iNum);

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	int n; // ������� ���������
	int m; // ������� �����������
	int num; // �������� ����������
	HANDLE	hThread[2];
	DWORD	IDThread[2];

	cout << "������� ������� ���������: ";
	cin >> n;
	int	*chis = new int[n + 4];
	cout << "������� ������������ ���������: ";
	for (int i = 2; i < n + 3; i++)
		cin >> chis[i];


	cout << "������� ������� �����������: ";
	cin >> m;
	int	*znam = new int[m + 4];
	cout << "������� ������������ �����������: ";
	for (int i = 2; i < m + 3; i++)
		cin >> znam[i];

	cout << "������� ��������: ";
	cin >> num;

	chis[0] = n;      // c������ ���������
	chis[1] = num;    // �������� ������� 
	chis[n + 3] = 0;  // �������� ��������

	znam[0] = m;     // c������ ���������
	znam[1] = num;   // �������� ������� 
	znam[m + 3] = 0; // �������� ��������


	hThread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Polynom, (void*)chis, 0, &IDThread[0]);
	Sleep(10);
	hThread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Polynom, (void*)znam, 0, &IDThread[1]);

	WaitForMultipleObjects(2, hThread, 1, INFINITE);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);

	cout << "f(" << num << ") = " << (double)chis[n + 3]/znam[m + 3] << endl;

	return 0;
}