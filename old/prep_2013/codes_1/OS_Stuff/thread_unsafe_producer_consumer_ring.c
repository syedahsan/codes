#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_PRODUCERS 5
#define NUM_CONSUMERS 5
#define RING_SIZE 5
#define TRUE 1
#define FALSE 0

int p = 0, c = 0; /* production and consumption indexes */

int myrand(int limit)
{
        return (rand() % limit);
}

void print(int CB[], int size, int p, int c)
{
        int i;
        for (i = c; i != p; i = (i + 1) % size)
                printf("%d ", CB[i]);
        printf("\n");
}

void* produce(void *cb)
{
        printf("Producing\n");
        fflush(NULL);

        int *CB = (int *)cb;
        int size = RING_SIZE + 1;
        
        while ((p + 1) % size == c) {
                printf("Producer Waiting!\n");
                fflush(NULL);
                sleep(1);
        }
        CB[p] = myrand(10);
        p = (p + 1) % size;
                
        print(CB, size, p, c);
        printf("----------------------------\n");
        fflush(NULL);

        pthread_exit(NULL);
}

void* consume(void *cb)
{
        printf("Consuming\n");
        fflush(NULL);

        int *CB = (int *)cb;
        int size = RING_SIZE + 1;

        while (c == p) {
                printf("Consumer Waiting!\n");
                fflush(NULL);
                sleep(1);
        }
        c = (c + 1) % size;
        
        print(CB, size, p, c);
        printf("----------------------------\n");
        fflush(NULL);

        pthread_exit(NULL);
}

int main()
{
        pthread_t producer_threads[NUM_PRODUCERS];
        pthread_t consumer_threads[NUM_CONSUMERS];
        int CB[RING_SIZE + 1] = {0};
        int i, j;
        
        srand(time(NULL));

        for (i = 0, j = 0; i < NUM_PRODUCERS || j < NUM_CONSUMERS; ) {
                if (myrand(2) == TRUE && i < NUM_PRODUCERS) { /* producer */
                        pthread_create(&producer_threads[i], NULL, produce, (void *)CB);
                        ++i;
                } else if (j < NUM_CONSUMERS) {
                        pthread_create(&consumer_threads[j], NULL, consume, (void *)CB);
                        ++j;
                }
        }

        for (i = 0; i < NUM_PRODUCERS; ++i)
                pthread_join(producer_threads[i], NULL);
        for (j = 0; j < NUM_CONSUMERS; ++j)
                pthread_join(consumer_threads[j], NULL);

        pthread_exit(NULL);

        return 0;
}
