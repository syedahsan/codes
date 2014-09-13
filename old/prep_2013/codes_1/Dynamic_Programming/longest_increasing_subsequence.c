/* given an array; find the longest increasing subsequence
 * not necessarily contiguous
 *
 * M[i] = LIS ending at i; including i
 *
 * M[i] = max (0 < j <= i) [M[i-j]] s.t. (A[i] > A[i-j]) {strictly increasing}
 *
 * LIS = max (i) [M[i]]
 *
 * O(n^2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define SIZE 20

int longest_increasing_subsequence(int *A, int size)
{
        int *M = calloc(size, sizeof(int));
        int *B = calloc(size, sizeof(int)); /* Backtrack array */
        int i, j;
        int max;

        memset(M, 1, size*sizeof(int)); /* every index is atleast LIS of size 1; ie itself */
        memset(B, -1, size*sizeof(int)); /* every index atleast start at itself */

        for (i = 0; i < size; ++i) {
                int max = INT_MIN;
                for (j = 1; j <= i; ++j) {
                        // if (A[i] >= A[i-j] && M[i-j] > max) { /* not strictly increasing */
                        if (A[i] > A[i-j] && M[i-j] > max) {
                                max = M[i-j];
                                B[i] = i - j;
                        }
                }
                if (max == INT_MIN)
                        M[i] = 1;
                else
                        M[i] = max + 1;
        }

        /* finding LIS */
        max = INT_MIN; /* length */
        j = 0; /* index */
        for (i = 0; i < size; ++i) {
                if (M[i] > max) {
                        max = M[i];
                        j = i;
                }
        }

        /* Backtrack to print the sequence */
        printf("LIS (reverse): ");
        i = j;
        while (i != -1) {
                printf("%d, ", A[i]);
                i = B[i];
        }
        printf("\n");

        free(M);
        free(B);

        return (max);
}

int my_rand()
{
        return ((rand() % 20) - 10);
}

void gen_values(int *A, int size)
{
        int i;
        srand(time(NULL));
        for (i = 0; i < size; ++i) {
                A[i] = my_rand();
        }
}

int main()
{
        int A[SIZE];
        int i;

        gen_values(A, SIZE);

        /* DEBUG */
        for (i = 0; i < SIZE; ++i)
                printf("%d ", A[i]);
        printf("\n");

        int len = longest_increasing_subsequence(A, SIZE);
        printf("Length of LIS: %d\n", len);

        return 0;
}
