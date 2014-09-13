#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 100

void print(int *arr, int n)
{
        int i;
        for (i = 0; i < n; ++i)
                printf("%d ", arr[i]);
        printf("\n");
}

inline int compare(const void *a, const void *b)
{
        return (*(int*) a - *(int*) b);
}

int partition(int *arr, int n)
{
        qsort(arr, n, sizeof(int), compare);

        int max = INT_MIN;
        int min = INT_MAX;
        int i;
        int x;

        for (i = 0; i < n/2; ++i) {
                x = arr[i] + arr[n-1-i];   
                if (x < min)
                        min = x;
                if (x > max)
                        max = x;
        }

        return (max - min);
}

int main()
{
        int arr[SIZE];
        int t, n;
        int i;

        scanf("%d", &t);

        while (t--) {
                scanf("%d", &n);
                for (i = 0; i < n; ++i)
                        scanf("%d", &arr[i]);
                printf("%d\n", partition(arr, n));
        }

        return 0;
}
