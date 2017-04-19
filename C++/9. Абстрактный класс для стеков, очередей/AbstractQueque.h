// Класс Кольцевая очередь:
class ArrayQueue: public AbstractQueue 
{
protected:
	int		size;			// размерность массива
	int*	p;				// указатель на массив
	int		head;			// индекс первого занятого элемента
	int		n;			// количество элементов в очереди
public:
	ArrayQueue(int _size = 16);
	ArrayQueue(ArrayQueue &q);
	~ArrayQueue();
	void push(const int& n);		// втолкнуть в очередь 
	void del(int& n);			// удалить из очереди
	bool IsEmpty() const;
	bool IsFull() const;
	friend class QueueIterator;
};

// Класс Дек:
class ArrayDequeue: public ArrayQueue
{
public:
	ArrayDequeue(int _size = 16);
	ArrayDequeue(const ArrayDequeue &d);
	~ArrayDequeue();
	virtual void pop(int& n);		// вытолкнуть из дека со стороны push
	virtual void ins(const int& n);		// вставить в дек со стороны del
};