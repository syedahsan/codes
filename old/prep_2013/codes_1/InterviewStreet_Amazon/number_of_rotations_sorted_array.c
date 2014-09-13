#include <stdio.h>

inline int _ceil(double num) {
        return ((num > (int) num) ? (int)(num + 1) : (int)num);
}

/* case of duplicates not handled */
int _num_rotations(int a[], int i, int j)
{
        int size = j - i + 1;
        if (size == 1) /* cant tell whether there are any rotations or not */
                return (0);

        if (size == 2) {
                if (a[i] < a[j])
                        return (0);
                else
                        return (i+1);
        }

        int mid = _ceil(size/2.0);

        if (a[mid] < a[mid-1])
                return (mid);
        if (a[mid] < a[i])
                return (_num_rotations(a, i, mid-1));
        else
                return (_num_rotations(a, mid, j));
}

int num_rotations(int a[], int size)
{
        if (size <= 0) /* errors */
                return (size);

        return (_num_rotations(a, 0, size - 1));
}

int main()
{
        int a[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
        int size = sizeof(a)/sizeof(int);

        printf("Number of Rotations: %d\n", num_rotations(a, size));

        return 0;
}
