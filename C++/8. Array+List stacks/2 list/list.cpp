#include "list.h"
void mystack::push(int x)
{
	Node *temp = new Node(x,first);
	first = temp;
}
int mystack::pop()
{
	Node *temp = first->next;
	int x = first->info;
	delete first;
	first = temp;
	return x;
}
bool mystack::is_empty()
{
	return (!first)? true : false; 
}
mystack::mystack() 
{
	first = 0;
}
