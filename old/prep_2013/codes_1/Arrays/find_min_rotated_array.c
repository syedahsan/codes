#include <stdio.h>

void print(int a[], int size)
{
        int i;
        printf("[");
        for (i = 0; i < size; ++i)
                printf("%d ", a[i]);
        printf("]\n");
}

void debug_print(int a[], int start, int end)
{
        int i;
        for (i = 0; i < start; ++i)
                printf("  ");
        printf("[");
        for (i; i <= end; ++i)
                printf("%d ", a[i]);
        printf("]\n");
}

int find_min(int a[], int start, int end, int size)
{
        debug_print(a, start, end);
        if (start == end)
                return (start);

        int mid = (start + end)/2;
        
        if (a[start] >= a[end]) {
                if (a[mid] < a[(mid + size - 1)%size])
                        return (mid);
                if (a[start] == a[mid] && a[mid] == a[end]) { /* this step makes the algo non-logarithmic */
                        int i = find_min(a, start, (mid == start) ? mid : mid-1, size);
                        int j = find_min(a, (mid == end) ? mid : mid+1, end, size);
                        if (a[i] < a[j])
                                return (i);
                        else
                                return (j);
                }                        
                if (a[start] >= a[mid])
                        return find_min(a, start, (mid == start) ? mid : mid-1, size);
                else
                        return find_min(a, (mid == end) ? mid : mid+1, end, size);
        } else { /* no rotation */
                return (start);
        }
}

int main()
{
        int a[7][9] = {
                        {2, 2, 1, 2, 2, 2, 2, 2, 2},
                        {2, 2, 2, 2, 2, 2, 2, 3, 2},
                        {1, 2, 3, 4, 5, 6, 7, 8, 9},
                        {2, 3, 4, 5, 6, 7, 8, 9, 1},
                        {8, 9, 1, 2, 3, 4, 5, 6, 7},
                        {4, 5, 6, 7, 8, 9, 1, 2, 3},
                        {6, 7, 8, 9, 1, 2, 3, 4, 5}
                     };
        int i;

        for(i = 0; i < 7; ++i) {
                //print(a[i], 9);
                int min = find_min(a[i], 0, 8, 9);
                printf("Min: %d\n", min);
        }

        return 0;
}
