#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a[10][10], n, m, sum[10];
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter matrix:" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];	
	_asm
	{
		lea eax, a
		lea ebx, sum
		mov ecx, m
		mov edi, 0
for1:
		mov edx, 0
		mov esi, 0
		push ecx
		mov ecx, n 
for2:
		add edx, [eax][esi*4]
		add esi, 10
		loop for2
		mov [ebx][edi*4], edx
		pop ecx
		inc edi
		add eax, 4
		loop for1
	}
	for (int i = 0; i < m; i++)
		cout << sum[i] << " ";
	cin >> n;
	cout << endl;
	return 0;
}