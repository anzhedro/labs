//ќчередь с приоритетами;   
//P.top() указывает на элемент, последн€€ цифра которого не больше
//последних цифр других элементов.
#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;
class CompareLastDigits   
{ 
public:
	bool operator()(int x, int y)
	{     
		return x % 10 > y % 10;
	}
};
int main()
{ 
	priority_queue <int, vector<int>, CompareLastDigits> P; 
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