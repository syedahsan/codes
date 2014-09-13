#include <stdio.h>

#define SIZE 100

int binary_search(int a[], int start, int end, int k)
{
        /* debug */
        int i;
        printf("[");
        for (i = start; i <= end; ++i)
                printf("%d ", a[i]);
        printf("]\n");
        /* debug */

        int mid = (start + end)/2;
        if (k == a[mid])
                return mid;
        
        if (start == end)
                return -1;
        
        if (k > a[mid])
                return binary_search(a, mid, end, k);
        else
                return binary_search(a, start, mid, k);
}

int main()
{
        int a[] = {1, 2, 2, 2, 3, 4, 5, 6, 7};
        int size = sizeof(a)/sizeof(int);

        int k = 2;

        int ind = binary_search(a, 0, size - 1, k);
        printf("%d\n", ind);
}

