#include<stdio.h>
/*void show_stack_dir(int * p) {
	printf("%s\n", p < (int*)(&p) ? "up" : "down");
}

int main(int argc, char ** argv) {
	show_stack_dir(&argc);
	return 0;
}*/
add(ii)
int ii;
{
	ii++;
	printf("ii = %d\n", ii);
}


main()
{
	/*int i=3;
	while (i--)
	{
		int i=100;
		i--;
		printf("%d..",i);
	}*/
	/* int *p[10];
	          printf("%d %d\n",sizeof(*p),sizeof(p));*/
	//printf("%d\n",printf("%d%d\n",    2,    2) & printf("%d%d\n",   2,2));

/*	int i = 3,j;
	j = add(++i);
	printf("i = %d j= %d\n", i, j);*/
/*	int a[ ] = {10,20,30,40,50},j,*p;
	for(j=0; j<5; j++)
	{
		printf("%d" ,*a);
		a++;
	}
	p = a;
	for(j=0; j<5; j++)
	{
		printf("%d" ,*p);
		p++;
		}*/
	/*int a=9,*p,*q;
		*p=a;q=p;
		printf("%d, %d, %d",p,q,&a);*/

	/*int *p,a=3,*q;
	*p=a;
	q=&a;
	printf("%u %u",p,q);*/


	int *i; 
	//int a = 100;
	*i = 10;
	*i = 20;
	printf("%d\n",*i);


}


