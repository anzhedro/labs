#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
int main()
{
	int n;
	FILE* f;
	f = fopen("input.txt", "r");
	fseek(f, 0, 2);
	n = ftell(f);
	fseek(f, 0, 0);
	printf("-%d-\n", n);
	char *s = new char[n];
	fgets(s, '\n', f);

	Stack st(n);

	for (int i = 0; i < n; i++)

		if (s[i] == '(') st.push(0);
		else
			if (!st.empty()) st.pop();
			else
			{
				printf("ERROR\n");
				return 0;
			}
			if (!st.empty()) 
			{
				printf("ERROR\n");
				return 0;
			}
			printf("+++\n");
			return 0;

}