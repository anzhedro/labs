//Использование очереди;  
//демонстрация функции-члены push, pop, back и front.
#include <iostream> 
#include <list> 
#include <queue>
using namespace  std;
int main()

{ 
	queue <int, list<int> > Q;
	Q.push(10); 
	Q.push(20); 
	Q.push(30); 
	cout << "After pushing 10, 20 and 30:\n"; 
	cout << "Q.front() = " << Q.front() << endl; 
	cout << "Q.back()  = " << Q.back() << endl; 
	Q.pop();
	cout << "After Q.pop():\n";
	cout << "Q.front() = " << Q.front() << endl; 
	return 0; 
}