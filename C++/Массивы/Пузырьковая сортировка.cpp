#include <stdio.h>
void main()
{
	int arr[20];
	int i, n, tmp, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	for(i = 0; i < n - 1; ++i) // i - номер прохода
	{            
		for(j = 0; j < n - 1; ++j) // внутренний цикл прохода
		{     
			if (arr[j + 1] < arr[j]) 
			{
				tmp = arr[j + 1]; 
				arr[j + 1] = arr[j]; 
				arr[j] = tmp;
			}
		}
	}
	for(i = 0; i < n; ++i)
		printf("%d ", arr[i]);
}