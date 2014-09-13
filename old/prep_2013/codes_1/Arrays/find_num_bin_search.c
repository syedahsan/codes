/*  Problem Statement:
 *  Given a sorter array; find all occurances of a number
 *  eg. [1, 1, 1, 2, 2, 2, 2, 4, 5, 5, 6] & 2
 *  output [2, 2, 2, 2]
 */

#include <stdio.h>


inline int _ceil(double n)
{
        if (n - (int)n == 0)
                return ((int)n);
        else
                return ((int)n + 1);
}

int print_arr(int a[], int start, int end)
{ 
        int size = sizeof(a)/sizeof(int);
        int i;
        for (i = 0; i < start; ++i)
                printf("  ");
        printf("[");
        for (i = start; i <= end; ++i)
                printf("%d ", a[i]);
        printf("]");
        for (i = end + 1; i < size; ++i)
                printf("  ");
        printf("\n");
}

/* this binary search will return the index of k
 * encountered first in its binary search
 * else will return an index where that number could fit
 * in if it were to be inserted into the array.
 */
int binary_search(int a[], int start, int end, int k)
{
        /* debug */
        print_arr(a, start, end);

        //int mid = _ceil((start + end)/2.0);

        int mid = ((start + end)/2);
        if (k < a[start])
                return (start);
        if (k > a[end])
                return (end + 1);
        if (k == a[mid])
                return mid;
        
        if (start == end) {
                if (k > a[start])
                        return (start + 1);
                else
                        return (start);
        }
        
        if (k > a[mid])
                return binary_search(a, ((mid == end) ? mid : mid + 1), end, k);
        else
                return binary_search(a, start, ((mid == start) ? mid : mid - 1), k);
}

int bounday_search(int a[], int start, int end, int size)
{
        /* debug */
        print_arr(a, start, end);

        if (start == end)
                return (start);
        int mid = (start + end)/2;
        if (mid + 1 < size) {
                if (a[mid] != a[mid+1]) {
                        return (mid + 1);
                } else if (a[mid] == a[start]) {
                        return bounday_search(a, mid + 1, end, size);
                } else if (a[mid] == a[end]) {
                        return bounday_search(a, start, mid, size);
                }
        } else {
                /* no idea what will happen if this happens */
        }
}

int main()
{
        int a[] = {1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 6, 7};
        int size = sizeof(a)/sizeof(int);
        int i, k;

        print_arr(a, 0, size - 1);
        scanf("%d", &k);

        printf("Searching %d!\n", k);
        int ind_elem = binary_search(a, 0, size - 1, k);
        printf("%d found at %d!\n", k, ind_elem);
        int start, end;
        if (ind_elem >= 0 && ind_elem < size && a[ind_elem] == k) { /* found & within limits */
                /* find start */
                if (ind_elem - 1 >= 0) {
                        if (a[ind_elem - 1] != a[ind_elem]) {
                                start = ind_elem;
                        } else {
                                /* search for k-1 */
                                printf("Searching %d!\n", k-1);
                                start = binary_search(a, 0, ind_elem - 1, k-1);
                                printf("%d found at %d!\n", k-1, start);

                                /* start could be ambiguous for repetitive k-1 */
                                if (start < size && a[start] == k-1) { /* there is some ambiguity */
                                        start = bounday_search(a, start, ind_elem, size);
                                }
                        }
                } else { /* we found k at index 0; it must be the start index */
                        start = ind_elem;
                }

                /* find end */
                if (ind_elem + 1 < size) {
                        if (a[ind_elem + 1] != a[ind_elem]) { /* this is a boundary */
                                end = ind_elem + 1;
                        } else {
                                /* search for k+1 */
                                printf("Searching %d!\n", k+1);
                                end = binary_search(a, ind_elem + 1, size - 1, k+1);
                                printf("%d found at %d!\n", k+1, end);

                                /* end could be ambiguous for repetitive k+1 */
                                if (end < size && a[end] == k+1) {
                                        end = bounday_search(a, ind_elem + 1, end, size);
                                }
                        }
                } else { /* we found k at index size; it must be the end index for k */
                        end = ind_elem + 1;
                }

                print_arr(a, start, end - 1);
        } else {
                printf("Element not found!\n");
        }
}

