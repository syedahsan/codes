#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

#define MAX_LEN 10

typedef struct _port {
        int south; /* stores the x co-ordinate of south port */
        int north; /* stores the x co-ordinate of north port */
} port;

inline void swap(int *x, int *y)
{
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
}

inline int myrand(int limit)
{
        return (rand() % limit);
}

void populate(port a[], int num)
{
        int i;
        srand(time(NULL));
        for (i = 0; i < num; ++i) {
                a[i].south = i;
                a[i].north = i;
        }

        /* shuffle */
        for (i = 0; i < num; ++i) {
                swap(&a[i].north, &a[myrand(num)].north);
                swap(&a[i].south, &a[myrand(num)].south);
        }

        return;
}

void print(port a[], int num)
{
        int i;
        for (i = 0; i < num; ++i) {
                printf("%d ", a[i].north);
        }
        printf("\n");

        for (i = 0; i < num; ++i) {
                printf("%d ", a[i].south);
        }
        printf("\n");
}

int compare(const void *x, const void *y)
{
        return (((port *)x)->north > ((port *)y)->north);
}

void max_bridges(port a[], int num)
{
        qsort(a, num, sizeof(port), compare);
        print(a, num);

        /* LIS on south ports */
        int *M = calloc(num, sizeof(int)); /* dp array */
        int *B = calloc(num, sizeof(int)); /* backtrack */
        memset(B, -1, num*sizeof(int));

        int i, j;
        for (i = 0; i < num; ++i) {
                for (j = 0; j < i; ++j) {
                        if (M[j] > M[i] && a[i].south > a[j].south) {
                                M[i] = M[j];
                                B[i] = j;
                        }
                }
                M[i] += 1;
        }

        int max = 0;
        for (i = 0; i < num; ++i) {
                if (M[i] > max) {
                        max = M[i];
                        j = i; /* index of max */
                }
        }

        while (j >= 0) {
                printf("(%d, %d) ", a[j].north, a[j].south);
                j = B[j];
        }
        printf("\n");

        /* cleanup */
        free(M);
        free(B);

        return;
}

int main()
{
        port a[MAX_LEN];

        populate(a, MAX_LEN);
        print(a, MAX_LEN);
        printf("\n");

        max_bridges(a, MAX_LEN);

        return 0;
}
