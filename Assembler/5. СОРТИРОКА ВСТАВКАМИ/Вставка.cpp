#include <iostream>
#include <ctime>
void main()
{
	int *a;
	int i, n, tmp, j, pos;
	std::cin >> n;
	n++;
	a = new int[n];

	srand(time(0));
	for(int i = 1; i < n; i++)
	{
		a[i] = rand() % 1000;
		//cin >> a[i];
	}
	_asm
	{
		mov ebx, a  // a
			mov esi, 2  // i
for1:
		cmp esi, n 
			je end_for1
			mov ecx, [ebx][esi * 4]  // tmp
		mov edi, esi // j = i
			dec edi  // j = i - 1
for2:
		cmp edi, 0
			je end_for2
			cmp [ebx][edi * 4], ecx       // a[j] ? tmp 
			jng end_for2
			mov eax, [ebx][edi * 4]       // a[j]
		    mov [ebx][edi * 4 + 4], eax   // a[j + 1] = a[j]; 
	     	dec edi     // j--
		    jmp for2
end_for2:
		mov [ebx][edi * 4 + 4], ecx
		inc esi
		jmp for1
end_for1:
		mov a, ebx
	}
	for(i = 1; i < n; ++i)
		std::cout << a[i] << " ";
	std::cout << "\n";
}