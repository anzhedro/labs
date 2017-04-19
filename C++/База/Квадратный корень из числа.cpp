//5.	Вычислить квадратный корень из положительного действительного числа x с точностью e.
#include <stdio.h>
#include <math.h>
int main()
{
	int k = 0, m, i=0;
	double y, y0, e, x, v;
	printf("Input e, x:\n");
	scanf("%lf%lf", &e,&x);
	v = sqrt(x);
	printf("sqrt= %12.12f ", v);
	while (true)
	{
		double a = pow(2.0, i);
		if ((x / a) >= 1 / 2 && ((x / a) < 1))
			break;
		i++;
	}
	k = i / 2;
	y0 = pow(2.0, k);
	y = 1.0/2.0 * (y0 + x / y0);
	while (abs(y - y0) > e)
	{
		y0 = y;
		y = 1.0/2 * (y0 + x /y0);
	}
	printf("\n%12.12f\n", y);
}