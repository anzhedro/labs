#include <fstream>
#include <iostream>
#include <math.h>
int main()
{
    int a[500][500]; // ������� ��������� �����, ��� -1 �������� ���������� ����� ����� ���������, 
	                 // � ����� ��������������� ����� � ����������� ����� ������� ����
	int d[500] = {0}, q[500]; 
	int n; // ���������� ������ �����
	int first; // ��������� �������
	int last; // �������� ������� 
	int flag[500], l, min1 = 100000000, nmin=0;
   
	for (int i = 0; i <= 500 ; i++) 
		flag[i] = 1;

    std:: ifstream IN("input.txt");
    IN >> n >> first >> last;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)//����
    {
     IN >> a[i][j];
     if (a[i][j] == -1 && i != j) a[i][j] = 32000;
    }
    IN.close();
    l = first;
    for (int i = 1; i <= n; i++) 
		d[i] = a[l][i]; //������� ��������� �������� ������� d
    flag[l] = 0;
    
    for (int i = 1; i <= n-1; i++)
    {
        min1 = 100000000;
        nmin = l;
        for (int j = 1; j <= n; j++)
        if (flag[j] != 0 && min1 > d[j]) 
        { 
           min1 = d[j]; 
           nmin = j; 
        } // ���� ��������� �������
        
		q[i] = min1;
        l = nmin;
        
        flag[l] = 0;
        
        for (int j = 1;j <= n;j++)
        if (flag[j] != 0) 
        d[j] = fmin(d[j], a[l][j] + d[l]); //����������� ���������� �� d[j]
        
    }
    
    
    std:: ofstream OUT ("output.txt");
    if (d[last] == 32000) OUT << "-1";
    else OUT << d[last];
	OUT << "\n";
	for (int i = 1; i <= n; i++)
	{
    for (int j = 1; j <= n; j++)//����
     OUT << a[i][j] << " ";
	OUT << "\n";
	}
	OUT << "\n";
	OUT << "\n";

	for (int j = 1; j <= n; j++)//����
     OUT << d[j] << " ";

OUT << "\n";
OUT << "\n";
	for (int j = 1; j <= n; j++)//����
     OUT << d[j] << " ";

    OUT.close();
    return 0;
}