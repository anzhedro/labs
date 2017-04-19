#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, k;
	int p[20];
	cout << "Enter a number:" << endl;
	cin >> n;	
	_asm
	{
		mov edi, 2
		mov esi, 0
		lea ebx, p
		mov ecx, n
while1:
		cmp ecx, 1
		je end_while
while2:
		mov eax, ecx
		cdq
		idiv edi
		cmp edx, 0
		jz else1
		add edi, 1
		jmp while2
else1:
		mov ecx, eax
		mov [ebx][esi], edi
		add esi, 4
		jmp while1
end_while:
		mov eax, esi
			cdq
		mov k, 4
		idiv k
		mov k, eax
	}
	for (int i = 0; i < k; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	return 0;
}