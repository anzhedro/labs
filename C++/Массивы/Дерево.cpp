#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	node* right;
	node* left;
};
node* root;

void add(int key, node** tree)
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

void print(node* tree)
{
	if (tree)
	{
		print(tree->left);
		printf("%d ", tree->val);
		print(tree->right);
	}
}

int main()
{
	int  *a, n;
	node s;
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		add(a[i], &root);
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	free(a);
	print(root);
	return 0;
}