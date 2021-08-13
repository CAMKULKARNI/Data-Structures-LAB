#include <stdio.h>
#include <stdlib.h>

// Node of the circular linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
// Handle of the list.
// Head points to the first node in the list.
// Tail points to the last node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int length;
} List;

// initializes a cirucular linked list
List *initialize_list();

// Creates a node and stores the data in it.
Node *create_node(int data);

// Inserts data at offset position pos. No operation is required if pos is out of range.
void position_insert(List *cll, int data, int pos);

// Deletes the node at position pos. No operation is required if pos is out of range.
void position_delete(List *cll, int pos);

// Print the data present in the safe node according to the josephus problem.
int josephus(List *cll, int k);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List *cll);

// Deallocates resources held by the list
void destroy_list(List *);
int main()
{

    List *cll = initialize_list();
    int ele, choice, pos, k, i = 0, input[] = {1,1,0,1,2,1,1,3,2,1,4,3,1,5,4,4,2,0,2,3,4,1,1,0,1,5,4,4,3,0,4,2,0,4,0};

    do
    {
        choice = input[i];
        i++;
        switch (choice)
        {
        // Insert at position;
        case 1:
            ele = input[i];
            i++;
            pos = input[i];
            i++;
            position_insert(cll, ele, pos);
            break;

        // Delete at position
        case 2:
            scanf("%d", &pos);
            position_delete(cll, pos);
            break;

        // Josephus problem
        case 3:
            scanf("%d", &k);
            ele = josephus(cll, k);
            printf("%d\n", ele);
            break;

        // Print entire list
        case 4:
            display(cll);
            break;
        }
    } while (choice != 0);

    destroy_list(cll);
    return 0;
}

List *initialize_list()
{
    List *cll = (List *)malloc(sizeof(List));
    cll->head = NULL;
    cll->tail = NULL;
    cll->length = 0;
    return cll;
}

Node *create_node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void display(List *cll)
{
    if (cll->length == 0)
        printf("EMPTY");
    else
    {
        Node *temp = cll->head;
        for (int i = 0; i < cll->length; i++)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void destroy_list(List *cll)
{
    Node *p = cll->head;
    Node *q = NULL;
    for (int i = 0; i < cll->length; i++)
    {
        q = p;
        p = p->next;
        free(q);
    }

    free(cll);
}

void position_insert(List *cll, int data, int pos)
{
    if (pos > cll->length)
    {
        return;
    }
    Node *ref = cll->head;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;

    if (pos == 0)
    {
        if (cll->length == 0)
        {
            temp->next = temp;
            cll->head = temp;
            cll->tail = temp;
        }
        else if (cll->length > 0)
        {
            temp->next = cll->head;
            cll->tail->next = temp;
            cll->head = temp;
        }
        (cll->length)++;
    }
    else if (pos == cll->length)
    {
        if (cll->length == 0)
        {
            temp->next = temp;
            cll->head = temp;
            cll->tail = temp;
        }
        else if (cll->length > 0)
        {
            temp->next = cll->head;
            cll->tail->next = temp;
            cll->tail = temp;
        }
        (cll->length)++;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            ref = ref->next;
        }
        temp->next = ref->next;
        ref->next = temp;
        (cll->length)++;
    }
}

void position_delete(List *cll, int pos)
{
    if (pos >= cll->length)
    {
        return;
    }
    Node *ref = cll->head;
    Node *temp = (Node *)malloc(sizeof(Node));

    if (pos == 0)
    {
        cll->tail = cll->head->next;
        temp = cll->head;
        cll->head = cll->head->next;
        free(temp);
        (cll->length)--;
    }
    else if (pos == (cll->length) - 1)
    {
        for (int i = 0; i < cll->length - 2; i++)
        {
            ref = ref->next;
        }
        temp = ref->next;
        ref->next = cll->head;
        cll->tail = ref;
        free(temp);
        (cll->length)--;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            ref = ref->next;
        }
        temp = ref->next;
        ref->next = temp->next;
        free(temp);
        (cll->length)--;
    }
}

int josephus(List *cll, int k)
{
    Node *ref = cll->head;
    for (int i = 0; i < k; i++)
    {
        ref = ref->next;
    }

    while (cll->length != 1)
    {
        if (ref->next == cll->tail)
        {
            ref = cll->head;
            position_delete(cll, cll->length - 1);
        }
        else if (ref->next == cll->head)
        {
            position_delete(cll, 0);
            ref = cll->head;
        }
        else
        {
            Node *temp = ref->next;
            ref->next = ref->next->next;
            ref = ref->next;
            free(temp);
            (cll->length)--;
        }
    }
    return (cll->head->data);
}
