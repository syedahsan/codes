#include <stdio.h>

#define SIZE 100000
#define NUM_CHILD 10

int Hash[SIZE];

int lca(int a[], int n, int b[], int m)
{
        int i, j;
        for (i = 0; i < m; ++i) {
                j = b[i];
                while(1) {
                        Hash[j] += 1;
                        if (Hash[j] == m)
                                return (j);
                        j = a[j];
                        if (j == -1)
                                break;
                }
        }

        return (0);
}

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a[SIZE];
    int b[SIZE];
    int N;
    int i;
    int M;
   
    a[0] = -1;
    scanf("%d", &N);
    for (i = 1; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &M);
    for (i = 0; i < M; ++i) {
            scanf("%d", &b[i]);
    }

    int i_lca = lca(a, N, b, M);
    printf("%d\n", i_lca);

    return 0;
}
