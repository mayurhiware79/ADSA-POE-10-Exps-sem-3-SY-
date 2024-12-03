#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity);

int main()
{
    int num;
    float weight[20], profit[20], capacity, ratio[20], temp;

    printf("\nEnter the number of objects: ");
    scanf("%d", &num);
    printf("\nEnter weights and profits: ");
    for (int i = 0; i < num; i++)
        scanf("%f %f", &weight[i], &profit[i]);
    printf("\nEnter knapsack capacity: ");
    scanf("%f", &capacity);

    for (int i = 0; i < num; i++)
        ratio[i] = profit[i] / weight[i];

    // Sorting by ratio
    for (int i = 0; i < num - 1; i++)
        for (int j = i + 1; j < num; j++)
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }

    knapsack(num, weight, profit, capacity);
    return 0;
}

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20] = {0}, tp = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            x[i] = 1.0;
            tp += profit[i];
            capacity -= weight[i];
        }
        else
        {
            x[i] = capacity / weight[i];
            tp += x[i] * profit[i];
            break;
        }
    }
    printf("\nResult vector: ");
    for (int i = 0; i < n; i++)
        printf("%f\t", x[i]);
    printf("\nMaximum profit: %f", tp);
}
