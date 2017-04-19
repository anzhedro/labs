#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char* zamena(char *s, char *s1, char *s2)
{
	int pr; char *t = s, *p, *r, *res;
	pr = strlen(s2) - strlen(s1);

	if (pr > 0) 
	{
		pr = pr * (strlen(s) / strlen(s1)) + strlen(s) + 1;
		res = new char[pr];
	}
	else 
		res = new char[strlen(s) + 1];
	r = res;


	while (p = strstr(t, s1))
	{
		int x = p - t;
		strncpy(r, t, x);
		strncpy(r+x, s2, strlen(s2));
		t = p + strlen(s1);
		r = r + x + strlen(s2);
	}
	strcpy (r, t);
	return res;
}

int main ()
{
	char *s = new char[200];
	char *s1 = new char[5];
	char *s2 = new char[5];
	int n = 0;
	/*char pp[2];
	cin.getline(pp, 2);*/
	cin.getline(s1, 5, '\n');
	cin.getline(s2, 5, '\n');
	FILE* f;
	f = fopen("input.txt", "r");
	while (!feof(f))
	{
		/*fscanf(f, "%s", s);*/
		fgets(s,20,f);
		//s = gets(s);
		printf("%s ", zamena(s, s1, s2));

	}
	system ("pause");
	return 0;
}