#include "et.h"

Node *createExpressionTree(char *a, int len)
{
    //TODO
    Node *stk[len];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (a[i] == 42 || a[i] == 43 || a[i] == 45 || a[i] == 47 || a[i] == 94 || a[i] == 36)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = a[i];
            temp->right = stk[top];
            top--;
            temp->left = stk[top];
            top--;
            temp->prev = NULL;
            top++;
            stk[top] = temp;
        }
        else
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = a[i];
            temp->left = NULL;
            temp->right = NULL;
            temp->prev = NULL;
            top++;
            stk[top] = temp;
        }
    }
    return stk[top];
}

void inorder(Node *root)
{
    //TODO
    // Note : Do not change the printf
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    //TODO
    // Note : Do not change the printf
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    //TODO
    // Note : Do not change the printf
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

void freeTree(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
}
