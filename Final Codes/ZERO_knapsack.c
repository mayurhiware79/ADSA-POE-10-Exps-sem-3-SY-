#include <stdio.h>

// using recursion
int knapsack(int profit[], int weight[], int W, int n)
{
    // base case
    if (W == 0 || n == 0)
    {
        return 0;
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (weight[i] <= W)
        {
            // include
            int include = profit[i] + knapsack(profit, weight, W - weight[i], n - 1);
            // exclude
            int exclude = knapsack(profit, weight, W, n - 1);

            return (include > exclude) ? include : exclude;
        }
        else
        {
            // exclude
            return knapsack(profit, weight, W, n - 1);
        }
    }
}

int main()
{
    int profit[20] = {15, 5, 10, 15, 7, 40};
    int weight[20] = {2, 5, 6, 10, 6, 1, 2};
    int W = 20;
    int n = sizeof(profit) / sizeof(profit[0]);

    printf("%d", knapsack(profit, weight, W, n));

    return 0;
}