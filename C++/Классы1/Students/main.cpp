#include "stud.h"
int main()
{
	int n;
	cout << "Input number of students: ";
	cin >> n;
	cout << "Name: Num: Grade:\n";
	StudContainer A(n);
	for (int i = 0; i < n; ++i)
		cin >> A.p[i];

	while (true)
	{
		int e = 0;
		cout << "Input nuber: 1 - Sort Name, 2 - Search, 3 - Sort Num, 4 - Grades, 6 - Insert, 7 - Delete, 8 - Print List, 9 - Exit\n"; 
		cin >> e;

		if (e == 1) 
		{
			A.sortByName();
			A.print(cout);
		}

		if (e == 2) 
		{
			char q[10];
			cout << "Input Name of student:\n";
			cin >> q;
			Student* r;
			r = A.findByName(q);
			cout << *r;
		}
		if (e == 3)
		{
			A.SortByNumAndName();
			A.print(cout);
		}
		if  (e == 4)
		{
			A.report();
		}
		if (e == 6)
		{
			Student Name;
			cout << "Input Name to Insert:\n";
			cin >> Name;
			A.insert(Name);
		}
		if (e == 7)
		{
			char* DNAME = new char[10];
			cout << "Input Name to Delete:\n";
			cin >> DNAME;
			A.del(DNAME);
		}
		if (e == 8) 
			A.print(cout);
		if (e == 9) break;
	}
}