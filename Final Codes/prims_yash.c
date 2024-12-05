// Name:Mayur Hiware ... exp6(prims algo)

#include <stdio.h>
#include <stdlib.h>
// mst
void prims(int n, int cost[10][10]);

int main()
{
    int n, cost[10][10]; // n: number of nodes, cost: adjacency matrix

    printf("Enter total number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]); // i : source && j : destination
            if (cost[i][j] == 0 && i != j)
            {
                cost[i][j] = 999; // Replace 0 with a large value for non-diagonal entries
            }
        }
    }

    prims(n, cost);

    return 0;
}

void prims(int n, int cost[10][10])
{
    int visited[10] = {0};   // Array to track visited nodes
    int minCost = 0, ne = 1; // Total cost and edge counter(n-1)

    visited[1] = 1; // Start with the first node

    printf("\nThe edges considered for the MST are:\n");
    while (ne < n)
    {
        int min = 999, u = -1, v = -1; // curr source and destination //

        // Find the minimum-cost edge connecting visited and unvisited nodes
        for (int i = 1; i <= n; i++)
        {
            if (visited[i]) // starting vertex
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!visited[j] && cost[i][j] < min) // edge weight < min
                    {
                        min = cost[i][j];
                        u = i; // curr source
                        v = j; // curr dest
                    }
                }
            }
        }

        if (u != -1 && v != -1)
        {
            printf("%d edge (%d, %d) = %d\n", ne++, u, v, min);
            minCost += min;
            visited[v] = 1;                // Mark the new node as visited
            cost[u][v] = cost[v][u] = 999; // Mark the edge as used
        }
    }

    printf("\nMinimum Cost of constructing the MST is: %d\n", minCost);
}