#include <stdio.h>
#include <limits.h>

#define SIZE_INT(x) (sizeof(x)/sizeof(int))

int print_arr(int a[], int start, int end)
{ 
        int i;
        for (i = 0; i < start; ++i)
                printf("  ");
        printf("[");
        for (i = start; i < end; ++i)
                printf("%d ", a[i]);
        printf("]");
        printf("\n");
}

int findKthSmallest(int a[], int m, int b[], int n, int k)
{
        int i = (int) (1.0 * (k-1) * m / (m + n));
        int j = (k-1) - i;

        /* a[-1] = b[-1] = INT_MIN; a[m] = b[n] = INT_MAX; */
        int Ai = (i == m) ? INT_MAX : a[i];
        int Bj = (j == n) ? INT_MAX : b[j];
        int Ai1 = (i == 0) ? INT_MIN : a[i-1];
        int Bj1 = (j == 0) ? INT_MIN : b[j-1];

        if (Bj1 <= Ai && Ai <= Bj)
                return Ai;
        if (Ai1 <= Bj && Bj <= Ai)
                return Bj;

        if (Ai < Bj)
                return findKthSmallest(a+i+1, m-i-1, b, j, k-i-1);
        else
                return findKthSmallest(a, i, b+j+1, n-j-1, k-j-1);
}

int main()
{
        int a[] = {1, 1, 1, 1, 5, 6, 7};
        int b[] = {8, 9, 10};

        int size_a = SIZE_INT(a);
        int size_b = SIZE_INT(b);

        /* debug */
        print_arr(a, 0, size_a);
        print_arr(b, 0, size_b);

        int k;
        scanf("%d", &k);

        if (k > 0 && k <= (size_a + size_b)) {
                int k_smallest = findKthSmallest(a, size_a, b, size_b, k);
                printf("%dth smallest is: %d\n", k, k_smallest);
        }
}

