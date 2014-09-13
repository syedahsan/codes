/* Given a sorted array and a number K, check if we can find two numbers whose sum is K */

#include <stdio.h>

#define LEN 10

void check_sum_k(int arr[LEN], int k)
{
        int i = 0, j = LEN - 1;
        while (i < j) {
                if (k - arr[j] > arr[i])
                        i++;
                else if (k - arr[j] < arr[i])
                        j--;
                else
                        break;
        }

        if (i >= j)
                printf("Unable to find such two numbers.\n");
        else
                printf("(%d, %d)\n", i+1, j+1);

        return;
}

void print_arr(int arr[LEN])
{
        int i;
        for (i = 0; i < LEN; i++)
                printf("%d, ", arr[i]);
        printf("\n");
}

int main()
{
        int k;
        int arr[LEN] = {2, 4, 5, 6, 9, 11, 12, 17, 19, 23};

        scanf("%d", &k);

        print_arr(arr); /* debug */
        check_sum_k(arr, k);
}
