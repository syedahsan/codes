#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int size)
{
        int i, j, sz = 0;
        for (i = 0; i < size; ++i)
                sz += arr[i];
        int s = sz/2;

        int **M = calloc(size, sizeof(int *));
        for (i = 0; i < size; ++i)
                M[i] = calloc(s+1, sizeof(int));

        for (i = 0; i < size; ++i) {
                for (j = 0; j <= s; ++j) {
                        if (j == 0 || j - arr[i] == 0) { /* Base Case */
                                M[i][j] = 1;
                        } else { /* Subproblems */
                                int a = 0, b = 0;
                                if (i - 1 >= 0) {
                                        a = M[i-1][j];
                                        if (j - arr[i] >= 0) {
                                                b = M[i-1][j-arr[i]];
                                        }
                                }
                                M[i][j] = ((a > b) ? a : b);
                        }
                }
        }

        for (j = s; j >= 0; --j) /* finding best filled capacity j */
                if (M[size-1][j] == 1)
                        break;

        /* cleanup */
        for (i = 0; i < size; ++i)
                free(M[i]);
        free(M);

        i = sz - j;
        int ret = (((i - j) > 0) ? (i - j) : (j - i));
        return (ret);
}

int main()
{
        int *arr = NULL;
        int t, n;
        int i;

        scanf("%d", &t);

        while (t--) {
                scanf("%d", &n);
                arr = calloc(n, sizeof(int));
                for (i = 0; i < n; ++i)
                        scanf("%d", &arr[i]);
                printf("%d\n", partition(arr, n));
                free(arr);
                arr = NULL;
        }

        return 0;
}
