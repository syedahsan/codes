#include <stdio.h>

int ways(int n)
{
        if (n <= 0)
                return (0);
        else if (n == 1)
                return (1);
        else if (n == 2)
                return (2);
        else
                return (ways(n-1) + ways(n-2));
}

int main()
{
        int n;
        scanf("%d", &n);
        printf("# of ways to reach floors %d: %d\n", n, ways(n));

        return 0;
}
