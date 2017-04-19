#include <iostream>
#include "ArrayStack.h"
using namespace std;
//void menu()
//{
//	cout<<"Choose:"<<endl;
//	cout<<"1. PUSH."<<endl;
//	cout<<"2. POP."<<endl;
//	cout<<"3. END."<<endl;
//}
struct POINT
{
	int x, y;
	friend istream& operator>>(istream& in, POINT& r)
	{
		in >> r.x >> r.y;
		return in;
	}
	friend ostream& operator<<(ostream& out, const POINT& r)
	{
		out << r.x << " " << r.y << endl;
		return out;
	}
};
int main()
{
	try
	{
	ArrayStack <POINT> My(2);
	POINT a, b, c;
	cin >> a;
	cin >> b;
	My.push(a);
	My.push(b);
	cout << endl;
	c = My.pop();
	cout << c;
	c = My.pop();
	cout << c;
	c = My.pop();
	/*int f;
	double d;
	for(;;)
	{
		menu();
		cin >> f;
		if (f == 1)
		{
			cout << "INPUT: ";
			cin >> d;
			My.push(d);
		}
		if (f == 2)
		{
			cout << "LAST: ";
			cout << My.pop() << endl;
		}
		if (f==3)
			return 0;
	}*/
	}
		catch (BAD)
		{
			cout << "EMPTY";
		}
	return 0;
}