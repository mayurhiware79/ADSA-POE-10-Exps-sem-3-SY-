// FILE WHICH IMPLEMENTS DFS TRAVERSAL FOR GRAPH

#include <stdio.h>

void DFS(int n, int graph[20][20], int visited[20], int source)
{
    visited[source] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[source][i] == 1 && !visited[i])
        {
            DFS(n, graph, visited, i);
        }
    }
}

int main()
{
    int num;
    int graph[20][20], visited[20] = {0}, source;

    printf("enter the number of vertices :");
    scanf("%d", &num);

    printf("Enter adjacency matrix : \n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("enter the source :");
    scanf("%d", &source);

    DFS(num, graph, visited, source);

    for (int i = 0; i < num; i++)
    {
        if (!visited[i])
        {
            printf("not connected");
            break;
        }
    }
    printf(" connected");
}
