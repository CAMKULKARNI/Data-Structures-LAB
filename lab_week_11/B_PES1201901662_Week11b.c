#include <stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
    //TODO
    int *visited = (int *)calloc(n, sizeof(int)), *queue = (int *)calloc(n, sizeof(int)), num_terms = 0;
    queue[0] = v; //enqueue(queue, v);
    num_terms++;
    while (num_terms)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[queue[0]][i] == 1 && visited[i] == 0)
            {
                queue[num_terms] = i;
                num_terms++;
            }
        }
        visited[queue[0]] = 1;
        //queue_dequeue(queue);
        for (int i = 0; i < n - 1; i++)
        {
            queue[i] = queue[i + 1];
        }
        num_terms--;
    }
    if (visited[v] == 1 && visited[u] == 1)
    {
        return 1;
    }
    return 0;
}
