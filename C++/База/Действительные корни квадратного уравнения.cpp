//	Найти действительные корни квадратного уравнения.
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, d, e, x1, x2;
	printf("a*x^2+b*x+c=0\n");
	printf("Input a, b, c:\n");
	scanf("%d%d%d", &a, &b, &c);
	d = b * b - 4 * a * c;
	if (d < 0)
	{
		printf("Error");
			return 0;
	}
	x1 = (-1 * b + sqrt((double) d)) / (2 * a);
	x2 = (-1 * b - sqrt((double) d)) / (2 * a);
	printf("x1=%d, x2=%d", x1, x2);
	return 0;
}