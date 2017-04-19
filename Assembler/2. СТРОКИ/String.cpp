#include <iostream>
using namespace std;
void main()
{
	char *source,*wword;
	setlocale(LC_ALL,".1251");
	source = new char[100];
	wword = new char[10];
	cout << "Строка:    ";
	cin.getline(source, 100, '\n');
	cout << "Удалить:   ";
	cin.getline(wword, 10, '\n');
	int ls, lw, ld;
	int found = -1;
	_asm
	{
		mov ebx, source
		mov esi, 0

		//len s
while1: cmp byte ptr [ebx][esi], 0
		je end1
		inc esi
		jmp while1

end1:   mov ls, esi
		mov ebx, wword
		mov esi, 0

		//len wword
while2: 
		cmp byte ptr [ebx][esi], 0
		je end2
		inc esi
		jmp while2

end2:   
		mov lw, esi
		mov ecx, ls

		// Head
METKA1:
		push ecx
		mov found, -1
		mov ebx, 0
		mov eax, ls
		sub eax, lw 
		mov edi, 0
		mov ld, eax
		mov edx, wword
		mov eax, source

		// Body
while3:	
		cmp ebx, ld
		jg PRE_END
		mov found, ebx
		mov edi, ebx
		mov esi, 0
		mov ecx, lw
		add edi, esi

for1:	
		push ecx
		mov cl, byte ptr[edx][esi]
		cmp cl, [eax][edi]
		jne else1
		inc esi
		inc edi
		jmp end3

else1:
		mov found, -1
		pop ecx
		jmp end4

end3:
		pop ecx
		loop for1

end4:	
		cmp found, -1
		jne PRE_END
		inc ebx
		jmp while3

PRE_END:
		cmp found, -1
		jne METKA2
		pop ecx
		jmp END

METKA2:	
		mov eax, source
		mov edi, found
		mov esi, edi
		add esi, lw
		mov ecx, ls
		sub ecx, esi
		inc ecx

for2:	
		mov dl, [eax][esi]
		mov [eax][edi], dl
		inc edi
		inc esi
		loop for2
		pop ecx
		loop METKA1

END: 
		nop
	}
	cout << "Результат: ";
	cout << source << endl;
}