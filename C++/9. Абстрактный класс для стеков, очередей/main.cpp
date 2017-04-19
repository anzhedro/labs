#include <iostream>
#include "Container.h"
using std::cout;
int main()
{

	ListStack LS;
	ArrayStack AS;
	ArrayQueue AQ;
	cout << "------------------------------PUSH & POP----------------------------------------\n";
	for(int i = 0; i < 5; i++)
	{
		LS.push(i * 10);
		AS.push(i * 10);
		AQ.push(i * 10);

	}
	cout << "_ListStack_  : \n";
	for(int i = 0; i < 5; i++)
	{
		cout << LS.pop() << ' ';
	}
	cout << "\n_ArrayStack_ : \n";

	for(int i = 0; i < 5; i++)
	{
		cout << AS.pop() << ' ';
	}
	cout << "\n_ArrayQueue_ : \n";
	for(int i = 0; i < 5; i++)
	{
		cout << AQ.del() << ' ';
	}
	cout << "\n------------------------------ABSTRACT------------------------------------------\n";


	ListStack  Q;
	ArrayStack A(1);
	ArrayQueue QA(1);

	AbstractStack *ASS, *WAS;
	AbstractQueue *Z;
	WAS = &Q;
	ASS = &A;
	Z   = &QA; 
	for (int i = 0; i < 5; i++)
	{
		WAS->push(i * 10);
		ASS->push(i * 10);
		Z->push(i * 10);
	}
	cout << "\n_AbstractStack - ListStack_ : \n";
	for (int i = 0; i < 5; i++)
	{
		cout << WAS->pop() << " ";
	}
	cout << "\n_AbstractStack - ArrayStack_ : \n";
	for (int i = 0; i < 5; i++)
	{
		cout << ASS->pop() << " ";
	}
	cout << "\n_AbstractQueue - ArrayQueue_ : \n";
	for (int i = 0; i < 5; i++)
	{
		cout << Z->del() << " ";
	}



	ArrayStack B(A);
	ArrayQueue C(QA);

	cout<<"\n------------------------------ITERATOR------------------------------------------\n";
	for(int i = 5; i < 10; i++)
	{
		B.push(i * 10);
		C.push(i * 10);
	}

	ArrayStackIterator ITT2(B);
	QueueIterator ITTT(C);


	AbstractIterator &ITT = ITT2;


	cout << "\n_Iterator - ArrayStack_ : \n";
	while(ITT.InRange())
	{
		cout << *ITT <<' ';
		ITT++;
	}
	cout << "\n_Iterator - ArrayQueue_ : \n";
	while(ITTT.InRange())
	{
		cout << *ITTT <<' ';
		ITTT++;
	}



	ListStack I;
	for(int i = 5; i < 10; i++)
	{
		I.push(i * 10);
	}

	ListStackIterator II2(I);
	AbstractIterator &II = II2;
	cout << "\n_Iterator - ListStack_ : \n";
	while(II.InRange()==true)
	{
		cout << *II << ' ' ;
		II++;
	}
	cout << "\n--------------------------------------------------------------------------------\n";
	return 0;
}