#include <stdio.h>
#define INF 999

// implementing single source shortest path in graph using dijkstra's algo
void Dijkstra(int n, int source, int visited[20], int distance[20], int cost[20][20]);

int main()
{
    int n, source, visited[20], distance[20], cost[20][20];

    printf("enter the total no. of vertices : ");
    scanf("%d", &n);

    printf("enter the cost adjacency matrix : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
            {
                cost[i][j] = INF;
            }
        }
    }

    printf("enter the source node : ");
    scanf("%d", &source);

    Dijkstra(n, source, visited, distance, cost);

    for (int i = 1; i <= n; i++)
    {
        if (i != source)
        {
            printf("shortest path from %d to %d is %d\n", source, i, distance[i]);
        }
    }

    return 0;
}

void Dijkstra(int n, int source, int visited[], int distance[], int cost[20][20])
{

    int min, u;

    // initializing
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        distance[i] = cost[source][i];
    }

    // starting conditions
    visited[source] = 1;
    distance[source] = 0;

    // now for all other vertices
    for (int j = 1; j <= n; j++)
    {
        min = INF;
        u = -1;

        // Find the unvisited node with the smallest distance
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && distance[i] < min)
            {
                min = distance[i];
                u = i; // mistake
            }
        }

        // loop madhee
        if (u != -1)
        {
            visited[u] = 1;

            for (int i = 1; i <= n; i++)
            {
                if (distance[u] + cost[u][i] < distance[i] && !visited[i] && cost[u][i] != INF)
                {
                    distance[i] = distance[u] + cost[u][i];
                }
            }
        }
    }
}
