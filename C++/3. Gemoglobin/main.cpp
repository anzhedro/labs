#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
class Stack
{
private:
	long long* st;
	int p;
	int n;
public:
	long long pop()
	{
		return st[p--];
	}

	long long gop(int j)
	{
		return st[p  - j];
	}

	void push(int x)
	{
		st[++p] = x;
	}

	Stack(int _n)
	{
		st = new long long[_n];
		p = -1;
		n = _n;
	}
};
int main()
{
	int n; int v = 0;
	long long z;
	char* l = new char[12];
	FILE* f;
	fstream out("hemoglobin.out");
	f = fopen("hemoglobin.in", "rt");
	fgets(l, 11, f);
	n = atoi ( l );
	printf("%d\n", n);
	Stack st(n);
	
	for (int i = 0; i < n; i++)
	{
		fgets(l, 12, f);
		if (l[0] == '+')
		{
			l[0] = '0';
			z = atoi( l );
			st.push(z);
		}
		if (l[0] == '?')
		{
			l[0] = '0';
			z = atoi( l );
			long long summ = 0;
			for (int j = 0; j < z; j++)
			{
				long long tr = st.gop(j);
				summ += tr;
			}
				out << summ  << endl;    //v
			}
		if (l[0] == '-')
		{
			long long q = st.pop();
				out << q << endl;       //v
		}
	}
}