#include <windows.h>
#include <iostream>
#include <math.h>

using namespace std;


DWORD WINAPI Polynom(int* iNum)
{
	int q = iNum[0] + 3;
	for (int j = 2; j < q; j++)
		iNum[q] += iNum[j] * (int)pow( (double)iNum[1], (double)(q - 1 - j));
	cout << "p(" << iNum[1] << ") = " << iNum[q] << endl;

	return 0;
}