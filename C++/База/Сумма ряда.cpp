//Найти сумму ряда
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, n;
	double e;
	printf("Input e:\n");
	scanf("%lf", &e);
	double s1, s2;
	s1 = -1;
	s2 = 1.0 / 9 - 1;
	n = 2;
	while (abs(s2 - s1) > e) 
	{
		n++;
		s1 = s2;
		if (n % 2 == 0)  
			s2 = s2 + (1.0 / ((2 * n - 1) * (2 * n - 1)));
		else
			s2 = s2 + ((-1.0) / ((2 * n - 1) * (2 * n - 1)));		
	}
	printf("symma = %f\n", s2);
	return 0;
}