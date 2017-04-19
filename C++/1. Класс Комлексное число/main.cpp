//#include <iostream>
#include "Complex.h"

using std:: cout;
using std:: cin;

int main () {

	Complex a;
	Complex b;


	cout << " Input first complex a ";
	cin >> a;

	cout << " Input second complex b ";
	cin >> b; 

	cout << "a = " << a << '\n';
	cout << "b = " << b << '\n';
	cout << "a + b = " << a + b << '\n';
	cout << "a - b = " << a - b << '\n';
	cout << "a * b = " << a * b << '\n';
	return 0;
}