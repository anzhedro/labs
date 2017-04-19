#include <stdio.h>
#include <stdarg.h>
int  print(int n, ...)
{
	int s = 0, pr = 1;
	va_list	a;
	if (n < 1)
	{
		printf("There are no numbers.\n");
		return 0;
	}
	printf("Number of parameters = %d\n", n);
	va_start(a, n);
	while (n)		
	{
		int x;
		x = va_arg(a, int);
		s += x;
		pr *= x;
		--n;
	}
	printf("pr = %d, s = %d\n", pr, s);

	va_end(a);

	return  0;
}
int main()
{
	print(3, 4, 5, 6);
	return 0;
}
