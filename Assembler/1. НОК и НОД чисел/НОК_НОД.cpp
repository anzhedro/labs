//1.	LCM and Gcd of 2 numbers
#include <iostream>
int main()
{
	int a, b, c, d;
	std::cin >> a >> b;
	long long q = 0;
	c = a;
	d = b;
	_asm
	{
		mov eax, a
			mov ebx, b
while1: cmp eax, ebx                //while (a != b) 
		je endwhile                 //if end eq
		jl else1                    //if a > b
		sub eax, ebx                //a = a - b;
		jmp while1
else1:                              //if a < b
		sub ebx, eax
			jmp while1
endwhile:

		mov a, eax                   // a = Gcd                      q = c * d / a;
			mov eax, c               // in eax value A
			cdq
			div a                    // div by Gcd
			mul d                    // multiply by B
			mov dword ptr q, eax     // q = LCM
			mov dword ptr q + 4, edx
	}
	std::cout << "NOD = " << a << " NOK = " << q << std::endl; 
	return 0;
}