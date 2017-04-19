//2* Получить, если это возможно, для заданного натурального числа x палиндром.
#include <stdio.h>
int main()
{
	int c, x, x1;
	printf("Input number:\n");
	scanf("%d", &x);
	do
	{
		x1 = x;
		c = 0;
		while (x1 != 0) 
		{
			c = c * 10 + x1 % 10;
			x1 = x1 / 10;
		}
		if (c == x)
		{
			printf("%d", c);
			return 0;
		}
		x += c;
	}
	while (true);
}