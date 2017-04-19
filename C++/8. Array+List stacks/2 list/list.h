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
	mystack();
	void push(int x);
	int pop();
	bool is_empty();
};