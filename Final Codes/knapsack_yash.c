#include <stdio.h>
int p[50];
int w[50];
int n;
int knapsack(int i, int m);

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int m, i, sol;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the weights: \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    printf("\nenter the profits:\n ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter capacity of knapsack:");
    scanf("%d", &m);

    sol = knapsack(1, m);
    printf("The optimal solution is : %d ", sol);
    return 0;
}
int knapsack(int i, int m)
{
    // base condition
    if (i > n)
    {
        return 0;
    }
    // for current weight
    if (w[i] > m)
    {
        return knapsack(i + 1, m);
    }
    // what to include and what not
    return max(knapsack(i + 1, m), knapsack(i + 1, m - w[i]) + p[i]);
}