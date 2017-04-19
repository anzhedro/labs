class List		
{
	struct node			
	{
		int  item;	
		struct  node*  next; 
	};
	struct node *head, *tail;
public:
	List();			
	List(const List& d);
	~List();		
	void insTail(int n);	
	int delTail();	      
	bool isEmpty();		
};
