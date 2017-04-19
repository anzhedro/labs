#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
	int deg;
	double coeff;
	node *next;
	node()
	{
		deg = 0;
		coeff = 0.0;
		next = NULL;
	};
	node(double coeff1, int deg1)
	{
		coeff = coeff1;
		deg = deg1;
	};
};
class Plist
{	
	node *head, *tail;
	int count;
public:
	Plist();
	Plist(const Plist&);
	~Plist();
	void pushback(const node&);
	void del();
	bool isEmpty();
	void print();
	node* get_head()
	{
		return head;
	};
	Plist& operator =(const Plist &X);
};