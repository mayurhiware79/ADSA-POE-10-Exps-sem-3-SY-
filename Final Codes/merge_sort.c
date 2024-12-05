#include <stdio.h>
// merge sort

void merge(int arr[], int mid, int si, int ei)
{

    int temp[ei - si + 1];
    int i = si;
    int j = mid + 1;
    int k = 0;

    // sorting while merging
    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // remaining in left arr
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= ei)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    // transfer data from temp to arr

    for (int i = si, k = 0; k < sizeof(temp) / sizeof(temp[0]); k++)
    {
        arr[i] = temp[k];
        i++;
    }
}

void merge_sort(int arr[], int si, int ei)
{

    if (si < ei)
    {
        int mid = si + (ei - si) / 2;

        merge_sort(arr, si, mid);
        merge_sort(arr, mid + 1, ei);
        merge(arr, mid, si, ei);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{

    // last element as pivot
    int pivot = arr[high];

    // set i to -1
    int i = low - 1;
    int j = low;

    // start comparing in array
    // no use of extra space
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;                    // MISTAKE
            swap(&arr[i], &arr[j]); // chage in arr[i] && arr[j]--> -1 & 0
                                    // increment i NOT HERE
        }
    }

    // set pivot's position
    // MISTAKE ARR[I + 1]
    swap(&arr[i + 1], &arr[high]);

    return i + 1; // return i
}

void quick_sort(int arr[], int low, int high)
{

    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main()
{

    int arr[] = {2, 5, 6, 3, 4, 1};
    int size = 6;

    // printarr
    printf("array before :");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    // merge_sort(arr, size, 0, size - 1);
    merge_sort(arr, 0, size - 1);

    printf("\narray after :");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 1;
}