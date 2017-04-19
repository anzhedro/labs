class Stack
{
private:
	int* st;
	int p;
	int n;
public:
	int pop()
	{
		if (p == -1) return -1;
		return st[p--];
	}
	void push(int x)
	{
		if (p < n-1)
			st[++p] = x;
	}
	int peek()
	{
		return st[p];
	}
	bool empty()
	{
		if (p == -1) return true;
		else 
			return false;
	}
	Stack(int _n)
	{
		st = new int[_n];
		p = -1;
		n = _n;
	}
};