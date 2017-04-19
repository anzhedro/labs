#include <stdio.h>
void main()
{
	int a[20];
	int i, n, tmp, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
    for (i = 1; i < n; ++i) 
    {
        tmp = a[i]; 
        for (j = i - 1; j >= 0 && a[j] > tmp; --j) // поеста элемента в готовой последовательности 
            a[j + 1] = a[j];    // сдвигаем элемент направо, пока не дошли
        a[j + 1] = tmp; // место найдено, вставить элемент    
    }

	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);
}