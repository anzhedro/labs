// ����� ��������� �������:
class ArrayQueue: public AbstractQueue 
{
protected:
	int		size;			// ����������� �������
	int*	p;				// ��������� �� ������
	int		head;			// ������ ������� �������� ��������
	int		n;			// ���������� ��������� � �������
public:
	ArrayQueue(int _size = 16);
	ArrayQueue(ArrayQueue &q);
	~ArrayQueue();
	void push(const int& n);		// ��������� � ������� 
	void del(int& n);			// ������� �� �������
	bool IsEmpty() const;
	bool IsFull() const;
	friend class QueueIterator;
};

// ����� ���:
class ArrayDequeue: public ArrayQueue
{
public:
	ArrayDequeue(int _size = 16);
	ArrayDequeue(const ArrayDequeue &d);
	~ArrayDequeue();
	virtual void pop(int& n);		// ���������� �� ���� �� ������� push
	virtual void ins(const int& n);		// �������� � ��� �� ������� del
};