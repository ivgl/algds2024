#include "treap.h"

// Операция разделения 2 деревьев, делал по алгоритму (псевдокоду)
void split(TreapNode *root, TreapNode **left, TreapNode **right, int key)
{
	if (root == NULL)
	{
		*left = NULL;
		*right = NULL;
		return;
	}
	if (key < root->key)
	{
		*right = root;
		split(root->left, left, &(root->left), key);
	}
	else
	{
		*left = root;
		split(root->right, &(root->right), right, key);
	}
}

// Операция слияния 2 деревьев, делал также по псевдокоду
TreapNode *merge(TreapNode *left, TreapNode *right)
{
	if (left == NULL)
		return right;
	if (right == NULL)
		return left;

	if (left->priority > right->priority)
	{
		left->right = merge(left->right, right);
		return left;
	}
	else
	{
		right->left = merge(left, right->left);
		return right;
	}
}

TreapNode *CreateTreapNode(int key, int priority)
{
	TreapNode *newnode = (TreapNode *)malloc(sizeof(TreapNode));
	newnode->key = key;
	newnode->priority = priority;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

TreapNode *insert(TreapNode *root, int key, int priority)
{
	TreapNode *new_node = CreateTreapNode(key, priority);

	if (root == NULL)
		return new_node;

	if (priority > root->priority)
	{
		split(root, &new_node->left, &new_node->right, key);
		return new_node;
	}
	else if (root->key <= key)
		root->right = insert(root->right, key, priority);
	else
		root->left = insert(root->left, key, priority);
	return root;
}