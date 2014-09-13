#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

#define NUMITEMS 10

typedef struct _item {
        int v; /* value */
        int s; /* size */
} item;

int myrand(int limit)
{
        return ((rand() % limit) + 1);
}

void gen_items(item *Items, int size)
{
        int i;
        srand(time(NULL));
        for (i = 0; i < size; ++i) {
                Items[i].v = myrand(50);
                Items[i].s = myrand(20);
        }

        return;
}

/* Debug */
void print_items(item *Items, int size)
{
        int i;
        for (i = 0; i < size; ++i) {
                printf("(%d, %d) ", Items[i].v, Items[i].s);
        }
        printf("\n");
}

void integer_knapsack(int C, item *Items, int size)
{
        /* M[i, W] = Value in sack of "exact" weight W, using i items
         *
         * M[i, W] = max(M[i-1, W-Si] + Vi, M[i-1, W])
         *
         * Ans = max (i) [M[n, i]]
         */

        int i, j;
        item **M = calloc(size + 1, sizeof(item*));
        for (i = 0; i <= size; ++i) {
                M[i] = calloc(C + 1, sizeof(item));
        }


        for (i = 1; i <= size; ++i) {
                for (j = 1; j <= C; ++j) {
                        if (j - Items[i-1].s >= 0 && (M[i-1][j].v < M[i-1][j-Items[i-1].s].v + Items[i-1].v)) {
                                M[i][j].v = M[i-1][j-Items[i-1].s].v + Items[i-1].v;
                                M[i][j].s = j - Items[i-1].s;
                        } else {
                                M[i][j].v = M[i-1][j].v;
                                M[i][j].s = j;
                        }
                }
        }

        /* Debug */
/*
        for (i = 0; i <= size; ++i) {
                for (j = 0; j <= C; ++j) {
                        printf("(%d, %d) ", M[i][j].v, M[i][j].s);
                }
                printf("\n");
        }
*/

        /* Backtrack bitches */
        i = size;
        j = C;
        printf("Max Value: %d\nItems: ",M[i][j].v);
        while (i && j) {
                if (M[i][j].v == M[i][j-1].v) { /* move left if possible */
                        j = j - 1;
                } else if (M[i][j].v == M[i-1][j].v) { /* move up if possible */
                        i = i - 1;
                } else {
                        j = M[i][j].s;
                        i = i - 1;
                        printf("(%d, %d) ", Items[i].v, Items[i].s);
                }
        }
        printf("\n");

        for (i = 0; i <= size; ++i) {
                free(M[i]);
        }
        free(M);

        return;
}

int main()
{
        item Items[NUMITEMS];

        gen_items(Items, NUMITEMS);
        print_items(Items, NUMITEMS);

        int n, C;
        scanf("%d", &n);
        while (n--) {
                scanf("%d", &C);
                integer_knapsack(C, Items, NUMITEMS);
        }

        return 0;
}
