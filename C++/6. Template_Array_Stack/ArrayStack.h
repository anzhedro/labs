struct BAD{};
template <class T>
class ArrayStack
{
	int size;
	int top;
	T *p;
public:
	ArrayStack(const int& _size);
	ArrayStack(ArrayStack &s)
	{
		size = s.size;
		p = new T[size];
		for(int q = 0; q < size; q++)
		{
			p[q] = s.p[q];
		}
		top = s.top;
	}
	~ArrayStack();
	void push(const T &x);
	T pop();
	bool isEmpty();
	bool isFull();
	friend class <T>ArrayStackIterator;
};
template <class T> 
ArrayStack <T>::ArrayStack(const int& _size)			//Конструктор
{
	size = _size;
	p = new T[size];
	top = 0;
}
template <class T> 
ArrayStack <T>::~ArrayStack()							//Деструктор
{
	delete []p;
}
template <class T> 
void ArrayStack <T> ::push(const T& n)					//Втолкнуть элемент в стек
{
	if (isFull() == 1)
		{
			T *K;
			K = new T[size + 10];
			for(int q = 0; q < size; q ++)
				K[q] = p[q];
			delete []p;
			p = K;
			size = size + 10;
		}
		p[top++] = n;
}
template <class T> 
T ArrayStack <T> ::pop()								//Вытолкнуть элемент из стека							
{
	if (isEmpty() == 1)
		{
			throw BAD();
		}
	else 
	{	
		top--;
		return p[top];
	}
}
template <class T> 
bool ArrayStack <T> ::isEmpty()							//Пустой стек?
{
	if (top == 0)
			return 1;
		return 0;
}
template <class T> 
bool ArrayStack <T> ::isFull()							//Полный стек?
{
	if (top == size)
		return 1;
	return 0;
}

template <class T>
class ArrayStackIterator: public ArrayStack
{
	ArrayStack	<T>&a;			
	int	     	pos;			
public:
	ArrayStackIterator( ArrayStack<T>& _a):pos (_a.top), a(_a){}
	bool InRange() const    { if(pos < 0 || pos > a.top) return false; return true;}
	void Reset()            { pos = 0; return;}
	void operator++()       { if(InRange()) {--pos; return;} else return;}
	void operator++(int)    { if(InRange()) {pos--; return;} else return;}
	T operator *() const { return a.p[pos];}
};