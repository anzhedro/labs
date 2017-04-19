#include "deque.h"
Deque::Deque():head(0), tail(0) {}
void Deque::insTail(int n)
{
	if (!tail)
	{
		node *temp = new node();
		temp->item = n;
		temp->next = temp->prev = 0;
		head = tail = temp;
	}
	else
	{
		node *temp = new node();
		temp->item = n;
		temp->next = 0;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}
void Deque::insHead(int n)
{
	if (!head)
	{
		node *temp = new node();
		temp->item = n;
		temp->next = temp->prev = 0;
		head = tail = temp;
	}
	else
	{
		node *temp = new node();
		temp->item = n;
		temp->prev = 0;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}
int Deque::delTail()
{
	if (tail == head)
	{
		int q = tail->item;
		delete tail;
		tail = head = 0;
		return q;
	}
	int q = tail->item;
	tail = tail->prev;
	delete tail->next;
	tail->next = 0;
	return q;
}
int Deque::delHead()
{
	if (tail == head)
	{
		int q = head->item;
		delete head;
		tail = head = 0;
		return q;
	}
	int q = head->item;
	head = head->next;
	delete head->prev;
	head->prev = 0;
	return q;
}
bool Deque::isEmpty()
{
	if (!tail) 
		return true;
	return false;
}
Deque::~Deque()
{
	while (head != tail)
	{
		head = head->next;
		delete head->prev;
	}
	delete head;
}
Deque::Deque(const Deque& d)
{
	node *temp = d.head;
	head = tail = 0;
	while (temp != 0)
	{
		insTail(temp->item);
		temp = temp->next;
	}
}