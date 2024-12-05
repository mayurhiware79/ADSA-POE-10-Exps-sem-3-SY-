// Mayur 0/1 Knapsack

#include <stdio.h>
#define MAX 50

int weight[MAX], profit[MAX], n;

int knapsack(int i, int m);
int max(int a, int b);

int main()
{
    int m, optSol;

    printf("enter the number of object : \n");
    scanf("%d", &n);

    printf("Enter the profit : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }

    printf("Enter the weight : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("enter the knapsack capacity : \n");
    scanf("%d", &m);

    optSol = knapsack(1, m);
    printf("The optimal solution is : %d\n", optSol);

    return 0;
}

int knapsack(int i, int m)
{
    if (i == n)
    {
        return (weight[n] > m) ? 0 : profit[n];
    }

    if (weight[i] > m)
    {
        return knapsack(i + 1, m);
    }

    return max(knapsack(i + 1, m), knapsack(i + 1, m - weight[i]) + profit[i]);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}