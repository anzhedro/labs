#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* zamena(char *s, int c1, int c2)
{
	char *s1; char *s2;
	s1 = new char[10];
	s2 = new char[10];
	sprintf(s1, "%d", c1);
	sprintf(s2, "%d", c2);
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
	char s[] = "1234522 222 2 2 2 3 14 3 22";
	//char *s1 = "hi";
	//char *s2 = "Helly";
	int s1 = 222 , s2 = 34;
	char *res;
	res = zamena(s, s1, s2);
	printf ( "%s \n", s);
	printf ( "%s \n", res);
	return 0;
}