#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print(int a[], int n);
int BinarySearch(int *a, int lo, int hi, int key);

inline void swap(int *x, int *y)
{
        int temp;

        temp = *x;
        *x = *y;
        *y = temp;
}

/* O(n^2)
 * sends the max element to end in every step
 */
void bubble_sort(int *a, int n)
{
        int i, j;
        for (i = n-1; i >= 0; --i) {
                for (j = 0; j < i; ++j) {
                        if (a[j] > a[j+1])
                                swap(&a[j], &a[j+1]);
                }
        }

        return;
}

/* O(n^2)
 * selects min in each step;
 * swaps min with the first element in the remaining array
 * only n swaps required
 */
void selection_sort(int *a, int n)
{
        int i, j;
        int min, i_min;

        for (i = 0; i < n; ++i) {
                min = INT_MAX;
                for (j = i; j < n; ++j) {
                        if (a[j] < min) {
                                min = a[j];
                                i_min = j;
                        }
                }
                swap(&a[i], &a[i_min]);
        }

        return;
}

int binsearch(int *a, int n, int x)
{
        if (a == NULL || n < 0)
                return (-1);

        int i, j, mid;
        i = 0;
        j = n;

        while (i < j) {
                mid = i + (j - i)/2;
                if (a[mid] < x) {
                        i = mid + 1;
                } else if (a[mid] > x) {
                        j = mid;
                } else
                        break;
        }
        if (i == j)
                return (i);
        return (mid);
}


/* O(n^2)
 * at every step i atleast i elements are sorted
 */
void insertion_sort(int *a, int n)
{
        int i, j;
        int pos;
        int temp;
        for (i = 1; i < n; ++i) {
                if (a[i] < a[i-1]) {
                        pos = binsearch(a, i, a[i]);
                        if (pos < i) {
                                temp = a[i];
                                for (j = i; j > pos; --j)
                                        a[j] = a[j-1];
                                a[pos] = temp;
                        }
                }
        }

        return;
}

/* not my code */

int BinarySearch(int *a, int lo, int hi, int key)
{
        if (lo == hi)
                return (lo);

        int mid = lo + (hi - lo)/2;

        if (a[mid] < key)
                return BinarySearch(a, mid+1, hi, key);
        if (a[mid] > key)
                return BinarySearch(a, lo, mid, key);

        return (mid);
}

void BinaryInsertionSort (int a[], int n)
{
        register int i, m;
        int hi, lo, tmp;

        for (i = 1; i < n; ++i) {
                lo = 0, hi = i;
                m = i / 2;

                do {
                        if (a[i] > a[m]) {
                                lo = m + 1;
                        } else if (a[i] < a[m]) {
                                hi = m;
                        } else
                                break;

                        m = lo + ((hi - lo) / 2);
                } while (lo < hi);

                if (m < i) {
                        tmp = a[i];
                        memmove (a + m + 1, a + m, sizeof (int) * (i - m));
                        a[m] = tmp;
                }
        }
}

void _merge(int *a, int lo, int mid, int hi)
{
        int *b = calloc(hi-lo+1, sizeof(int));
        int i, j, k;
        for (i = lo, j = mid+1, k = 0; i <= mid && j <= hi; ) {
                if (a[i] <= a[j]) {
                        b[k++] = a[i++];
                } else {
                        b[k++] = a[j++];
                }
        }
        if (i > mid) {
                while (j <= hi) {
                        b[k++] = a[j++];
                }
        } else if (j > hi) {
                while (i <= mid) {
                        b[k++] = a[i++];
                }
        }

        for (i = 0; i < (hi-lo+1); ++i)
                a[lo+i] = b[i];

        free(b);
}

void _mergesort(int *a, int lo, int hi)
{
        if (lo == hi)
                return;

        int mid = lo + (hi - lo)/2;
        _mergesort(a, lo, mid);
        _mergesort(a, mid+1, hi);
        _merge(a, lo, mid, hi);
}
        
void merge_sort(int *a, int n)
{
        _mergesort(a, 0, n-1);
}

inline int myrand(int lo, int hi)
{
        return ((rand() % (hi-lo+1)) + lo);
}

void _qsort(int *a, int lo, int hi)
{
        if (lo >= hi)
                return;

        int st = lo;
        int end = hi;
        int pivot = myrand(lo, hi);

        /* sort on pivot */
        swap(&a[pivot], &a[hi]);
        pivot = hi;
        --hi;
        while (lo < hi) {
                while (a[lo] <= a[pivot] && (lo < hi)) ++lo;
                while (a[hi] > a[pivot] && (lo < hi)) --hi;
                if (lo < hi)
                        swap(&a[lo], &a[hi]);
        }
        /* pivot's new location */
        if (lo == hi) {
                if (a[lo] < a[pivot])
                        pivot = lo + 1;
                else
                        pivot = lo;
        } else if (lo == end) {
                pivot = end;
        } else if (hi == st) {
                pivot = st;
        }

        swap(&a[end], &a[pivot]);
        
        _qsort(a, st, pivot);
        _qsort(a, pivot+1, end);

}

void quick_sort(int *a, int n)
{
        srand(time(NULL));
        _qsort(a, 0, n-1);
}

int *copy(int a[], int *b, int n)
{
        if (b == NULL)
                b = calloc(n, sizeof(int));

        int i;
        for (i = 0; i < n; ++i)
                b[i] = a[i];

        return (b);
}

void print(int a[], int n)
{
        int i;
        printf("[");
        for (i = 0; i < n; ++i) {
                printf("%d ", a[i]);
        }
        printf("]\n");
}

int main()
{
        //int a[] = {1, 1, 1, 1, 1, 4, 3, 2, 2, 6, 6, 5};
        int a[] = {8, 4, 6, 1, 3, 3, 7, 9, 11, 2, -1};
        int size = sizeof(a)/sizeof(int);
        print(a, size);

        int *b = NULL;
        
        b = copy(a, b, size);
        bubble_sort(b, size);
        print(b, size);

        b = copy(a, b, size);
        selection_sort(b, size);
        print(b, size);

        b = copy(a, b, size);
        insertion_sort(b, size);
        //BinaryInsertionSort(b, size);
        print(b, size);

        b = copy(a, b, size);
        merge_sort(b, size);
        print(b, size);
        
        b = copy(a, b, size);
        quick_sort(b, size);
        print(b, size);
        
        
        free(b);
}
