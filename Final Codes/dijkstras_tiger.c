#include <stdio.h>
#define INF 999
// shortest path algo from single source

void Dijkstras(int n, int source, int visited[20], int cost[20][20], int distance[20]);

int main()
{
    // inputs : n, source,cost[][], visited[], distance[]
    int n, source;
    int cost[20][20], visited[20], distance[20];

    printf("Enter no. of vertices :");
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

    printf("Enter source node :");
    scanf("%d", &source);

    Dijkstras(n, source, visited, cost, distance);

    for (int i = 1; i <= n; i++)
    {
        if (i != source)
        { // other than source
            printf("Shortest path from %d to %d is %d \n", source, i, distance[i]);
        }
    }

    return 0;
}

void Dijkstras(int n, int source, int visited[20], int cost[20][20], int distance[20])
{

    int min, u;

    // initialize
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        distance[i] = cost[source][i];
    }

    // after selecting source
    visited[source] = 1;
    distance[source] = 0;

    // process all other vertices
    for (int count = 1; count <= n; count++)
    {
        min = INF;
        u = -1;

        // find smallest distance for each vertex
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && distance[i] < min)
            {
                min = distance[i];
                u = i; // ye kya hai pata nahi //represents the vertex with the smallest distance
            }
        }

        if (u != -1)
        {

            visited[u] = 1;

            // update the dist of neighbouring node
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i] && cost[u][i] != INF && distance[u] + cost[u][i] < distance[i])
                {
                    distance[i] = distance[u] + cost[u][i];
                }
            }
        }
    }
}