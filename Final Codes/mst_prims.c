// vertex based
// minimum spanning tree from graph
#include <stdio.h>

void prims(int n, int cost[20][20])
{
    int visited[20] = {0};
    int minCost = 0, ne = 1; // total cost and curr edge count

    visited[1] = 1;

    printf("the edges considered for the mst are :\n");

    while (ne < n)
    {
        int min = 999, u = -1, v = -1;

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
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

int main()
{
    int n, cost[20][20]; // no. of nodes & adj matrix

    n = 4;
    printf("Enter the cosst matrix :\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
            {
                cost[i][j] = 999;
            }
        }
    }

    // will print - shortest path bet nodes min
    // will print - total mincost
    prims(n, cost);

    return 0;
}
