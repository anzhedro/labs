#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* zamena(char *s, char *s1)
{
	int pr; char *t = s, *p, *r, *res;
	res = new char[strlen(s) + 1];
	r = res;
	
	while (p = strstr(t, s1))
	{
		int x = p - t;
		strncpy(r, t, x);
		t = p + strlen(s1);
		r = r + x;
	}
	strcpy (r, t);
	
	return res;
}

int main ()
{
	char s[] = "hi 1hi hih jjjkhihikk jhkhj hi";
	char *s1 = "hi";
	char *res;
	res = zamena(s, s1);
	printf ( "%s \n", s);
	printf ( "%s \n", res);
	delete []res;
	return 0;
}