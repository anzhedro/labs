//1* Разложить заданное натуральное число на простые множители.
#include <stdio.h>
int main()
{
	int a;
	printf("Input number:\n");
	scanf("%d", &a);
	printf("Mnoziteli: ");
	while (a != 1) 
	{
		for (int i = 2; i <= a; i++)
			if (a % i == 0)
			{
				printf("%d ", i);
					a = a / i;
				break;
			}
	}
}