#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 100
#define RING_SIZE 10
#define TRUE 1
#define FALSE 0



int myrand(int limit)
{
        return (rand() % limit);
}

int produce(int CB[], int size, int p, int c)
{
        printf("Producing\n");
        if ((p + 1) % size == c) { /* change if to while in threaded program? */
                printf("Buffer is full!\n");
                return (p);
        }
        CB[p] = myrand(10);
        p = (p + 1) % size;
        return (p);
}

int consume(int CB[], int size, int p, int c)
{
        printf("Consuming\n");
        if (c == p) { /* change if to whilie in threaded program? */
                printf("Buffer is Empty!\n");
                return (c);
        }
        c = (c + 1) % size;
        return (c);
}

void print(int CB[], int size, int p, int c)
{
        int i;
        for (i = c; i != p; i = (i + 1) % size)
                printf("%d ", CB[i]);
        printf("\n");
}

int main()
{
        int CB[RING_SIZE + 1] = {0};
        int n = NUM_ITERATIONS;
        int p, c; /* production and consumption indexes */
        
        srand(time(NULL));

        while (n--) {
                if (myrand(2) == TRUE) {
                        p = produce(CB, RING_SIZE + 1, p, c);
                } else {
                        c = consume(CB, RING_SIZE + 1, p, c);
                }
                print(CB, RING_SIZE + 1, p, c);
                printf("----------------------------\n");
        }

        return 0;
}
