#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

#define SIZE 25

/* -limit/2 to limit/2 */
int myrand(int limit)
{
        return ((rand() % limit));
}

void populate_arr(int *arr, int size)
{
        int i;
        srand(time(NULL));
        for (i = 0; i < size; ++i) {
                arr[i] = myrand(51);
        }

        return;
}

/* Debug */
void print_arr(int *arr, int size)
{
        int i;
        printf("[");
        for (i = 0; i < size; ++i) {
                printf("%d ", arr[i]);
        }
        printf("]\n");
}

/*
 * Solution to this problem is finding a best fill for
 * a sack of capacity 's' (s = sum(arr)/2)
 *
 * Let M(i,j) = 1 if a sack of size j can be filled completely
 *                by a subset of i items
 *            = 0 otherwise
 *
 * So,
 * M(i,j) = max { M(i-1, j), M(i-1, j-Si) }
 *
 * We can backtrack to find the elements involved
 *
 * Best fill capacity would be last j which was completely filled
 */
void partition(int *arr, int size)
{
        int i, j, s = 0;
        for (i = 0; i < size; ++i)
                s += arr[i];
        s /= 2;

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

        /* Debug */
#if 0
        for (i = 0; i < size; ++i) {
                for (j = 0; j <= s; ++j) {
                        printf("%d ", M[i][j]);
                }
                printf("\n");
        }
        printf("\n");
#endif

        /* Backtrack */
        for (j = s; j >= 0; --j) /* finding best filled capacity j */
                if (M[size-1][j] == 1)
                        break;
        int *b = calloc(size, sizeof(int));
        for (i = size - 1; i > 0; --i) {
                if (M[i-1][j-arr[i]] == 1) {
                        b[i] = 1;
                        j = j - arr[i];
                }
        }
        /* 1st item */
        if (j - arr[i] == 0)
                b[i] = 1;
        
        /* partition */
        printf("[");
        for (i = 0; i < size; ++i)
                if (b[i] == 0)
                        printf("%d ", arr[i]);
        printf("][");
        for (i = 0; i < size; ++i)
                if (b[i] == 1)
                        printf("%d ", arr[i]);
        printf("]\n");
        
        /* cleanup */
        for (i = 0; i < size; ++i)
                free(M[i]);
        free(M);
        free(b);

        return;
}

int main()
{
        int arr[SIZE];

        populate_arr(arr, SIZE);
        print_arr(arr, SIZE);

        partition(arr, SIZE);

        return 0;
}
