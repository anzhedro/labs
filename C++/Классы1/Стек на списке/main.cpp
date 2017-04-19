#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stll.h"
int main()
{
	int n;
	scanf("%d", &n);
	Stack st;
	for (int i = 0, x = 0; i < n; i++)
	{
		scanf("%d", &x);
		st.push(x);
	}
	for (int i = 0, x = 0; i < n; i++)
	{
		x = st.del();
		printf("%d\n", x);
	}
	

}