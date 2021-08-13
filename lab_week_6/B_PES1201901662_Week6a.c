#include "6a.h"

static Node *create_Node(int data, Node *link)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = link;
    return temp;
}

void List_initialize(List *ptr_List)
{
    //TODO
    ptr_List->head = NULL;
    ptr_List->number_of_Nodes = -1;
}

void List_insert_front(List *ptr_List, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    if (ptr_List->head == NULL)
    {
        ptr_List->head = temp;
    }
    else
    {
        temp->link = ptr_List->head;
        ptr_List->head = temp;
    }
    (ptr_List->number_of_Nodes)++;
}

const int Node_get_data(Node *Node_ptr)
{
    return Node_ptr->data;
}

void List_delete_front(List *ptr_List)
{
    Node *temp = ptr_List->head;
    ptr_List->head = ptr_List->head->link;
    free(temp);
    (ptr_List->number_of_Nodes)--;
}

void List_destroy(List *ptr_List)
{
    Node *t = ptr_List->head, *u = NULL;
    while (t != NULL)
    {
        u = t;
        t = t->link;
        free(u);
    }
    free(ptr_List);
}

void stack_initialize(Stack *ptr_stack)
{
    ptr_stack->ptr_List = (List *)malloc(sizeof(List));
    List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
    List_insert_front(ptr_stack->ptr_List, key);
}

void stack_pop(Stack *ptr_stack)
{
    if (!stack_is_empty(ptr_stack))
    {
        List_delete_front(ptr_stack->ptr_List);
    }
}

int stack_is_empty(Stack *ptr_stack)
{
    if ((ptr_stack->ptr_List->head) != NULL)
    {
        return 0;
    }
}

const int stack_peek(Stack *ptr_stack)
{
    if (!stack_is_empty(ptr_stack))
    {
        return (ptr_stack->ptr_List->head->data);
    }
}

void stack_destroy(Stack *ptr_stack)
{
    List_destroy(ptr_stack->ptr_List);
    free(ptr_stack);
}

int postfix_eval(const char *expression)
{
    // TODO
    int i = 0;
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    stack_initialize(newStack);

    while (expression[i])
    {
        if (expression[i] <= 57 && expression[i] >= 48)
        {
            stack_push(newStack, expression[i] - '0');
        }
        else
        {
            int operand_1 = stack_peek(newStack);
            stack_pop(newStack);
            int operand_2 = stack_peek(newStack);
            stack_pop(newStack);
            switch (expression[i])
            {
            case 43:
                stack_push(newStack, operand_1 + operand_2);
                break;
            case 45:
                stack_push(newStack, -operand_1 + operand_2);
                break;
            case 47:
                stack_push(newStack, operand_2 / operand_1);
                break;
            case 42:
                stack_push(newStack, operand_1 * operand_2);
                break;
            case 37:
                stack_push(newStack, operand_2 % operand_1);
                break;
            }
        }
        i++;
    }

    return stack_peek(newStack);
}
