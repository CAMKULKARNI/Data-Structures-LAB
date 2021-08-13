#include "poly.h"
#include <math.h>

void insert_at_end(List *list, int data)
{
    Node *ref = list->head, *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    if (ref == NULL)
    {
        list->head = temp;
        list->number_of_nodes++;
    }
    else
    {
        while ((ref->link) != NULL)
        {
            ref = ref->link;
        }
        ref->link = temp;
        list->number_of_nodes++;
    }
}

long long int evaluate(List *list, int x)
{
    Node *ref = list->head;
    double sum = 0;

    for (int i = 0; ref != NULL; ref = ref->link, i++)
    {
        sum += ((ref->data) * pow(x, i));
    }

    return sum;
}
