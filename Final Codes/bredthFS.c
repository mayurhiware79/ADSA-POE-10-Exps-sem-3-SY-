// FILE WHICH IMPLEMENTS BFS TRAVERSAL FOR GRAPH

#include <stdio.h>

void BFS(int n, int graph[20][20], int visited[20], int source)
{
    int queue[20];
    int front = 0;
    int rear = 0;
    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear)
    {
        int current = queue[front++];
        printf("visited :%d \n", current);
        for (int i = 0; i < n; i++)
        {

            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
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

    BFS(num, graph, visited, source);

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
