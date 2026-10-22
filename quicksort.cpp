
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivot = a[right];  // Rightmost pivot
        int i = left - 1;

        for (int j = left; j < right; j++)
        {
            if (a[j] >= pivot) // Descending order
            {
                i++;
                swap(&a[i], &a[j]);
            }
        }

        swap(&a[i + 1], &a[right]);
        int p = i + 1;

        quicksort(a, left, p - 1);
        quicksort(a, p + 1, right);
    }
}

int main()
{
    int a[] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
    int n = sizeof(a) / sizeof(a[0]);

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
