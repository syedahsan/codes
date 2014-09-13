#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_coins(int C, int *V, int size)
{
        int *M = calloc(C + 1, sizeof(int));
        int i, j;
        int min;

        for (i = 1; i <= C; ++i) {
                min = INT_MAX;
                for (j = 0; j < size; ++j) {
                        if ((i - V[j] >= 0) && (M[i - V[j]] < min)) {
                                min = M[i - V[j]];
                        }
                }
                M[i] = (min == INT_MAX) ? INT_MAX : min + 1;
        }

        int min_change = (M[C] == INT_MAX) ? -1 : M[C];

        free(M);

        return (min_change);
}

int main()
{
        int V[] = {5, 5, 5, 5, 5};
        int size = sizeof(V)/sizeof(int);

        int C;
        scanf("%d", &C);
        printf("%d\n",min_coins(C, V, size));

        return 0;
}
