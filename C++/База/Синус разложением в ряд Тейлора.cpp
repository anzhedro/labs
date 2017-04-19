//4* Вычислить значение функции sinx с точностью , используя разложение в ряд Тейлора.
#include <stdio.h>
#include <math.h>
int main()
{
	int n, b, z;
	double e, a, x, l;
	printf("Input e, x:\n");
	scanf("%lf%lf", &e,&x);
	double s1, s2;
	printf("sin = %12.12f\n", sin(x));
	s1 = x;
	s2 = s1 + ((-1) * pow(x, 3)) / 6;
	n = 1;
	a = 1;
	z = 3;
	l = ((-1) * pow(x, 3)) / 6;
	while (abs(s2 - s1) > e) 
	{
		s1 = s2;
		a = -1 * a;
		z++;
		l = (l * a * x * x)/z;
		z++;
		l = l / z;
		s2 += l;
		/*a = (pow(-1.0, n) * pow(x, (2 * n + 1))); 
		for (int i = 1; i <= (2 * n + 1); i++) 
			a /= i;
		s2 += a;*/ 				
	}
	printf("symma = %12.12f\n", s2);
	return 0;
}