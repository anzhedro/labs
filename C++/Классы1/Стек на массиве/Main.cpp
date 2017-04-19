#include <iostream>
#include "Stack.h"
using std::cin;
using std::cout;
int main()
{
	int size;
	cin >> size;
	ArrayStack st(size);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << st.peek() << "\n";
	st.pop();
	if (st.IsEmpty()) cout << "Empty" << "\n";
	ArrayStack ss(st);                                      ///////
	cout << st.peek() << "\n";
	st.pop();
	if (st.IsEmpty()) cout << "Empty" << "\n";
	cout << st.peek() << "\n";
	st.pop();
	if (st.IsEmpty()) cout << "Empty" << "\n";
	cout << st.peek() << "\n";
	st.pop();
	if (st.IsEmpty()) cout << "Empty" << "\n";
	cout << "\n";
	if (ss.IsEmpty()) cout << "Empty" << "\n";
	cout << ss.peek() << "\n";
	ss.pop();
	cout << ss.peek() << "\n";
	ss.pop();
}
