#include "dll.h"
int count_nodes(List *dll)
{
    Node *ref = dll->head;
    int count = 0;

    if (ref == NULL)
    {
        return count;
    }

    while ((ref != NULL) && ((ref->next) != NULL))
    {
        count++;
        ref = ref->next;
    }

    return count + 1;
}

void insert_front(List *dll, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (dll->head == NULL)
    {
        dll->head = temp;
    }
    else
    {
        temp->next = dll->head;
        temp->prev = NULL;
        dll->head = temp;
    }
    dll->number_of_nodes++;
}

void dllist_delete_beginning(List *list)
{
    Node *temp = list->head;

    if (list->head == NULL)
    {
        return;
    }
    else
    {
        list->head = temp->next;
        (list->head)->prev = NULL;
        free(temp);
        list->number_of_nodes--;
    }
}

void position_delete(List *dll, int pos)
{
    if (pos == 0)
    {
        /* delete start */
        dllist_delete_beginning(dll);
    }
    else if (pos == (dll->number_of_nodes) - 1)
    {
        /* delete end*/
        Node *temp = dll->head;

        if (dll->head == NULL)
        {
            return;
        }
        else
        {
            while ((temp != NULL) && ((temp->next) != NULL) && ((temp->next->next) != NULL))
            {
                temp = temp->next;
            }
        }
        free(temp->next);
        temp->next = NULL;
        dll->number_of_nodes--;
    }
    else if (pos > 0 && pos < dll->number_of_nodes)
    {
        /* delete at pos */
        Node *ref = dll->head, *temp = (Node *)malloc(sizeof(Node));

        for (int i = 0; i < pos - 1; i++)
        {
            ref = ref->next;
        }

        temp = ref->next;
        ref->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        dll->number_of_nodes--;
    }
}

int search_list(List *dll, int key)
{
    Node *temp = dll->head;
    int i = 0;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return i;
        }
        i++;
        temp = temp->next;
    }

    return -1;
}

void reverse_list(List *dll)
{
    while ((dll->head)->next != NULL)
    {
        Node *temp = dll->head, *refer = temp->prev;
        temp->prev = (dll->head)->next;
        (dll->head) = (dll->head)->next;
        temp->next = refer;
    }
    (dll->head)->next = (dll->head)->prev;
    (dll->head)->prev = NULL;
}
