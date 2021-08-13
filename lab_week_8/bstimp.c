#include <stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
	tree = (Tree *)malloc(sizeof(Tree));
}

void tree_insert(Tree *tree, int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	if (tree->root == NULL)
	{
		tree->root = temp;
		return;
	}
	else
	{
		Node *root = tree->root;

		while (root->data != data)
		{
			if (root->data > data)
			{
				if (root->left == NULL)
				{
					root->left = temp;
				}
				else
				{
					root = root->left;
				}
			}
			else if (root->data < data)
			{
				if (root->right == NULL)
				{
					root->right = temp;
				}
				else
				{
					root = root->right;
				}
			}
		}
	}
}
void tree_delete(Tree *tree, int element)
{
	// TODO : Delete elements from BST
	Node *temp = tree->root, *prev = tree->root;

	while (temp->data != element)
	{
		if (element < temp->data)
		{
			prev = temp;
			temp = temp->left;
		}
		else
		{
			prev = temp;
			temp = temp->right;
		}
	}

	if (temp == NULL)
	{
		return;
	}

	if (temp->right == NULL && temp->left == NULL)
	{
		if (prev->right == temp)
		{
			prev->right = NULL;
		}
		else
		{
			prev->left = NULL;
		}
		free(temp);
	}
	else if (temp->right != NULL && temp->left == NULL)
	{
		if (prev->right == temp)
		{
			prev->right = temp->right;
		}
		else
		{
			prev->left = temp->right;
		}
		free(temp);
	}
	else if (temp->right == NULL && temp->left != NULL)
	{
		if (prev->right == temp)
		{
			prev->right = temp->left;
		}
		else
		{
			prev->left = temp->left;
		}
		free(temp);
	}
	else if (temp->left != NULL && temp->right != NULL)
	{
		Node *to_replace = temp->right, *prev_to_replace = temp; //to_replace = inorder successor initially and the prev_to_replace = node itself
		while (to_replace->left != NULL)
		{
			prev_to_replace = to_replace;
			to_replace = to_replace->left;
		}
		temp->data = to_replace->data;

		if (prev_to_replace->left == to_replace)
		{
			prev_to_replace->left = to_replace->right;
		}
		else
		{
			prev_to_replace->right = to_replace->right;
		}
		free(to_replace);
	}
}

void tree_inorder(Node *r)
{
	if (r == NULL)
	{
		return;
	}
	tree_inorder(r->left);
	printf("%d ", r->data);
	tree_inorder(r->right);
}

void tree_preorder(Node *r)
{
	if (r == NULL)
	{
		return;
	}
	printf("%d ", r->data);
	tree_preorder(r->left);
	tree_preorder(r->right);
}

void tree_postorder(Node *r)
{

	if (r == NULL)
	{
		return;
	}
	tree_postorder(r->left);
	tree_postorder(r->right);
	printf("%d ", r->data);
}

void postorder(Tree *t)
{
	tree_postorder(t->root);
}

void preorder(Tree *t)
{
	tree_preorder(t->root);
}

void inorder(Tree *t)
{
	tree_inorder(t->root);
}

void destroy(Node *r)
{
	free(r);
}

void tree_destroy(Tree *t)
{
	Node *temp = t->root;
	if (temp->left == NULL && temp->right == NULL)
	{
		destroy(temp);
	}
	else
	{
		Tree *tempTree = (Tree *)malloc(sizeof(Tree));
		tempTree->root = temp->left;
		tree_destroy(tempTree);
		tempTree->root = temp->right;
		tree_destroy(tempTree);
	}
}
