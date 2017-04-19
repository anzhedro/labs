#include <stdio.h>
int main()
{
	int a[30];
	int n = 0, men, bol;
	unsigned q;
	scanf("%d", &q);
	while (q!=0)
	{
		a[n] = q % 10;
		q /= 10;
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		men = 0;
		bol = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i] < a[j]) men++;
			if (a[i] > a[j]) bol++;
		}
		if (men == bol)
		{
			printf("%d\n", a[i]);
			return 0;
		}
	}
	printf("no mid\n");
	return 0;
}