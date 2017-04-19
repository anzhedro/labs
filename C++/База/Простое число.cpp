//Определить, является ли заданное натуральное число простым.
#include <stdio.h>
int main()
{
	int a, b, c;
	printf("Input number:\n");
	scanf("%d", &a);
	if (a == 0)
	for (int i = 2; i <= a / 2; i++)
	{
		if (a % i == 0) 
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}