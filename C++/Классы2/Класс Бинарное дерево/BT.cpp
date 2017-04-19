#include "BT.h"
void BT::add(int key, node** tree)
{
	if (!(*tree))
	{
		*tree = (node*) malloc(sizeof(node));
		(*tree)->val = key;
		(*tree)->left = (*tree)->right = 0;
		return;
	}
	if (key <= (*tree)->val)
		add(key, &(*tree)->left);
	else
		add(key, &(*tree)->right);
}

void BT::print(node* tree)
{
	if (tree)
	{
		print(tree->left);
		cout << " " << tree->val;
		print(tree->right);
	}
}