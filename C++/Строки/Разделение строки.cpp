#include <stdio.h>
#include <string.h>

int main()
{
	char  str[ ] = "123 ab3 ab3 112 123 3cd 333 333";
	char *p;
	char* s[10];
	int n = 0, b;
	p = strtok(str, " ");
	while (p)
	{
		b = 0;
		for (int i = 0; i < n; i++)
			if (!strcmp(s[i], p))
			{
				b = 1;
				break;
			}
			if (b != 1) 
			{
				s[n] = p;
				printf("%s\n", s[n]);
				++n;
			}
			p = strtok(NULL, " ");
	}
	printf("\n%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%s\n", s[i]);

	return 0;
}
