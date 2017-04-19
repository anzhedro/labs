#include <iostream>
using namespace std;

int main()
{
	double e = 1.0;
	int k = 0;
	while (e > abs(3.0*(4.0/3.0 - 1.0) - 1.0))
	{
		e = e / 2.0;
		k++;
	}
	cout << "del na 2 = " << k << endl;
	cout << "e = " << e << endl;

}