//Класс Cтек на базе Списка:
#include "Container.h"
ListStack::ListStack()
{
	head = 0;
}
ListStack::ListStack(const ListStack &X)
{
	ListStack temp;	
	Node *t = X.head;
	head = temp.head = 0;
	while (t)
	{		
		temp.push(t->item);
		t = t->p;
	}	


	t = temp.head;
	head = NULL;
	while(t !=0)
	{
		push(t->item);
		t=t->p;
	}
};
ListStack::~ListStack()
{
	while (!IsEmpty())
	{
		pop();
	}
};
int ListStack::pop()
{
	if (IsEmpty())
	{
		return -1;
	}
	int x = head->item;
	Node *temp = head;
	head = head->p;
	delete temp;
	return x;
};
void ListStack::push(int x)
{
	if (IsEmpty())
	{
		head = new Node;
		head->p = NULL;
		head->item = x;		
	}
	else
	{
		Node *temp = new Node;
		temp->item = x;
		temp->p = head;
		head = temp;
	}
}
bool ListStack::IsEmpty()
{
	if (head == 0)
		return true;
	return false;
}

bool ListStack::IsFull()
{
	return 0;
}