#include <iostream>
void main()
{
	int *a;
	int i, n, tmp, j, pos;
	std::cin >> n;
	a = new int[n];
	for(i = 0; i < n; ++i)
		std::cin >> a[i];
	//for(i = 0; i < n; ++i) // i - номер текущего шага
	//{ 
	//	pos = i; 
	//	tmp = a[i];
	//	for(j = i + 1; j < n; ++j) // цикл выбора наименьшего элемента
	//	{
	//		if (a[j] < tmp) 
	//		{
	//			pos = j; 
	//			tmp = a[j]; 
	//		}
	//	}
	//	a[pos] = a[i]; 
	//	a[i] = tmp; // меняем местами наименьший с a[i]
	//}
	_asm
	{
		mov ebx, a  // a
			mov esi, 0  // i
while1:
		cmp esi, n 
			je end_while1
			mov edx, esi             // pos
			mov ecx, [ebx][esi * 4]  // tmp
		mov edi, esi // j
			inc edi
while2:
		cmp edi, n
			je end_while2
			//if (a[j] < tmp) 
			cmp [ebx][edi * 4], ecx   // tmp ? a[j] 
			jge EX
			mov edx, edi              // pos = j
			mov ecx, [ebx][edi * 4]   // tmp = a[j]
EX:
		inc edi
			jmp while2
end_while2:
		//	a[pos] = a[i]; 
		//	a[i] = tmp; // меняем местами наименьший с a[i]
		mov eax, [ebx][esi * 4]
		mov [ebx][edx * 4], eax
			mov [ebx][esi * 4], ecx
			inc esi
			jmp while1
end_while1:
		mov a, ebx
	}
	for(i = 0; i < n; ++i)
		std::cout << a[i] << " ";
	std::cout << "\n";
}