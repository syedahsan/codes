#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

int dp_max_value_contiguous_subsequence(int *A, int size)
{
        int *M = calloc(size, sizeof(int));
        int i;

        /* M[i] = max contiguous subsequence sum ending at i; including i
         * M[i] = M[i-1] + A[i] if (M[i-1] + A[i] >= A[i]])
         * M[i] = A[i] otherwise
         *
         * or M[i] = max(A[i], M[i-1] + A[i]);
         *
         * return value = max_i(M[i])
         */

        for (i = 0; i < size; ++i) {
                if ((i-1) >= 0 && (M[i-1] + A[i] >= A[i]))
                        M[i] = M[i-1] + A[i];
                else
                        M[i] = A[i];
        }

        int max = INT_MIN;
        for (i = 0; i < size; ++i)
                if (M[i] > max)
                        max = M[i];


        free(M);

        return (max);
}

/* same solution as above but a little space efficient;
 * as the var local_sum is nothing but M[i-1];
 */
int max_value_contiguous_subsequence(int *A, int size)
{
        int global_sum = INT_MIN;
        int local_sum = 0;
        int i;

        for (i = 0; i < size; ++i) {
                if (local_sum + A[i] >= A[i])
                        local_sum += A[i];
                else
                        local_sum = A[i];

                if (local_sum > global_sum)
                        global_sum = local_sum;
        }

        return (global_sum);
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

        int sum = max_value_contiguous_subsequence(A, SIZE);
        printf("MAX SUM: %d\n", sum);

        int sum1 = dp_max_value_contiguous_subsequence(A, SIZE);
        printf("MAX SUM: %d\n", sum1);

}
