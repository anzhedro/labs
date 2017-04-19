#include <iostream>
using namespace std;
int main()
{
	int **a, n, m, sum;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter matrix:" << endl;
	a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	_asm
	{
		mov ebx, a
		mov ecx, n
		mov esi, 0
		mov eax, 0		
for1:
		mov edx, [ebx]		
		add eax, [edx][esi*4]
		inc esi
		add ebx, 4
		loop for1
		mov sum, eax
	}
	cout << "Summ= " << sum << endl;
	return 0;
}