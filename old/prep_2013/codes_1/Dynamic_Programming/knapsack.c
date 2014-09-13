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

int myrand(void)
{
        return ((rand() % 50) + 1);
}

void gen_items(item *Items, int size)
{
        int i;
        srand(time(NULL));
        for (i = 0; i < size; ++i) {
                Items[i].v = myrand();
                Items[i].s = myrand();
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

void knapsack(int C, item *Items, int size)
{
        int *M = calloc(C + 1, sizeof(int));
        int *B = calloc(C + 1, sizeof(int)); /* Backtrack */
        int i, j;

        memset(B, -1, (C+1)*sizeof(int));

        for (i = 0; i <= C; ++i) {
                for (j = 0; j < size; ++j) {
                        if ((i - Items[j].s >= 0) && ((M[i - Items[j].s] + Items[j].v) > M[i])) {
                                M[i] = M[i - Items[j].s] + Items[j].v;
                                B[i] = j;
                        }
                }
                if (i >= 0 && M[i] <= M[i-1]) {
                        M[i] =  M[i-1];
                        B[i] = -1;
                }
        }

        /* Backtrack */
        i = C;
        while (i >= 0) {
                if (B[i] != -1) {
                        printf("(%d, %d) ", Items[B[i]].v, Items[B[i]].s);
                        i -= Items[B[i]].s;
                } else
                        i -= 1;
        }
        printf("\n");

        free(M);
        free(B);
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
                knapsack(C, Items, NUMITEMS);
        }

        return 0;
}
