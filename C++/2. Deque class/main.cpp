#include "deque.h"
#include <iostream>
using std::cout;
int main()
{
	Deque deq;
	deq.insHead(95);
	deq.insTail(5);
	deq.insTail(58);
	deq.insHead(66);
	cout << deq.delHead();
	cout << deq.delTail();
	cout << deq.delTail();
	
	if (deq.isEmpty()) 
		cout << "\nEmpty\n"; 
	else 
		cout << "\nNo Empty\n";
	deq.~Deque();
	return 0;
}