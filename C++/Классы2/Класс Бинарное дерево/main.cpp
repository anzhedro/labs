#include "BT.h"

int main()
{
	int n;
	BT A;
	cin >> n;
	for (int i = 0, temp = 0; i < n; ++i)
	{
		cin >> temp;
		A.add(temp, &root);
	}
	cout << "\n";
	A.print(root);
}