#include "Ratio.h"

int main () {

	ratio a;
	ratio b;
	ratio c;
	double A, B, C;


	cout << " Input 1 rational a ";
	cin >> a;
	cout << " Input 2 rational b ";
	cin >> b;
	cout << " Input 3 rational c ";
	cin >> c;
	a.Reduce();
	b.Reduce();
	c.Reduce();

	A = (double)a;
	B = (double)b;
	C = (double)c;

	cout << "   a    ==  " <<  a <<  endl;
	cout << "   b    ==  " <<  b <<  endl;

	cout << "   A    ==  " <<  A <<  endl;
	cout << "   B    ==  " <<  B <<  endl;
	cout << "   C    ==  " <<  C <<  endl;
	
	cout << "  +a    ==  " << +a <<  endl;
	cout << "  -a    ==  " << -a <<  endl;
	cout << "  +b    ==  " << +b <<  endl;
	cout << "  -b    ==  " << -b <<  endl;

	cout << "  a + b ==  " << a + b <<  endl;
	cout << "  a + b + c ==  " << a + b + c <<  endl;
	cout << "  a - b ==  " << a - b <<  endl;
	cout << "  a - b - c ==  " << a - b - c <<  endl;

	cout << "  a * b ==  " << a * b <<  endl;
	cout << "  a * b * c ==  " << a * b * c <<  endl;
	cout << "  a / b ==  " << a / b <<  endl;
	cout << "  a / b / c ==  " << a / (b - b) / c <<  endl;
	
	ratio d;
	d = (a + b) * (a - b) / (a + b);
	cout << " ---- " << d << endl;
	if (a > b) a = b; else b = a;
	cout << "  a   ==  " << a <<  endl;
	cout << "  b   ==  " << b <<  endl;
}