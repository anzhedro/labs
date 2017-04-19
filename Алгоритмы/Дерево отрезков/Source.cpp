#include <cstdio>
#include <algorithm>

using namespace std;
#define INF 1000000000 // ������������, ��� ����� ������ ������ �� �����.

#define TREE_REAL_DATA 1024     // ������������ ���������� ���������� ���������
int tree_data[TREE_REAL_DATA * 2];  

// �������� ������� ������.
// ���������: p - ������� �������(������������� �������� �������).
// l, p - ����� � ������ ������� �������, ��� �������� tree_data[p] �������� ����������.
// ������ ����� ���� �������� ��� ���� ����������, � ���������� �� ������ �� p, �� ��� ����� � ��������.
// a, b - ����� � ������ ������� �������, ��� �������� ���������� ����� �������.
int __tree_find_max(int p, int l, int r, int a, int b) 
{
	if (b < l || r < a) return -INF;
	if (a <= l && r <= b) return tree_data[p];
	int r1 = __tree_find_max(p*2  , l, (l+r) / 2,   a, b); // ����� ������ ������
	int r2 = __tree_find_max(p*2+1, (l+r)/2 + 1, r, a, b); // ����� ������� ������
	return max(r1, r2); // ���������� �������� �� ������ � ������� �����������
}

// ����� ���������� �������� ��� ������� ����.
int tree_find_max(int a, int b)
{
	return __tree_find_max(1, 0, TREE_REAL_DATA - 1, a, b);
}

// ���������� �������� � �.
void tree_update(int p, int x) 
{
	p += TREE_REAL_DATA; // �������������� ������� p � ������� � ����� ������ ������,
	// � ������� ������� ��������� ������ �� ����������.
	tree_data[p] = x;
	for(p/=2; p ; p/=2) {
		if (tree_data[p * 2] > tree_data[p * 2 + 1])
			tree_data[p] = tree_data[p * 2];
		else tree_data[p] = tree_data[p * 2 + 1];
	}
} 

// ���������� ������������� - ��������� ���� �������� � -INF
void tree_init()
{
	for (int i = 0; i < TREE_REAL_DATA * 2; i++) 
		tree_data[i] = -INF;
}

int main()
{
	tree_init();
	while ( 1 ){
		char c;
		scanf_s("%c", &c);
		if (c == 'Q') return 0; // �����
		if (c == 'F') {  // ����� �������� �� ��������� a..b
			int a, b;
			scanf_s("%d%d", &a, &b);
			printf("%d\n", tree_find_max(a, b));
		}
		if (c == 'U') { // ���������� �������� �������� p ����� x.
			int p, x; 
			scanf_s("%d%d", &p, &x);
			tree_update(p, x);
		}
	}
}