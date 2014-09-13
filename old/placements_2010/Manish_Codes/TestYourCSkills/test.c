#include<stdio.h>
#include<malloc.h>
main()
{
	char *str1="abcd";
	char str2[]="abcd";
	printf("%d %d %d",sizeof(str1),sizeof(str2),sizeof("abcd"));

}

