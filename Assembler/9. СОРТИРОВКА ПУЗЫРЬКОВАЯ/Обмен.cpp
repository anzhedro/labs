#include <iostream>
void main()
{
	int *a;
	int i, n, tmp, j;
	std::cin >> n;
	a = new int[n];
	for(i = 0; i < n; ++i)
		std::cin >> a[i];
	tmp = n - 1;
	_asm
	{
		mov ebx, a  // a
		mov esi, 0  // i
while1:
		cmp esi, n 
		je end_while1
		
		mov edi, 0  // j
while2:
		cmp edi, tmp
		je end_while2

		mov eax, [ebx][edi * 4 + 4] // a[j + 1]
		mov ecx, [ebx][edi * 4]         // a[j]
		cmp eax, ecx                // a[j] ? a[j + 1] 
		jnl EX                      // (a[j] < a[j+ 1])
			mov [ebx][edi * 4 + 4], ecx
			mov [ebx][edi * 4], eax
EX:
		inc edi
		jmp while2
end_while2:
		inc esi
		jmp while1
end_while1:
		mov a, ebx
	}
	for(i = 0; i < n; ++i)
		std::cout << a[i] << " ";
	std::cout << "\n";
}