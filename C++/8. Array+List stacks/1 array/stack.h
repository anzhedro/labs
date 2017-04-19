class stack
{
private:
	int* st;
	int p;
	int n;
public:
	int pop();
	void push(int x);
	int peek();
	bool empty();
	stack(int _n);
	~stack();
};