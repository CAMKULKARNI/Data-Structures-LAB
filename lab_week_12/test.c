#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *table;
    int size;
} HashTable;

HashTable *create_table(int size);
void insert(HashTable *htable, int element);
int search(HashTable *htable, int element);
void display_table(HashTable *htable);

int main()
{
    int choice, loop = 0, input[] = {1, 0, 1, 1, 1, 3, 1, 8, 3, 0, 3, 1, 3, -1, 3, 3, 3, 8}, element, find;
    HashTable *htable = create_table(5);
    while (input[loop])
    {
        choice = input[loop];
        loop++;
        switch (choice)
        {
        case 1:
            // Insert element
            element = input[loop];
            loop++;
            insert(htable, element);
            break;

        case 3:
            // Search element
            element = input[loop];
            loop++;
            find = search(htable, element);
            if (find)
                printf("YES\n");
            else
                printf("NO\n");
            break;

        case 4:
            // Print all elements in the hash table
            display_table(htable);
            break;
        }
    }
}

void display_table(HashTable *htable)
{
    for (int i = 0; i < htable->size; i++)
        printf("%d ", htable->table[i]);
    printf("\n");
}

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

    if (htable->table[index] == -1)
    {
        htable->table[index] = element;
        return;
    }

    int offset = 1;
    while (htable->table[(element + offset) % htable->size] != -1)
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