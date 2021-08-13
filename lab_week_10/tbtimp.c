#include <stdio.h>
#include <stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    //Done
    tree = (Tree *)malloc(sizeof(tree));
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    //Done
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->leftThread = temp->rightThread = 1;

    if (tree->root == NULL)
    {
        tree->root = temp;
        return;
    }

    Node *ref = tree->root, *prev = tree->root;

    while (ref != NULL)
    {
        if (ref->data < data)
        {
            // right subtree insertion
            if (ref->right == prev || ref->right == tree->root || (ref->leftThread == 1 && ref->rightThread == 1))
            {
                prev = ref;
                ref = NULL;
                break;
            }
            prev = ref;
            ref = ref->right;
        }
        else
        {
            //left subtree insertion
            if (ref->left == prev || ref->left == tree->root || (ref->leftThread == 1 && ref->rightThread == 1))
            {
                prev = ref;
                ref = NULL;
                break;
            }
            prev = ref;
            ref = ref->left;
        }
    }

    if (prev->data < data)
    {
        //right subtree insertion
        temp->right = prev->right;
        temp->left = prev;
        prev->rightThread = 0;
        // prev->leftThread = 1;
        prev->right = temp;
    }
    else
    {
        //left subtree insertion
        temp->left = prev->left;
        temp->right = prev;
        // prev->rightThread = 1;
        prev->leftThread = 0;
        prev->left = temp;
    }
}

Node *inorder_predecessor(Node *ptr)
{
    //TODO
    if (ptr->leftThread == 1)
    {
        return ptr->left;
    }
    Node *temp = ptr->left;
    while (temp->rightThread != 1)
    {
        temp = temp->right;
    }
    return temp;
}

Node *inorder_successor(Node *ptr)
{
    //TODO
    if (ptr->rightThread == 1)
    {
        return ptr->right;
    }
    Node *temp = ptr->right;
    while (temp->leftThread != 1)
    {
        temp = temp->left;
    }
    return temp;
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
    Node *temp = tree->root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    while (temp != NULL)
    {
        printfun(temp->data);
        temp = inorder_successor(temp);
    }
    nextline();
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
    Node *temp = tree->root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    while (temp != NULL)
    {
        printfun(temp->data);
        temp = inorder_predecessor(temp);
    }
    nextline();
}

void destroy(Node *r)
{
    //TODO
    if (r == NULL)
    {
        return;
    }
    free(r->left);
    free(r);
    free(r->right);
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
