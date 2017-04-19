//1.	Найти НОД и НОК двух заданных натуральных чисел, используя алгоритм Евклида.
#include <stdio.h>
int main()
{
	int a, b, c, d;
	printf("Input a, b:\n");
	scanf("%d%d", &a, &b);
	c = a;
	d = b;
	if ((a == 0) || (b == 0)) 
	{
		printf("No natural\n");
		return 0;
	}
	while (a != b) 
	{
		if (a < b)
			b = b - a;
		else
			a = a - b;
	}
	b = c * d / b;
	printf("NOD=%d NOK=%d\n", a, b);
	return 0;
}