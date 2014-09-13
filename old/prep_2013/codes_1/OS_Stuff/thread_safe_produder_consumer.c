#include <stdio.h>
#include <pthread.h>

#define SIZE 11

pthread_cond_t space_available = PTHREAD_COND_INITIALIZER;
pthread_cond_t data_available = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int buffer[SIZE];
int front = 0, rear = 0; /* producer is producing at front index
                          * consumer is consuming at rear index */

/* Take the mutex lock for accessing the critical data (buffer & rear)
 * It may be the case that producer is writing at a different location
 * and consumer is consuming at different location.
 * But, for the case where they both are accessing the same location
 * its critical section.
 *
 * Now a consumer thread will wait to enter the critical section if
 * producer is already in. If the buffer becomes full, producer will
 * wait on condition variable space_available and will release
 * the mutex lock allowing the consumer to enter. As soon as consumer
 * consumes it will signal that space is available and that will release
 * the producer and it producer thread will acquire the mutex lock
 * blocking the consumer thread at lock condition and will start producing.
 *
 * consumer can enter directly if the mutex lock is available;
 * it will block at data_available if the buffer is empty releasing
 * the mutex lock allowing the producer thread to enter the critical section.
 * producer will produce and will signal data_available which will release
 * consumer whilst acquiring the mutex lock.
 */

void *produce()
{
        int i = 0;
        while (1) {
                printf("Producer\n");
                fflush(NULL);

                pthread_mutex_lock(&mutex);
                while ((front + 1) % SIZE == rear) { /* buffer is full */
                        printf("Producer: Buffer is full!\n");
                        fflush(NULL);
                        pthread_cond_wait(&space_available, &mutex);
                }
                /* critical section starts here */
                buffer[front] = i;
                front = (front + 1) % SIZE;
                /* critical section ends here */
                pthread_cond_signal(&data_available);
                pthread_mutex_unlock(&mutex);
                
                ++i; /* don't need a lock since only a single producer thread is working,
                        and consumer has no access to this variable */
        }

        pthread_exit(NULL);
}

void *consume()
{
        int i, v;
        for (i = 0; i < 100; ++i) {
                printf("Consumer\n");
                fflush(NULL);
                
                pthread_mutex_lock(&mutex);
                while (front == rear) { /* buffer is empty */
                        printf("Consumer: Buffer is empty!\n");
                        fflush(NULL);
                        pthread_cond_wait(&data_available, &mutex);
                }
                /* critical section starts here */
                v = buffer[rear];
                rear = (rear + 1) % SIZE;
                /* critical section ends here */
                pthread_cond_signal(&space_available);
                pthread_mutex_unlock(&mutex);
                
                printf("Got Data: %d\n", v);
                fflush(NULL);
        }
        pthread_exit(NULL);
}

/* Creating a single producer thread;
 * Creating s single consumer thread;
 * 
 * Producer thread produces data infinitely.
 * Consumer runs only 100 iterations.
 * So, we are only waiting for consumer thread to return.
 * Producer thread exits as we exit the program.
 */

int main()
{
        pthread_t producer_thread;
        pthread_t consumer_thread;

        pthread_create(&producer_thread, NULL, produce, NULL);
        pthread_create(&consumer_thread, NULL, consume, NULL);
        pthread_join(consumer_thread, NULL);
}
