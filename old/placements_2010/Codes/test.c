#include <stdio.h>
main()
{
	int i,a[10];
	int *p=a;
	for(i=0; i<10; i++)
		a[i] = 10*i;

	int x = p++;
	printf("%d\n",x);
}
