//���������� ���� ��� ������
//������������������ ����� ����� ������������ �����
//� ����������� ���� ������������������
//� �������� �������.

#include <iostream> 
#include <vector> 
#include <stack> 
using namespace std;

int main()
{ 
	stack <int, deque<int> > S;
	int x; 
	cout << "Enter some integers, followed by a letter:\n"; 
	while (cin >> x) 
		S.push(x); 
	while (!S.empty())
	{ 
		x = S.top();
		cout << "Size: " << S.size() << "   Element at the top: " << x << endl; 
		S.pop(); 
	}

	return 0; }