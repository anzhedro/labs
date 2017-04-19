#include <iostream>

using std:: cout;

struct Node
{
	int info;
	Node *next;
	Node(int x,Node *top)
	{
		info = x;
		next = top;
	}
};


class mystack
{
	Node *first;
public:
	mystack() {
		first = NULL;
	}
	void push(int x);
	void print();
	int pop();
	bool is_empty();
};

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
void mystack::print()
{
	Node *temp = first;
	while (temp)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << std::endl;
}
bool mystack::is_empty()
{
	return (!first)? true : false; 
}

void main()
{
	mystack n;
	mystack m;
	n.push(10);
	n.push(25);
	n.push(35);
	n.print();
	while (!n.is_empty())
	{
		m.push(n.pop());
	}
	n.print();
	m.print();
}