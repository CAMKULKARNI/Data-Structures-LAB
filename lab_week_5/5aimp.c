#include "5a.h"

static Node *create_Node(int data, Node *link)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = link;
}

void list_initialize(List *ptr_list)
{
    ptr_list->head = NULL;
    ptr_list->number_of_Nodes = -1;
}

void list_insert_front(List *ptr_list, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    if (ptr_list->head == NULL)
    {
        ptr_list->head = temp;
    }
    else
    {
        temp->link = ptr_list->head;
        ptr_list->head = temp;
    }
    (ptr_list->number_of_Nodes)++;
}

const int Node_get_data(Node *Node_ptr)
{
    return Node_ptr->data;
}

void list_delete_front(List *ptr_list)
{

    Node *temp = ptr_list->head;
    ptr_list->head = ptr_list->head->link;
    free(temp);
    (ptr_list->number_of_Nodes)--;
}

void list_destroy(List *ptr_list)
{
    Node *t = ptr_list->head, *u = NULL;
    while (t != NULL)
    {
        u = t;
        t = t->link;
        free(u);
    }
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack)
{
    ptr_Stack->ptr_list = (List *)malloc(sizeof(List));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key)
{
    list_insert_front(ptr_Stack->ptr_list, key);
}

void Stack_pop(Stack *ptr_Stack)
{
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack)
{
    if ((ptr_Stack->ptr_list->head) != NULL)
    {
        return 0;
    }
}

const int Stack_peek(Stack *ptr_Stack)
{
    return (ptr_Stack->ptr_list->head->data);
}

void Stack_destroy(Stack *ptr_Stack)
{
    list_destroy(ptr_Stack->ptr_list);
    free(ptr_Stack);
}

int match_parenthesis(const char *string)
{
    int i = 0;
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    Stack_initialize(newStack);

    while (string[i] != '\0')
    {
        switch (string[i])
        {
        case '(':
        case '{':
        case '[':
            Stack_push(newStack, string[i]);
            break;
        case ')':
            if (Stack_peek(newStack) == '(')
            {
                Stack_pop(newStack);
            }
            else
            {
                Stack_push(newStack, string[i]);
            }
            break;
        case '}':
            if (Stack_peek(newStack) == '{')
            {
                Stack_pop(newStack);
            }
            else
            {
                Stack_push(newStack, string[i]);
            }
            break;
        case ']':
            if (Stack_peek(newStack) == '[')
            {
                Stack_pop(newStack);
            }
            else
            {
                Stack_push(newStack, string[i]);
            }
            break;
        }
        i++;
    }

    if (newStack->ptr_list->number_of_Nodes == -1)
    {
        Stack_destroy(newStack);
        return 1;
    }
    else
    {
        Stack_destroy(newStack);
        return 0;
    }
}