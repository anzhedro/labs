#include "SafeMatrix.h"
//matrix::matrix& operator += (const matrix& m)
//{
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			m[i][j]
//}

//matrix::matrix& operator *=(const matrix& e) // результат - матрица  nrows x A.ncols, старая удаляется
//{
//	int *z = new int[n * e.m];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < e.m; j++)
//		{
//			int summ = 0; 
//			for (int k = 0; k < m; k++)
//				summ += p[i * m + k] * e[k][j];
//		z[i * e.m + j] = summ;
//		}
//	}
//	delete []p;
//	p = z;
//	return *this;
//}

matrix::matrix& operator *=(const matrix& e) // результат - матрица  nrows x A.ncols, старая удаляется
{
	int *Z = new int[m * e.n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < e.n; j++)
		{
			int summ = 0; 
			for (int k = 0; k < n; k++)
				Summ += p[i * n + k] * e[k][j];
			Z[i * e.n + j] = summ;
		}
	}
	delete []p;
	p = Z;
	return *this;
}

//matrix& operator *= (const double& d)
//{
//
//}