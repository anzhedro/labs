#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int comp(const void* e1, const void* e2)
{
	char **a=(char**)e1,**b=(char**)e2;
	return strcmp(*a, *b);
}
int main()
{
	int  n;	
	char **a;		
	int  i;		
	char s[101];		

	printf("Input an array size: ");
	cin >> n;
	char pp[2];
	cin.getline(pp, 2);

	a = new char*[n];
	printf("Input elements: ");
	for (i = 0; i < n; ++i)
	{
		cin.getline(s, 100, '\n');
		a[i] = new char[strlen(s)+1];
		strcpy(a[i], s);
	}
	
	qsort(a, n, sizeof(char*),comp);

	printf("The sorted array: ");
	for (i = 0; i < n; ++i)
		printf("%s\n", a[i]);
}