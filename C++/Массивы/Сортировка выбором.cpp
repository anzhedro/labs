#include <stdio.h>
void main()
{
	int a[20];
    int tmp, i, j, pos, n;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);
    for(i = 0; i < n; ++i) // i - ����� �������� ����
    { 
        pos = i; 
        tmp = a[i];
        for(j = i + 1; j < n; ++j) // ���� ������ ����������� ��������
        {
            if (a[j] < tmp) 
            {
               pos = j; 
               tmp = a[j]; 
            }
        }
        a[pos] = a[i]; 
        a[i] = tmp; // ������ ������� ���������� � a[i]
    }
	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);
}