#include "cll.h"
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
