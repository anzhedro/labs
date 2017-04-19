#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"
int main()
{
	int n;
	scanf("%d", &n);
	List st;
	for (int i = 0, x = 0; i < n; i++)
	{
		scanf("%d", &x);
		st.insTail(x);
	}
	for (int i = 0, x = 0; i < n; i++)
	{
		x = st.delTail();
		printf("%d\n", x);
	}
	

}