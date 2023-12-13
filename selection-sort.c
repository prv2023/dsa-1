#include<stdio.h>

void swap(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selectionSort(int a[], int n, int i)
{
    if (i >= n - 1)
        return;

    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (a[j] < a[min])
        {
            min = j;
        }
    }

    if (min != i)
    {
        swap(a, i, min);
    }

    selectionSort(a, n, i + 1);
}

int main(int argc, char const *argv[])
{
    int a[50], n, i;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter Elements of array:");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter value:");
        scanf("%d", &a[i]);
    }

    printf("BEFORE SORTING :");
    for (i = 0; i < n; i++)
    {
        printf("\n %d", a[i]);
    }

    selectionSort(a, n, 0);

    printf("\nAFTER SORTING :");
    for (i = 0; i < n; i++)
    {
        printf("\n %d", a[i]);
    }

    return 0;
}
