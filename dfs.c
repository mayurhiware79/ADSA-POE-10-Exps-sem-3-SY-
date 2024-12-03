#include <stdio.h>

#define MAX 20

void DFS(int graph[MAX][MAX], int node, int visited[MAX], int n);

int main()
{
    int n, graph[MAX][MAX], visited[MAX] = {0}, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &source);

    // Perform DFS
    DFS(graph, source, visited, n);

    // Check if all nodes are visited
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("Graph is not connected\n");
            return 0;
        }
    }
    printf("Graph is connected\n");
    return 0;
}

void DFS(int graph[MAX][MAX], int node, int visited[MAX], int n)
{
    visited[node] = 1; // Mark the current node as visited
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            DFS(graph, i, visited, n); // Recursively visit neighbors
        }
    }
}
