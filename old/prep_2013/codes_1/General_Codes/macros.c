#include <stdio.h>

#define MAX(a, b) ({            \
        typeof(a) _a = a;       \
        typeof(b) _b = b;       \
        (_a > _b) ? (_a) : (_b);\
        })

int main()
{
        int a, b, c;
        
        scanf("%d %d", &a, &b);
        printf("MAX: %d\n", MAX(a,b));

        c = MAX(a++, b++);
        printf("MAX: |c| %d |b| %d |a| %d\n", c, b, a);

        return 0;
}
