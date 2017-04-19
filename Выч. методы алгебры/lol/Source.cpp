#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>

using namespace std;
void main()
{
	clock_t start, finish;
	start = clock();

	ifstream in;
	in.open("input.txt");

	int n;
	in >> n;

	float **matrix;
	float **E;

	matrix = new float*[n]; // основная
	E = new float*[n];      // обратная

	for (int i = 0; i < n; ++i)  // выделение памяти
	{
		matrix[i] = new float[n];
		E[i] = new float[n];
	}

	for(int i = 0; i < n; ++i) // заполнение обратной
	{
		for(int j = 0; j < n; ++j)
		{
			in >> matrix[i][j]; //ввод основной
			E[i][j] = 0.0;
		}
		E[i][i] = 1.0;
	}
	in.close();

	for(int i = n - 1; i > 0; --i)
	{
		if(abs(matrix[i][n - i - 1]) < abs(matrix[i - 1][n - i - 1]))
		{
			float *t = matrix[i];
			matrix[i] = matrix[i-1];
			matrix[i - 1] = t; 
			t = E[i];
			E[i] = E[i - 1];
			E[i - 1] = t;
		}

		if (matrix[i - 1][n - i - 1] == 0.0) continue;

		float z = matrix[i - 1][n - i - 1] / matrix[i][n - i - 1];

		for (int j = n - i - 1; j < n; ++j)
		{
			matrix[i - 1][j] -= z * matrix[i][j];
		}

		for(int j = 0; j < n; ++j)
			E[i - 1][j] -= z * E[i][j];
	} 

	float det = 1;
	for(int i = 0; i < n; i++)
		det *= matrix[i][n - i - 1];
	if (det == 0) 
		cout << "det(A) = 0 => A^(-1) is absent." << endl;
	else 
	{
		for(int i = 1; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					E[j][k] -= E[i - 1][k] * matrix[j][n - i] / matrix[i - 1][n -i];
				}
			}
		}

		for(int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				E[i][j] /= matrix[i][n - i - 1];
			}
		}

		for(int i = 0; i < n / 2; ++i)
		{
			float *t =  E[i];
			E[i] = E[n - i - 1];
			E[n - i - 1] = t;
		}

		ofstream out;
		out.open("output.txt");
		for (int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				out << setw(5) << E[i][j] << " ";
			out << endl;
		}
	}


	finish = clock();
	cout << "n = " << n << " time = " << float(finish - start) / CLOCKS_PER_SEC << endl;

}
