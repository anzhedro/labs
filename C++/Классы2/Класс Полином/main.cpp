#include "Polinom.h"
int main()
{
	setlocale(LC_ALL,".1251");
	Polinom A, B, C;
	cin >> A;
	cout << A;
	cin >> B;
	cout << B;
	cout << "A * B  ==  " << A * B << endl;
	cout << "A + B  ==  " << A + B << endl;
	cout << "A - B  ==  " << A - B << endl;
	C = A - B *(A-B);
	cout << "C  ==  " << C << endl;
	return 0;
}