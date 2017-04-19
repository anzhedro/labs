#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* vstavka(char *s, char *s1, char *s2)
{
	int pr; // длина результата
	char *t = s, *p, *r, *res;
	pr = (strlen(s) / strlen(s1)) * strlen(s2) + strlen(s) + 1;
	res = new char[pr];
	r = res;


	while (p = strstr(t, s1))
	{
		int x = p - t;
		strncpy(r, t, x);
		r +=x;
		strncpy(r, s1, strlen(s1));
		r +=strlen(s1);
		strncpy(r, s2, strlen(s2));
		t = p + strlen(s1);
		r = r + strlen(s2);
	}
	strcpy (r, t);
	return res;
}

int main ()
{
	char s[] = "hii hih hi hi hi hzjkkkd0012 hi";
	char *s1 = "hi";
	char *s2 = "0Hell0";
	char *res;
	res = vstavka(s, s1, s2);
	printf ( "%s \n", s);
	printf ( "%s \n", res);
	return 0;
}