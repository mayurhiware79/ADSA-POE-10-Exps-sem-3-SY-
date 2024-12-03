#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;
    int j = low;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quicksort(int arr[], int low, int high)
{

    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int main()
{
    int arr[] = {4, 1, 5, 2, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("array before :\n");
    for (int i = 0; i < size; i++)
    {
        printf("\n%d", arr[i]);
    }

    quicksort(arr, 0, size - 1);
    printf("array after :\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}