class Deque		
{
	struct node			
	{
		int  item;	
		struct  node*  next; 
		struct  node*  prev;  
	};
	struct node *head, *tail;
public:
	Deque();			
	Deque(const Deque& d);	// ����������� �����������
	~Deque();		
	void insHead(int n);	
	void insTail(int n);	
	int delHead();	      
	int delTail();	      
	bool isEmpty();		
};
