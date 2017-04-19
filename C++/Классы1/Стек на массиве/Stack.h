class ArrayStack
{
private:
	int top;
	int* p;
	int size;
public:
	int pop();
	void push(int);
	int peek();
	bool IsEmpty();
	bool IsFull();
	ArrayStack(int);
	~ArrayStack();
	ArrayStack(const ArrayStack&);  
};