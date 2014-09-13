#include<stdio.h>
main()
{
	int num = 2;
	num = num << 2;	printf("%d\n", num);
	/*if(*(char *)&num == 1)
	{
		printf("\nLittle-Endian\n");
	}
	else 
	{
		printf("Big-Endian\n");
	}*/
}
