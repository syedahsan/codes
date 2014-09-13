#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 1

int **rotate_90(int a[ROW][COL], int m, int n)
{
        int i, j;
        int **b = NULL;
        
        b = calloc(m, sizeof(int*));
        for (i = 0; i < n; ++i) {
                b[i] = calloc(m, sizeof(int));
        }

        /* rotate */
        for (i = 0; i < m; ++i) {
                for (j = 0; j < n; ++j) {
                        b[j][m-1-i] = a[i][j];
                }
        }

        return (b);
}

void cleanup(int **b, int m, int n)
{
        int i;
        for (i = 0; i < m; ++i)
                free(b[i]);
        free(b);
}

void print_a(int a[ROW][COL], int m, int n)
{
        int i, j;
        for (i = 0; i < m; ++i) {
                for (j = 0; j < n; ++j) {
                        printf("%02d ", a[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}

void print_b(int **b, int m, int n)
{
        int i, j;
        for (i = 0; i < m; ++i) {
                for (j = 0; j < n; ++j) {
                        printf("%02d ", b[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}
int main()
{
/*
        int a[ROW][COL] = {
                                {1, 2},
                                {3, 4},
                                {5, 6},
                                {7, 8}
                          };
*/
        int a[ROW][COL] = {
                                {1},
                                {3},
                                {5},
                                {7}
                          };


        print_a(a, ROW, COL);
        int **b = rotate_90(a, ROW, COL);
        print_b(b, COL, ROW);

        cleanup(b, COL, ROW);

        return 0;
}
