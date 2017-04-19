//3* Найти все точки с целочисленными координатами, которые находятся внутри круга радиуса R и с центром в точке с координатами 
//   x, y, где R, x, y – действительные числа, которые вводятся с консоли.
#include <stdio.h>
int main()
{
	int c;
	double x, y, R, z, a, b;
	printf("Input x, y, R:\n");
	scanf("%lf%lf%lf", &x, &y, &R);
	a = x;
	b = y;
	x = x - R;
	y = y + R;
	while ((x != a + R) || (y != b - R))
	{
		if ((a - x)*(a - x) + (b - y)*(b - y) <= R * R) 
			printf("%f %f\n", x, y);

		if (x == a + R)
		{
			x = a - R;
			y = y - 1;
		}
		else
			x = x + 1;		
	}
}