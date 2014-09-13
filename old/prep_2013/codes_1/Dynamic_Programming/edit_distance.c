#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100
#define cA 1 /* cost of appending */
#define cD 1 /* cost of deleting */
#define cR 1 /* cost of replacing */

inline int min(int x, int y) {
        return ((x < y) ? x : y);
}

/*
 * let M(i, j) is the edit distance for A[0..i] and B[0..j]
 *
 * So,
 * M(i,j) =     M(i-1, j-1) if A[i] == B[j]
 *              min {
 *                      M(i-1, j) + cD;
 *                      M(i, j-1) + cA;
 *                      M(i-1, j-1) + cR;
 *                  }
 *              otherwise
 */
int edit_distance(char *a, int len_a, char *b, int len_b)
{
        int i, j;
        /* we could just do away with 3 variables */
        int **M = calloc(len_a, sizeof(int*));
        for (i = 0; i < len_a; ++i)
                M[i] = calloc(len_b, sizeof(int));

        for (i = 0; i < len_a; ++i) {
                for (j = 0; j < len_b; ++j) {
                        if (a[i] == b[j]) {
                                if (i > 0 && j > 0)
                                        M[i][j] = M[i-1][j-1];
                                else
                                        M[i][j] = 0;
                        } else {
                                int x = ((i > 0) ? M[i-1][j] : 0) + cD;
                                int y = ((j > 0) ? M[i][j-1] : 0) + cA;
                                int z = ((i > 0 && j > 0) ? M[i-1][j-1] : 0) + cR;
                                M[i][j] = min(x, min(y, z));
                        }
                }
        }

        int ret = M[len_a - 1][len_b - 1];

        /* cleanup */
        for (i = 0; i < len_a; ++i)
                free(M[i]);
        free(M);

        return (ret);
}

int main()
{
        char a[MAX_LEN];
        char b[MAX_LEN];

        scanf("%s", a);
        scanf("%s", b);

        int dis = edit_distance(a, strlen(a), b, strlen(b));

        printf("Edit Distance: %d\n", dis);

        return 0;
}
