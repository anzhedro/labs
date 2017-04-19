class Stack
{
	struct Node
	{
		int item;
		Node *p;
	};
	Node *head;
public:
	Stack();
	Stack(const Stack&);
	~Stack();
	void push(const int&);
	int del();
	bool isEmpty();
	void print();
};