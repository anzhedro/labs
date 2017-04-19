#include <iostream>
class AbstractContainer
{
public:
	virtual ~AbstractContainer() {};
	virtual bool IsEmpty()  = 0;		// контейнер пуст
	virtual bool IsFull()   = 0;		// контейнер полный
};

class AbstractQueue: public AbstractContainer
{
public:
	virtual void push(int n) = 0;	// втолкнуть в очередь 
	virtual int  del() = 0;			// удалить из очереди
};
class AbstractStack: public AbstractContainer
{
public:
	virtual void push(int n) = 0;		// втолкнуть в стек
	virtual int pop()  = 0;			// вытолкнуть из стека
};




class ArrayStack: public AbstractStack
{
protected:
	int		size;	
	int*	p;		
	int		top;	
public:
	ArrayStack(int _size = 16);
	ArrayStack(ArrayStack &s);
	~ArrayStack();
	void push(int n);
	int pop();		
	bool IsEmpty() ;
	bool IsFull()  ;
	friend class ArrayStackIterator;
};


class ArrayQueue: public AbstractQueue 
{
protected:
	int		size;		
	int*	p;			
	int		head;			// индекс первого занятого элемента
	int     tail;
	int		n;			// количество элементов в очереди
public:
	ArrayQueue(int _size = 16);
	ArrayQueue(ArrayQueue &q);
	~ArrayQueue();
	void push(int);	
	int del();			
	bool IsEmpty() ;
	bool IsFull() ;
	friend class QueueIterator;
};



class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0;		
	virtual void Reset() = 0;			
	virtual int& operator *() const = 0;
	virtual void operator ++() = 0;		
};

class ArrayStackIterator: public AbstractIterator
{
	ArrayStack	&a;			
	int	     	pos;			
public:
	ArrayStackIterator( ArrayStack& _a):pos (_a.top), a(_a){}
	bool InRange() const    { if(pos < 0 || pos > a.top) return false; return true;}
	void Reset()            { pos = 0; return;}
	void operator++()       { if(InRange()) {--pos; return;} else return;}
	void operator++(int)    { if(InRange()) {pos--; return;} else return;}
	int& operator *() const { return a.p[pos];}
};


class QueueIterator: public AbstractIterator
{
	ArrayQueue	&a;			
	int		    pos;			
public:
	QueueIterator(ArrayQueue& _a):pos(0), a(_a){}
	void Reset()              { pos = a.head; return;}
	bool InRange() const      {	if(pos<a.head || pos>a.tail) return false; return true;}
	void operator++()         { if(InRange()) { ++pos; return;} else return;}
	void operator++(int)      { if(InRange()) { pos++; return;} else return;}
	int& operator*() const    { return a.p[pos];}
};


struct Node
	{
		int item;
		Node *p;
	};
class ListStack: public AbstractStack
{
	Node *head;
public:
	ListStack();
	ListStack(const ListStack&);
	~ListStack();
	void push(int n);
	int pop();
	bool IsEmpty();
	bool IsFull();
	friend class ListStackIterator;
};

class ListStackIterator: public AbstractIterator
{
	ListStack& a;
	Node *pos;
public:
	ListStackIterator(ListStack& _a):a(_a), pos(_a.head) {}
	void Reset()              { pos = a.head; return;}
	bool InRange() const {
		if (pos != NULL)
			return true; 
		else false;}
	void  operator ++()
	{
		pos = pos->p;
	}
	void  operator ++(int)
	{
		pos = pos->p;
	}
	int& operator*() const
	{
		return pos->item;
	}
};