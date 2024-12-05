// edge based pn sameach aahe broo..😎
#include <stdio.h>

int parent[20];
void kruskal(int n, int cost[20][20]);
int find(int i);
int uni(int i, int j);

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
    kruskal(n, cost);

    return 0;
}

void kruskal(int n, int cost[20][20])
{

    int visited[20] = {0};
    int minCost = 0, ne = 1; // total cost and curr edge count

    // visited[1] = 1;

    printf("the edges considered for the mst are :\n");

    while (ne < n)
    {
        int min = 999, u = -1, v = -1;

        for (int i = 1; i <= n; i++)
        {
            // if (visited[i])
            // {
            for (int j = 1; j <= n; j++)
            {
                if (/*!visited[j] && */ cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
            // }
        }

        int root1 = find(u);
        int root2 = find(v);

        if (uni(root1, root2))
        {
            printf("%d. edge(%d, %d) = %d\n", ne++, u, v, min);
            minCost += min;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("the minimum cost of the constructing to MST : %d\n", minCost);
}

int find(int i)
{
    while (parent[i])
    {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
