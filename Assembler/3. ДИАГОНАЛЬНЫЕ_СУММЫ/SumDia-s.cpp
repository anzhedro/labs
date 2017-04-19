#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
int main()
{
	HANDLE Con;
	Con = GetStdHandle(STD_OUTPUT_HANDLE);
	int **a, n, *s, i, c;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter matrix (n * n):" << endl;
	SetConsoleTextAttribute(Con, 7);
	a = new int*[n];
	s = new int[2 * n + 1];
	for ( i = 0; i < n; i++)
	{	
		s[i] = 0;
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
			cin >> a[i][j];		
	}
	_asm
	{
		mov eax, a
			mov esi, 0
			mov ecx, n
			mov edi, s		
for1:			
		push ecx
			mov ecx, n
			sub ecx, esi
			push esi
			mov edx, 0
for2:
		mov ebx, [eax]
		add edx, [ebx][esi*4]
		add eax, 4
			inc esi
			loop for2
			pop esi
			pop ecx
			mov eax, a
			mov [edi][esi*4], edx	
			inc esi
			loop for1
			mov c, esi
			//сумма чисел на прямых под главной диагональю
			mov esi, 0
			mov ecx, n
			dec ecx			
for3:
		mov eax, a
			push ecx
			mov ecx, esi
			inc ecx
for4:
		add eax, 4
			loop for4
			mov ecx, n
			sub ecx, esi
			dec ecx
			push esi
			mov esi, 0
			mov edx, 0
for5:
		mov ebx, [eax]
		add edx, [ebx][esi*4]
		add eax, 4
			inc esi
			loop for5
			pop esi
			mov ecx, c
			mov [edi][ecx*4], edx
			inc ecx
			mov c, ecx
			pop ecx
			inc esi		
			loop for3
	}
	for (i = 0; i < n; i++)
	{
		SetConsoleTextAttribute(Con, 10);
		cout << s[i] << " ";
	}
	cout << "0";
	c = i;
	cout << endl;
	for (i = 0; i < n; i++)
	{		
		for (int j = 0; j <= n; j++)
		{
			if (j == 0)
			{
				if (i == (n - 1))
				{
					SetConsoleTextAttribute(Con, 10);
					cout << "0 ";
					SetConsoleTextAttribute(Con, 12);
				}
				else
				{
					SetConsoleTextAttribute(Con, 10);
					cout << s[c + i] << " ";
					SetConsoleTextAttribute(Con, 12);
				}
			}
			else
			{
				cout << a[i][j - 1] << " ";
			}			
		}
		cout << endl;
	}
	SetConsoleTextAttribute(Con, 7);
	return 0;
}