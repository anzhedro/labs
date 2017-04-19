#include "Plist.h"
Plist::Plist():head(0),tail(0), count(0){}
Plist::Plist(const Plist &X)
{
	head = 0;
	tail = 0;
	node *temp;
	temp = X.head;
	while (temp)
	{
		pushback(*temp);
		temp = temp->next;
	}
}

Plist::~Plist()
{
	node *temp;
	temp = head;
	while (temp)
	{
		del();
		temp = head;
	}
}

void Plist::pushback(const node &X)
{
	if (isEmpty())
	{
		head = new node;
		head->coeff = X.coeff;
		head->deg = X.deg;
		head->next = NULL;
		tail = head;
	}
	else
	{
		node *temp;
		temp = new node;
		temp->coeff = X.coeff;
		temp->deg = X.deg;
		tail->next = temp;
		tail = temp;
	}
}	
void Plist::del()
{
	if (isEmpty())
		return;
	else
	{
		node *temp=head;
		head = head->next;
		if (head == 0)
			tail = 0;
		delete temp;
	}
}
bool Plist::isEmpty()
{
	if (head == 0)
		return true;
	return false;
}
void Plist::print()
{
	node *temp;
	temp = head;
	while (temp)
	{
		cout << temp->coeff << "x^" << temp->deg << " ";
		temp = temp->next;
	}
	cout<<endl;
}
Plist& Plist::operator =(const Plist &X)
{
	if (this == &X)
		return *this;
	node *temp;
	//Plist Y;
	this->del();
	this->head = 0;
	this->tail = 0;
	temp = X.head;
	while (temp)
	{
		this->pushback(*temp);
		temp = temp->next;
	}
	//*this=Y;
	return *this;
}
