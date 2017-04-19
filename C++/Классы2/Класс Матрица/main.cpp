#include "SafeMatrix.h"
int main()
{
	matrix A(2, 2);
	A[0][0] = 1;
	A[0][1] = 2;
	A[1][0] = 3;
	A[1][1] = 4;
	cout << A[0][0];
	cout << A[0][1];
	cout << A[1][0];
	cout << A[1][1];
}