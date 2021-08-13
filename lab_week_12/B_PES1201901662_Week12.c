#include "hash.h"
HashTable *create_table(int size)
{
    //TODO
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->table = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        ht->table[i] = -1;
    }
    ht->size = size;
    return ht;
}

void insert(HashTable *htable, int element)
{
    //TODO
    int count = 0;
    for (int i = 0; i < htable->size; i++)
    {
        if (htable->table[i] != -1)
        {
            count++;
        }
    }

    if (count == htable->size)
    {
        return;
    }

    int index = element % htable->size; //hash function

    if (htable->table[index] == -1 || htable->table[index] == element)
    {
        htable->table[index] = element;
        return;
    }

    int offset = 1;
    while (htable->table[(element + offset) % htable->size] != -1 && htable->table[(element + offset) % htable->size] != element)
    {
        offset++;
    }

    index = (element + offset) % htable->size;
    htable->table[index] = element;
    return;
}

int search(HashTable *htable, int element)
{
    //TODO
    int index = element % htable->size; //hash function

    if (htable->table[index] == -1)
    {
        return 0;
    }

    int offset = 1;
    while (htable->table[(element + offset) % htable->size] != element)
    {
        offset++;
        if (offset == htable->size + 1)
        {
            return 0;
        }
    }
    return 1;
}

void delete (HashTable *htable, int element)
{
    //TODO
    int index = element % htable->size;

    if (htable->table[index] == element)
    {
        htable->table[index] = -1;
        return;
    }

    int offset = 1;
    while (htable->table[(element + offset) % htable->size] != element)
    {
        offset++;
        if (offset == htable->size + 1)
        {
            return;
        }
    }
    htable->table[(element + offset) % htable->size] = -1;
    return;
}

void destroy_table(HashTable *htable)
{
    //TODO
    free(htable->table);
    free(htable);
}
