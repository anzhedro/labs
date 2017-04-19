#include "stll.h"
#include <iostream>
using namespace std;
Stack::Stack()
{
	head=0;
}
Stack::Stack(const Stack &X)
{
	head=0;
	Stack A1;	
	Node *temp;	
	temp=X.head;
	while (temp)
	{		
		push(temp->item);
		temp=temp->p;
	}	
};
Stack::~Stack()
{
	Node *temp;
	temp=head;
	Node *t;
	while (temp)
	{	t=temp;
		t=t->p;
		del();
		temp=t;
	}
};
int Stack::del()
{
	if (isEmpty())
	{
		return -1;
	}
	int x=head->item;
	Node *temp=head;
	head=head->p;
	delete temp;
	return x;
};
void Stack::push(const int& x)
{
	if (isEmpty())
	{
		head=new Node;
		head->p=NULL;
		head->item=x;		
	}
	else
	{
		Node *temp;
		temp=new Node;
		temp->item=x;
		temp->p=head;
		head=temp;
	}
}
bool Stack::isEmpty()
{
	if (head==0)
		return true;
	return false;
};
void Stack::print()
{
	Node *temp=new Node;
	temp=head;
	while (temp)
	{
		cout<<temp->item<<" ";
		temp=temp->p;		
	}		
	cout<<endl;
};
