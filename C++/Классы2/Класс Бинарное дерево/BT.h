#include <iostream>
using namespace std;
struct node
{
	int val;
	node* right;
	node* left;
};
node* root;
class BT
{
public:
	void add(int key, node** tree);
	void print(node* tree);
};