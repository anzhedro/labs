#include "stack.h"
int stack::pop()
{
	if (p == -1) return -1;
	return st[p--];
}
void stack::push(int x)
{
	if (p < n-1)
		st[++p] = x;
	else
	{
		int *temp = new int[n];
		for (int i =0; i < n; i++)
			temp[i] = st[i];
		st = new int[n+10];
		for (int i =0; i < n; i++)
			st[i] = temp[i];
		n += 10;
		delete []temp;
	}
}
int stack::peek()
{
	return st[p];
}
bool stack::empty()
{
	if (p == -1) return true;
	else 
		return false;
}
stack::stack(int _n)
{
	st = new int[_n];
	p = -1;
	n = _n;
}
stack::~stack()
{
	p = -1;
	n = 0;
	delete []st;
}