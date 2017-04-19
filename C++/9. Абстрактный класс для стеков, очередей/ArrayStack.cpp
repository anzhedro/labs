#include "Container.h"
#include <string.h>
int ArrayStack::pop()
{
	if (top == -1) return -1;
	return p[top--];
}
void ArrayStack::push(const int x)
{
	if (top < size-1)
		p[++top] = x;
	else
	{
		int *temp = new int[size + 10];
		for (int i =0; i < size; i++)
			temp[i] = p[i];
		delete []p;
		size += 10;
		p = temp;
		p[++top] = x;
	}
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
ArrayStack::ArrayStack(ArrayStack &s) 
{
	size = s.size;
	p = new int[size];
	top = s.top;	
	memcpy(p, s.p, sizeof(int)*size);
}