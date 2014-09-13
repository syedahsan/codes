/* Given an integer array A of size n. Given an integer k < n. Construct an array B, such that
 * B[i] = min{A[i], A[i+1], A[i+2], A[i+3], ……., A[i+k]}
 * Solve in time complexity better than O(nk).
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int
main()
{
        int N, k;
        vector <int> A, B;

        /* Input */
        scanf("%d %d\n", &N, &k);
        while (N--) {
                int temp;
                scanf("%d", &temp);
                A.push_back(temp);
        }

        /* Print A */
        printf("A: ");
        for (vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
                printf("%d ", *it);
        }
        printf("\n\n");

        return 0;
}
