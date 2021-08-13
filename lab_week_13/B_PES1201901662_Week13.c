#include <stdio.h>
#include "trie.h"

struct trienode *getnode()
{
    struct trienode *temp = (struct trienode *)malloc(sizeof(struct trienode));
    for (int i = 0; i < 26; i++)
    {
        temp->child[i] = NULL;
    }
    temp->endofword = 0;
    return temp;
}

void display(struct trienode *curr)
{
    for (int i = 0; i < 26; i++)
    {
        if (curr->child[i] != NULL)
        {
            word[length] = i + 97;
            length++;
            if (curr->child[i]->endofword == 1)
            {
                printnewline();
                for (int j = 0; j < length; j++)
                {
                    printfun(word[j]);
                }
            }
            display(curr->child[i]);
        }
    }
    length--;
    return;
}

void insert(struct trienode *root, char *key)
{
    struct trienode *ref = root;

    for (int i = 0; key[i] != '\0'; i++)
    {
        int index = key[i] - 97;
        if (ref->child[index] == NULL)
        {
            ref->child[index] = getnode();
        }
        ref = ref->child[index];
    }
    ref->endofword = 1;
    return;
}

int search(struct trienode *root, char *key)
{
    struct trienode *ref = root;

    for (int i = 0; key[i] != '\0'; i++)
    {
        int index = key[i] - 97;
        if (ref->child[index] == NULL)
        {
            return 0;
        }
        ref = ref->child[index];
    }
    if (ref->endofword == 1)
    {
        return 1;
    }
    return 0;
}

void delete_trie(struct trienode *root, char *key)
{
    int index, k;
    struct trienode *ref = root;
    struct stack x;
    for (int i = 0; key[i] != '\0'; i++)
    {
        index = key[i] - 97;
        if (ref->child[index] == NULL)
        {
            return;
        }
        push(ref, index);
        ref = ref->child[index];
    }
    ref->endofword = 0;
    push(ref, -1);

    while (1)
    {
        x = pop();
        if (x.index != -1)
        {
            x.m->child[x.index] = NULL;
        }
        if (x.m == root)
        {
            break;
        }
        k = check(x.m);
        if ((k >= 1) || (x.m->endofword == 1))
        {
            break;
        }
        else
        {
            free(x.m);
        }
    }
    return;
}

int check(struct trienode *x)
{
    int counter = 0;
    for (int i = 0; i < 255; i++)
    {
        if (x->child[i] != NULL)
        {
            counter++;
        }
    }
    return counter;
}

void push(struct trienode *x, int k)
{
    //TODO
    top++;
    s[top].m = x;
    s[top].index = k;
}

struct stack pop()
{
    //TODO
    struct stack temp;
    temp = s[top--];
    return temp;
}
