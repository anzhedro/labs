#include "Stack.h"
#include <string.h>
int ArrayStack::pop()
{
	if (top == -1) return -1;
	return p[top--];
}
void ArrayStack::push(int x)
{
	if (top < size-1)
		p[++top] = x;
	else
	{
		int *temp = new int[size];
		for (int i =0; i < size; i++)
			temp[i] = p[i];
		delete []p;
		p = new int[size+10];
		for (int i =0; i < size; i++)
			p[i] = temp[i];
		size += 10;
		delete []temp;
		p[++top] = x;
	}
}
int ArrayStack::peek()
{
	return p[top];
}
bool ArrayStack::IsEmpty()
{
	if (top == -1) 
		return true;
	else 
		return false;
}
bool ArrayStack::IsFull()
{ 
	if (top == size-1)
		return true;
	else
		return false;
}

ArrayStack::ArrayStack(int _size)
{
	p = new int[_size];
	top = -1;
	size = _size;
}
ArrayStack::~ArrayStack()
{
	top = -1;
	size = 0;
	delete []p;
}
ArrayStack::ArrayStack(const ArrayStack &s) 
{
	size = s.size;
	p = new int[size];
	top = s.top;	
	memcpy(p, s.p, sizeof(int)*size);
}