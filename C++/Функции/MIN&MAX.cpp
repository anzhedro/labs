#include <stdio.h>
int mm(int* min, int *max, int n, int a[20])
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] > *max) *max = a[i];
		if (a[i] < *min) *min = a[i];
	}
	return;
}
int main()
{
	int a[20];
	int min, max, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	scanf("%d", &a[i]);
	min = a[0];
	max = a[0];
	mm(&min, &max, n, a);
	printf("min = %d, max = %d/n", min, max);
}