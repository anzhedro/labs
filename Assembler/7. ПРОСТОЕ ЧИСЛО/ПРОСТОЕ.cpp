//Определить, является ли заданное натуральное число простым.
#include <iostream>
#include <math.h>
int main()
{
	int a, n, q = 0;
	std::cin >> a;
	n = sqrt((double)a) + 1;
	_asm
	{
		mov eax, a
		mov ebx, 2
		mov ecx, n
		mov edi, 0
while1:
		cmp ebx, ecx
			je endwhile1
			cdq
			div ebx
			cmp edx, 0
				je No1
			inc ebx
			mov eax, a
			jmp while1
No1:
		mov edi, 1
endwhile1:
		mov q, edi
	}
	if (q)
		std::cout << "NO" << std::endl;
	else
		std::cout << "YES" << std::endl;
	return 0;
}