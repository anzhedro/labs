//Сравнение и присваивание для стеков
#include <iostream> 
#include <vector> 
#include <stack> 
using namespace std;

int main()
{ 
	stack <int, vector<int> > S, T, U;
	S.push(10); 
	S.push(20); 
	S.push(30);
	cout << "Pushed into S: 10 20 30\n";
	T = S;
	cout << "After T = S; We have:" << endl;
	cout << (S == T ? "S == T" : "S != T") << endl;
	U.push(10); 
	U.push(21);
	cout << "Pushed onto U: 10 21\n";
	cout << "We now have ";
	cout << (S < U ? "S < U" : "S >= U") << endl;
	return 0; 
}