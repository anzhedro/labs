#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> row;
typedef vector<row> matrix;
typedef vector<matrix> matrix3d;

int main()
{
	ifstream in;                                 
	in.open("jokers.in");

	int K, C, J, T, M, N;
	in >> K >> C >> J >> T;

	M = C + J + 1;
	vector<int> A(M);
	for (int i = 0; i < M; ++i)
		in >> A[i];

	in >> N;
	int temp;
	vector<int> B(K + 1);
	for (int i = 0; i < N; ++i)
	{
		in >> temp;
		B[temp]++;
	}
	in.close();

	matrix3d f(B[0] + 1, matrix(T + 2, row(K + 1, -1000000)));

	int z = 0;
	f[B[0]][0][0] = 0;

	for (int k = f.size() - 1; k >= 0; --k) {
		for (int i = 0; i < f[0].size() - 1; ++i) {
			z = ((k < f.size() - 1) && (i == 0)) ? 1 : 0;
			for (int j = i + z; j < f[0][0].size() - 1; ++j)  {
				for (int q = 0; q <= k; q++){
					f[k - q][i][j + 1] = max(f[k - q][i][j + 1],
								f[k][i][j] - A[B[j + 1] + q]);
					f[k - q][i + 1][j + 1] = max(f[k - q][i + 1][j + 1],
								f[k][i][j] + A[B[j + 1] + q]);
				}
				cout << f[0][i][j] << " " ;
			}
			cout << f[0][i][7] <<endl;
		}
	}

	ofstream out("jokers.out");
	out << f[0][T][K];
	out.close();

	return 0;
}