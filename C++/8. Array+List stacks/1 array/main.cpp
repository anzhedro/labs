#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
int main()
{
	int n;
	scanf("%d", &n);
	stack st(n);
	for (int i = 0, x = 0; i < n; i++)
	{
		scanf("%d", &x);
		st.push(x);
	}
	for (int i = 0, x = 0; i < n; i++)
	{
		x = st.pop();
		printf("%d\n", x);
	}

}