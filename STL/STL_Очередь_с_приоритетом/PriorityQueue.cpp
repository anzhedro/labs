//Очередь с приоритетами;  
//программа демонстрирует функции-члены push, pop, empty и top.
#include <iostream> 
#include <vector> 
#include <functional> 
#include <queue>
using namespace  std;
int main()
{ 
	priority_queue <int, vector<int>, less<int> > P;
	int x;
	P.push(123);
	P.push(51); 
	P.push(1000);
	P.push(17);
	while (!P.empty())
	{ 
		x = P.top();
		cout << "Retrieved element: " << x << endl;
		P.pop(); 
	}
	return 0; 
}