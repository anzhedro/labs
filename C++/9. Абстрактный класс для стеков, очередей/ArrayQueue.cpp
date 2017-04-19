// Класс Кольцевая очередь:
#include "Container.h"
ArrayQueue::ArrayQueue(int _size): size(_size), head(-1), tail(-1), n(0)
{
	p = new int[size];
}
ArrayQueue::ArrayQueue(ArrayQueue& q)
{
	this->size = q.size;
	n = q.n;
	p = new int[size];
	head = q.head;
	tail = q.tail;
	memcpy(p, q.p, sizeof(int)*size);
}
ArrayQueue::~ArrayQueue()
{
	delete []p;
}
void ArrayQueue::push(int x)
{
	if (!IsFull())
	{
		tail = (tail + 1) % size; 
		p[tail] = x;
		n++;
		if (n == 1) head = tail;
	}
	else
	{
		int *b;
		b = new int[size + 10];
		if (head <= tail)
		{
			memcpy(b, p, sizeof(int) * size );
			size += 10;
		}
		else
		{
			memcpy(b, p + head, sizeof(int)*(size - head ));
			memcpy(b + size - head , p, sizeof(int)*(tail + 1));
			head = 0;
			tail = size - 1;
			size += 10;
		}
		delete []p;
		p = b;
		tail++;
		p[tail] = x;
		n++;
	}
}

int ArrayQueue::del()
{
	if  (IsEmpty()) return -100;
	int z = p[head];
	head = (head + 1) % size;
	n--;
	if (n == 0) head = tail = -1;
	return z;
}

bool ArrayQueue::IsEmpty()
{
	if (n == 0) return true;
	else return false;
}
bool ArrayQueue::IsFull()
{
	if (n == size) return true;
	else return false;
}
