#include <iostream>
#include <ctime>
using namespace std;
void Sort(int *A, int L, int R) 
{
	/*int mid, lo, hi;
	mid = A[(L + R) / 2];
	lo = L;
	hi = R;
	while (lo <= hi)
	{
	while (A[lo] < mid) 
	lo++;
	while (A[hi] > mid) 
	hi--;
	if (lo <= hi)
	{
	int x = A[lo];
	A[lo] = A[hi];
	A[hi] = x;
	lo++;
	hi--;
	}
	if (L < hi)
	Sort(A, L, hi);
	if (lo < R)
	Sort(A, lo, R);

	}*/
	_asm
	{
		mov ebx, A  // A
			mov ecx, L  // L
			add ecx, R  // L + R
			shr ecx, 1  // [mid]
			mov edx, [ebx][ecx * 4] // mid = A[mid]
		mov esi, L  // lo
			mov edi, R  // hi
while1:
		cmp esi, edi
			jg end1
while2:
		cmp [ebx][esi * 4], edx
			jnl while3
			inc esi
			jmp while2
while3:
		cmp [ebx][edi * 4], edx
			jng end3
			dec edi
			jmp while3
end3:
		cmp esi, edi
			jg end1
			mov eax, [ebx][esi * 4]
		mov ecx, [ebx][edi * 4]
		mov [ebx][edi * 4], eax
			mov [ebx][esi * 4], ecx
			inc esi
			dec edi
			jmp while1
end1: /*nop*/
		cmp L, edi
			jnl next_cmp
			push edi
			push dword ptr L
			push ebx
			call Sort
			pop ebx
			pop L
			pop edi
next_cmp:
		cmp esi, R
			jnl nexxt
			push dword ptr R
			push esi
			push ebx
			call Sort
			pop ebx
			pop esi
			pop R
nexxt:
	}
}
int main()
{
	int *a;
	int n, c;
	srand(time(0));
	cout << "Input size:" << endl;
	cin >> n;
	a = new int[n];
	cout << "Input elements:" << endl;
	for(int i = 0; i < n; i++)
	{
		a[i] = rand() % 100000;
		//cin >> a[i];
	}
	Sort(a, 0, n - 1);
	cout << "Result:" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}