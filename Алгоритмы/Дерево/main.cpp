//#include <iostream>
//#include <fstream>
//#include <stack>
//using namespace std;
//
//struct node
//{
//public:
//	int val;
//	node* right;
//	node* left;
//};
//ofstream out("output.txt");
//int i =0, j = 0;
//
//void postorder(node* tree)
//{
//	if (tree)
//	{
//		postorder(tree->left);
//		postorder(tree->right);
//		i++;
//		if (i == 1)
//		{
//			out << tree->val;
//		}
//		else
//			out << " " << tree->val;
//
//	}
//}
//
//void inorder(node* tree)
//{
//	if (tree)
//	{
//		inorder(tree->left);
//		j++;
//		if (j == 1)
//		{
//			out << tree->val;
//		}
//		else
//			out << " " << tree->val;
//		inorder(tree->right);
//	}
//}
//
//int main()
//{
//	int  num, n;
//
//	ifstream in("input.txt");
//
//	in >> n;
//	in >> num;
//
//	node* key = new node();
//	node* root = new node();
//	key = root;
//	key->val = num;
//	key->left = key->right = 0;
//
//	stack<node*> a;
//	a.push(root);
//
//	for (int i = 1; i < n; ++i)
//	{
//		in >> num;
//		if (num < a.top()->val)
//		{
//			node* tree = new node();
//			key->left =	tree;
//			tree->val = num;
//			tree->left = tree->right = 0;
//			a.push(tree);
//			key = tree;
//		}
//		else
//		{
//			while (!a.empty() && num >= a.top()->val)
//			{ 
//				key = a.top();
//				a.pop();
//			}
//			node* tree = new node();
//			key->right = tree;
//			tree->val = num;
//			tree->left = tree->right = 0;
//			a.push(tree);
//			key = tree;
//		}
//	}
//
//	in.close();
//
//	postorder(root);
//	out << "\n";
//
//	inorder(root);
//
//	out.close();
//
//	return 0;
//}
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
struct Node
{
	int value;
	int height;
	int sub;
	int empty;
	Node* left;
	Node* right;
};
Node* ROOT = NULL;
int k = 1;

void add(Node *&n, int _value)
{
	if(n == NULL)
	{
		n = new Node;
		n->left = NULL;
		n->right = NULL;
		n->value = _value;
		n->height = 0;
		n->sub = -1;
		return;
	}
	if(_value > n->value)
	{
		if(n->right != NULL)
			add(n->right, _value);
		else
		{
			n->right = new Node;
			n->right->right = n->right->left =NULL;
			n->right->value = _value;
		}
	}
	if(_value < n->value)
	{
		if(n->left != NULL)
			add(n->left, _value);
		else
		{
			n->left = new Node;
			n->left->left = n->left->right =NULL;
			n->left->value = _value;
		}
	}
}
ofstream out("output.txt");
int i = 0;
void preview(Node* n, int* _mass)
{
	if(n == NULL)
		return;
	_mass[i] = n->value;
	i++;
	preview(n->left, _mass);
	preview(n->right, _mass);
}
void view(int* __mass, int _nn)
{
	for(int i = 0; i < _nn; i++)
	{	
		if(i != _nn - 1)
			out << __mass[i] << endl;
		else
			out << __mass[i];
	}
	return;
}
int MAX(int x, int y)
{
	if(x >= y)
		return x;
	if(y >= x)
		return y;
}
int metka = 0;
void height(Node* n)
{
	if(n == NULL)
		return;
	if(n->left != NULL)
	{
		height(n->left);
	}
	if(n->right != NULL)
	{
		height(n->right);
	}
	if(n->left == NULL && n->right == NULL)
	{
		n->height = 0;
		n->sub = 0;
	}
	if(n->right != NULL && n->left == NULL)
	{
		n->height = n->right->height + 1;
		int raznost = n->right->height - (-1);
		if(raznost == 2)
		{
			n->sub = 1;
			metka++;
		}
		else
			n->sub = 0;
	}
	if(n->right == NULL && n->left != NULL)
	{
		n->height = n->left->height + 1;
		int raznost = n->left->height - (-1);
		if(raznost == 2)
		{n->sub = 1;metka++;}
		else
			n->sub = 0;

	}
	if(n->right != NULL && n->left != NULL)
	{
		int flagR = n->right->height;
		int flagL = n->left->height;
		int raznost;
		n->height = MAX(flagR, flagL) + 1;
		if(n->right->height > n->left->height)
		{	
			raznost = n->right->height - n->left->height;
			if(raznost == 2)
			{n->sub = 1; metka++;}
			else
				n->sub = 0;
		}
		if(n->right->height < n->left->height)
		{	
			int raznost = n->left->height - n->right->height;
			if(raznost == 2)
			{n->sub = 1;metka++;}
			else
				n->sub = 0;
		}
		if(n->right->height == n->left->height)
		{	
			int raznost = n->left->height - n->right->height;
			if(raznost == 2)
			{n->sub = 1;metka++;}
			else
				n->sub = 0;
		}

	}

}
int flag = 0;
int flag_remove = 0;
void removal(Node* n)
{
	Node* temp = n;
	if(n->right == NULL && n->left == NULL)
		n = NULL;
	if (temp->left != NULL)
	{
		temp = temp->left;
		Node* y = temp;
		if(temp->right == NULL)
		{
			n->value = temp->value;
			if (temp->left != NULL)
			{
				n->left = temp->left;
			}
			else
				n->left == NULL;
		}
		else
		{
			while (temp->right != NULL)
				temp = temp->right;
			n->value = temp->value;
			while(y->right != temp)
				y = y->right;
			y->right = temp->left;
		}
	}
	else
	{
		if(n == ROOT)
			ROOT = ROOT->right;
		else
		{
			Node* y = n;
			n->value = temp->right->value;
			if(temp->right->left != NULL)
				n->left = temp->right->left;
			else 
				n->left = NULL;
			while(y->right != NULL)
			{
				y = y->right;
				flag_remove++;
			}
			if(flag_remove != 1)
				n->right = y;
			else
				if(y->right != NULL)
				{
					n->right = y;
					n->left = y->left;
				}
				else
					n->right = NULL;
		}
	}
}
void obhod_dlya_ydaleniya(Node* n, int _metka)
{
	if(n == NULL || _metka % 2 == 0)
		return;
	obhod_dlya_ydaleniya(n->left, _metka);
	if(n->sub == 1)
	{
		flag++;
		if(flag == (_metka + 1) / 2)
			removal(n);
	}
	obhod_dlya_ydaleniya(n->right, _metka);
}
int main()
{
	metka = 0;
	int* mass;
	int* in_mass;
	int count = 0;
	ifstream in("input.txt");
	int b = -9999999;
	while(!in.eof())
	{
		int a;
		in >> a;
		if(a != b)
		{
			count++;
		}
		else
			continue;
	}
	in.close();
	in_mass = new int[count];
	int flag_size = 0;
	in.open("tst.in");
	while(!in.eof())
	{
		int g = 1;
		int a;
		in >> a;
		for(int i = 0; i < count; i++)
		{
			if(a != in_mass[i])
			{
				g++;
			}
		}
		if(g == count + 1)
		{
			in_mass[flag_size] = a;
			flag_size++;
		}
	}
	for(int i = 0; i < flag_size; i++)
		add(ROOT,in_mass[i]);
	height(ROOT);
	obhod_dlya_ydaleniya(ROOT, metka);
	
	if(metka % 2 != NULL)
		flag_size--;

	mass = new int[flag_size];
	preview(ROOT, *&mass);
	view(*&mass, flag_size);
	return 0;
}