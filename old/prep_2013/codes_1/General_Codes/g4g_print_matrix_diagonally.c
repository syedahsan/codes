/*
 *   1  2  3  4  5  6
 *   7  8  9 10 11 12
 *  13 14 15 16 17 18
 *  19 20 21 22 23 24
 *  25 26 27 28 29 30
 *
 *  1
 *  7  2
 * 13  8  3
 * 19 14  9  4
 * 25 20 15 10  5
 * 26 21 16 11  6
 * 27 22 17 12
 * 28 23 18
 * 29 24
 * 30
 */

#include <stdio.h>

#if 0 /* Border Cases */
#define ROW 1
#define COL 5

#define ROW 4
#define COL 1
#endif

#define ROW 5
#define COL 6

#define min(a, b) ((a < b) ? a : b)

void printDiagonal(int arr[ROW][COL])
{
        int i, j, row, col;
        for (row = 0; row < (ROW + COL - 1); row++) {
                i = min(ROW - 1, row);
                col = min(COL - 1, row);

                for (j = row - i; j <= col; j++)
                        printf(" %2d", arr[row-j][j]);

                printf("\n");
        }

        return;
}

void printMatrix(int arr[ROW][COL])
{
        int i, j;

        for (i = 0; i < ROW; i++) {
                for (j = 0; j < COL; j++)
                        printf(" %2d", arr[i][j]);
                printf("\n");
        }

        return;
}

int main()
{
#if 0 /* Border Case */
        int Arr[ROW][COL] = {
                                {1, 2, 3, 4, 5},
                            };
        
        int Arr[ROW][COL] = {
                                {1},
                                {2},
                                {3},
                                {4},
                            };
#endif
        int Arr[ROW][COL] = {
                         {1,  2,  3,  4,  5,  6 },
                         {7,  8,  9,  10, 11, 12},
                         {13, 14, 15, 16, 17, 18},
                         {19, 20, 21, 22, 23, 24},
                         {25, 26, 27, 28, 29, 30},
                        };

        printMatrix(Arr);
        printf("\n");

        printDiagonal(Arr);

        return 0;
}
