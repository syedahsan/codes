/* N denominations Vi...Vn
 * V1 = 1 (so we can always make change)
 * for a sum C find the min number of coins
 * required to make a change.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_coins(int C, int *V, int size)
{
        int *M = calloc(C + 1, sizeof(int));
        int *B = calloc(C + 1, sizeof(int)); /* Backtrack indexes */
        int i, j;
        int min;

        B[0] = -1; /* sentinal value */
        for (i = 1; i <= C; ++i) {
                min = INT_MAX;
                for (j = 0; j < size; ++j) {
                        if ((i - V[j] >= 0) && (M[i - V[j]] <= min)) {
                                min = M[i - V[j]];
                                B[i] = i - V[j];
                        }
                }
                M[i] = min + 1;
        }

        int min_change = M[C];

        /* find the exact coins */
        i = C;
        while (i) {
                printf("%d, ", i - B[i]);
                i = B[i];
        }
        printf("\n");

        free(B);
        free(M);

        return (min_change);
}

int main()
{
        int V[] = {2, 5, 10, 20, 50, 100}; /* indian denominations */
        int size = sizeof(V)/sizeof(int);

        int N, C;
        scanf("%d", &N);
        while (N--) {
                scanf("%d", &C);
                printf("%d: %d\n", C, min_coins(C, V, size));
        }

        return 0;
}
