#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

inline int max(int x, int y) {
        return ((x > y) ? x : y);
}

inline int min(int x, int y) {
        return ((x < y) ? x : y);
}

/*
 * Let M(i, j) be the maximum value a player can attain
 * in the game of coins from i to j
 *
 * So,
 * M(i, j) = max { min {M(i+2, j)}, + A[i]            min{M(i, j-2)}   + A[j]    }
 *                      M(i+1, j-1)                       M(i+1, j-1)
 *                 If player picks coin;            If player picks coin
 *                        i                                j
 *
 * Description: If player picks coin i or j, then his opponent being equally wise
 * will choose the coin for which we get minimum of the two options present
 * to him
 */
int optimal_strategy(int *a, int n)
{
        /* declarations */
        int i, j;
        int **M = calloc(n, sizeof(int*));
        for (i = 0; i < n; ++i) {
                M[i] = calloc(n, sizeof(int));
        }

        /* build the solution */
        for (i = n-1; i >= 0; --i) {
                for (j = i; j < n; ++j) {
                        if (j == i) {
                                M[i][j] = a[i];
                        } else if (j == i+1) {
                                M[i][j] = max(a[i], a[i+1]);
                        } else {
                                M[i][j] = max(min(M[i+2][j], M[i+1][j-1]) + a[i], min(M[i][j-2], M[i+1][j-1]) + a[j]);
                        }
                }
        }

        /* debug */
#if 0
        for (i = 0; i < n; ++i) {
                for (j = 0; j < n; ++j) {
                        printf("%d ", M[i][j]);
                }
                printf("\n");
        }
        printf("\n");
#endif

        int val = M[0][n-1];

        /* cleanup */
        for (i = 0; i < n; ++i)
                free(M[i]);
        free(M);

        return val;
}

int main()
{
        /* declaration */
        int i, n;
        int a[MAX_LEN];

        /* input */
        scanf("%d", &n);
        if (n >= MAX_LEN) {
                printf("Error!. Enter a value less than or equal to %d", MAX_LEN);
                return 1;
        }
        for (i = 0; i < n; ++i)
                scanf("%d", &a[i]);

        int maxval = optimal_strategy(a, n);
        printf("Maximum value that can be attained by first player: %d\n", maxval);

        return 0;
}
