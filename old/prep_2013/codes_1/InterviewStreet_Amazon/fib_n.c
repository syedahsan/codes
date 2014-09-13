#include <stdio.h>

void multiply(long long int F[2][2], long long int M[2][2]);

void power(long long int F[2][2], int n);

/* function that returns nth Fibonacci number */
long long int fib(int n)
{
        long long int F[2][2] = {{1,1},{1,0}};
        if(n == 0)
                return 0;
        power(F, n-1);
        return F[0][0];
}

/* Optimized version of power() in method 4 */
void power(long long int F[2][2], int n)
{
        if( n == 0 || n == 1)
                return;
        long long int M[2][2] = {{1,1},{1,0}};

        power(F, n/2);
        multiply(F, F);

        if( n%2 != 0 )
                multiply(F, M);
}

void multiply(long long int F[2][2], long long int M[2][2])
{
        long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
        long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
        long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
        long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
}

int digits(long long int n)
{
        int digits = 0;
        while (n) {
                ++digits;
                n /= 10;
        }

        return (digits);
}

/* Driver program to test above function */
int main()
{
        int i, n;
        scanf("%d", &n);

        for (i = 2; i < 84; ++i) {
                long long int x = fib(i);
                printf("%lld, ", x);
        }
        printf("\n");

        return 0;
}
