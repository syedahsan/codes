#include <stdio.h>
#include <stdlib.h>


inline void swap(int *arr, int i, int j)
{
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}

typedef enum {
        MAX_HEAP = 0,
        MIN_HEAP,
} heap_type;

typedef struct _heap {
        int size;
        int count;
        heap_type type;
        int *arr;
} heap;

heap* heap_init(int size, heap_type type)
{
        heap *ret = calloc(1, sizeof(heap));

        ret->size = size;
        ret->count = 0;
        ret->type = type;
        ret->arr = calloc(size, sizeof(int));

        return (ret);
}

unsigned int is_heap_full(heap *h)
{
        if (h == NULL)
                return (0);

        return (h->count >= h->size);
}

void heap_push(heap *h, int val)
{
        if (h == NULL)
                return;

        if (is_heap_full(h))
                return;

        switch (h->type) {
                case MAX_HEAP: {
                                       int index = h->count;
                                       h->arr[index] = val;

                                       /* percolate up */
                                       while (index) {
                                               if (h->arr[index] > h->arr[index/2]) {
                                                       swap(h->arr, index, index/2);
                                                       index = index/2;
                                               } else {
                                                       break;
                                               }
                                       }
                                       h->count += 1;
                                       break;
                }
                case MIN_HEAP: {
                                       int index = h->count;
                                       h->arr[index] = val;

                                       /* percolate up */
                                       while (index) {
                                               if (h->arr[index] < h->arr[index/2]) {
                                                       swap(h->arr, index, index/2);
                                                       index = index/2;
                                               } else {
                                                       break;
                                               }
                                       }
                                       h->count += 1;
                                       break;
                }
                default: {
                                 /* some error */
                }
        }

        return;
}

void heap_pop(heap *h)
{
        if (h == NULL)
                return;

        switch (h->type) {
                case MAX_HEAP: {
                                       swap(h->arr, 0, h->count - 1);
                                       h->count -= 1;

                                       /* percolate down */
                                       /* swap with max child */
                                       int index = 0;
                                       while (index < h->count) {
                                               if (((2*index + 1 < h->count) && (h->arr[index] < h->arr[2*index + 1])) &&
                                                   ((2*index + 2 < h->count) && (h->arr[index] < h->arr[2*index + 2]))) {
                                                       if (h->arr[2*index + 1] > h->arr[2*index + 2]) {
                                                               swap(h->arr, index, 2*index + 1);
                                                               index = 2*index + 1;
                                                       } else {
                                                               swap(h->arr, index, 2*index + 2);
                                                               index = 2*index + 2;
                                                       }
                                               } else if ((2*index + 1 < h->count) && (h->arr[index] < h->arr[2*index + 1])) {
                                                       swap(h->arr, index, 2*index + 1);
                                                       index = 2*index + 1;
                                               } else if ((2*index + 2 < h->count) && (h->arr[index] < h->arr[2*index + 2])) {
                                                       swap(h->arr, index, 2*index + 2);
                                                       index = 2*index + 2;
                                               } else { /* already correct order */
                                                       break;
                                               }
                                       }

                                       break;
                               }
                case MIN_HEAP: {
                                       swap(h->arr, 0, h->count - 1);
                                       h->count -= 1;

                                       /* percolate down */
                                       /* swap with min child */
                                       int index = 0;
                                       while (index < h->count) {
                                               if (((2*index + 1 < h->count) && (h->arr[index] > h->arr[2*index + 1])) &&
                                                   ((2*index + 2 < h->count) && (h->arr[index] > h->arr[2*index + 2]))) {
                                                       if (h->arr[2*index + 1] < h->arr[2*index + 2]) {
                                                               swap(h->arr, index, 2*index + 1);
                                                               index = 2*index + 1;
                                                       } else {
                                                               swap(h->arr, index, 2*index + 2);
                                                               index = 2*index + 2;
                                                       }
                                               } else if ((2*index + 1 < h->count) && (h->arr[index] > h->arr[2*index + 1])) {
                                                       swap(h->arr, index, 2*index + 1);
                                                       index = 2*index + 1;
                                               } else if ((2*index + 2 < h->count) && (h->arr[index] > h->arr[2*index + 2])) {
                                                       swap(h->arr, index, 2*index + 2);
                                                       index = 2*index + 2;
                                               } else { /* already correct order */
                                                       break;
                                               }
                                       }

                                       break;
                               }
                default: {
                                 /* error */
                         }
        }

        return;
}

int heap_front(heap *h)
{
        return ((h->count) ? h->arr[0] : -1);
}

void heap_print(heap *h)
{
        if (h == NULL)
                return;

        int i;
        printf("[");
        for (i = 0; i < h->count; ++i)
                printf("%d ,", h->arr[i]);
        printf("]\n");
}

/* k max and min elements in a stream */
int main()
{
        int k;
        heap *max = NULL;
        heap *min = NULL;

        scanf("%d", &k);

        max = heap_init(k, MIN_HEAP); /* max is calculated using min heap */
        min = heap_init(k, MAX_HEAP); /* min is calculated using max heap */

        while (1) {
                scanf("%d", &k);
                if (k == -1)
                        break;

                /* min */
                if (!is_heap_full(min)) { /* if heap is not full, keep pushing */
                        heap_push(min, k);
                } else {
                        if (k < heap_front(min)) { /* k is smaller than our largest element */
                                heap_pop(min); /* largest element must go */
                                heap_push(min, k); /* smaller element (contender) is pushed in */
                        }
                }

                /* max */
                if (!is_heap_full(max)) { /* if heap is not full, keep pushing */
                        heap_push(max, k);
                } else {
                        if (k > heap_front(max)) { /* k is larger than our smallest element */
                                heap_pop(max); /* smallest element must go */
                                heap_push(max, k); /* larger element (contender) is pushed in */
                        }
                }
        }

        printf("OUTPUT: \n");
        heap_print(min);
        heap_print(max);

        return (0);
}

