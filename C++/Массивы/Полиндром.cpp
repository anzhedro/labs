#include <stdio.h>
int main()
{
	int a[10]={0,};
	int b, c = 0 , q1 = 0, q2 = 0, r = 1, v = 0, l =0, z = 0, x =0;
	scanf("%d", &b);
	while (b != 0)
	{
		a[b % 10]++;
		b /= 10;
	}
	for (int i=0; i < 10; i++)
		if (a[i] % 2 == 1)
			c++;
	if (c > 1) 
	{
		printf("net polindroma\n");
		return 0;
	}
	

	if (a[0] % 2 == 0)
		x = a[0] / 2;
		


	for (int i=9; i >= 0; i--)
	{
		if (a[i] % 2 == 1)
		{
			v = i;
			a[i] -=1;
			l = 1;
		}
		if ((a[i] % 2 == 0) && (a[i] > 0)) 
		{
			while (a[i] > 0)
			{
				q1 = q1 * 10 + i;
				q2 = q2 + r * i;
				r *= 10;
				a[i]-=2;
			}
		}
	}
	if (l == 1)
		q1 = (q1 *10 + v)*r + q2;
	else
		q1 = q1 * r + q2;

	if (x > 0)
	{
		for (int i = 0; i < x; i ++)
			printf("0");
		printf("%d", q1);
	}

	else 
		printf ("%d", q1);
}