#include <iostream>
#include <fstream>

using namespace std;

bool *used;
int N;
int **G;
int *Size;
int *Number;
int *otvet;
int k = 1, summ = 0;

void Gly(int pos)
{
	used[pos] = true;
	for (int i = 1; i < N + 1; ++i)
	{
		if ((!used[i]) && (G[pos][i] != 0))
		{
			Gly(i);
			Size[pos] += Size[i];
		}
	}
	++Size[pos];
}

void PriorityGly(int pos)
{
	used[pos] = true;
	int flag = 0;
	while ( flag == 0 )
	{
		int max = 0;
		int z = 0;
		flag = 1;
		for (int i = 1; i < N + 1; ++i)
		{
			if ((!used[i]) && (G[pos][i] != 0))
			{
				if (Size[i] > max)
				{
					max = Size[i];
					z = i;
					flag = 0;
				}
			}
		}

		if (z != 0)
			PriorityGly(z);
	}
	Number[pos] = k;
	otvet[k] = pos;
	k++;

	for (int i = 1; i < N + 1; i++)
	{
		if (G[pos][i] != 0)
		{
			summ += abs (Number[pos] - Number[i]);
		}
	}
}

int main()
{
	ifstream in("input.txt");
	int start;
	in >> N;
	in >> start;

	Size   = new int[N + 1];
	Number = new int[N + 1];
	otvet  = new int[N + 1];
	G = new int*[N + 1];

	for (int i = 0; i < N + 1; ++i) 
	{
		Size[i] = 0;
		G[i] = new int[N + 1];
		for(int j = 1; j < N + 1; ++j)
		{
			G[i][j] = 0;
		}
	}

	used = new bool[N + 1]; 

	for (int i = 1; i < N + 1; ++i)	{ used[i] = false; }

	int node, q, z;
	char *p = new char[5 * N];
	for (int i = 1; i < N + 1; ++i)
	{
		in >> p;

		char * pch = strtok (p,":");

		z = 0;
		while (pch != NULL)
		{
			if (z == 0)
				node = atoi(pch);
			if (z == 1)
				q = atoi(pch);
			if (z > 1)
			{
				q = atoi(pch);
				G[node][q] = 1;
			}
			z++;
			pch = strtok (NULL, ":");
		}
	}


	Gly(start);

	for (int i = 1; i < N + 1; ++i)	{ used[i] = false; }

	PriorityGly(start);

	int w = 0;
	for (int i = 1; i < N + 1; ++i)
	{
		if (Size[i] == 0)
		{
			w++;
		}
	}

	ofstream out("output.txt");
	out << summ << endl;
	for (int i = 1; i < N - w; ++i)
	{
		out << otvet[i] << " ";
	}
	if (w == 0) out << otvet[N];
	else 
		out << otvet[N - w];
}