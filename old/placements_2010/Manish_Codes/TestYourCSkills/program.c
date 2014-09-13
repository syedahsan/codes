#include<stdio.h>
/*int main()
{*/
	/*static int i=5;
	if(--i){
		main();
		printf("%d ",i);
	}*/
	/*	char a[]="12345\0";
		int i=strlen(a);
		printf("here in 3 %d\n",++i);*/
	/*	unsigned giveit=-1;
		int gotit;
		printf("%u ",++giveit);
		printf("%u \n",gotit=--giveit);*/
		/*unsigned int i=10;
		while(i-->=0)
		printf("%u ",i);*/
		/*int a[10];
		printf("%d",*a+1-*a+3);*/
	/*int x=2, y=5, z=6; x=y==z; printf ("%d", x); */
	/* int i=5;
	 	 printf("%d",++i++);*/
	/*	int i=300;
		char *ptr = &i;
		*++ptr=2;
		printf("%d",i);*/
	/*char * str = "hello";
	char * ptr = str;
	char least = 127;
	while (*ptr++)
	least = (*ptr<least ) ?*ptr :least;
	printf("%d",least);*/
	/*	extern int i;
		{ 	int i=20;
			{ 	
				const volatile unsigned i=30; printf("%d",i); 
			}
			printf("%d",i);
		}
		printf("%d",i);
	}	
	int i;*/
/*enum {false,true};

int main()
{
	int i=1;
	do
	{
		i++;
		printf("%d\n",i);
		if(i < 15)
			continue;
			}while(false);
			return 0;
			}*/

/*#include <unistd.h>
int main()
{
	while(1)
	{
		fprintf(stdout,"hello-out");
		fprintf(stderr,"hello-err");
		sleep(1);
	}
	return 0;
	}*/
/*#include <stdio.h>
#define f(a,b) a##b
#define g(a)   #a
#define h(a) g(a)

int main()
{
	printf("%s\n",h(f(1,2)));
	printf("%s\n",g(f(1,2)));
	return 0;
}*/

/*#include<stdio.h>
int main()
{
	int a=10;
	switch(a)
	{
		case '1':
			printf("ONE\n");
			break;
		case '2':
			printf("TWO\n");
			break;
		default:
			printf("NONE\n");
	}
	return 0;
}*/
/*#include <stdio.h>

int main()
{
	float f=0.0f;
	int i;

	for(i=0;i<10;i++)
		f = f + 0.1f;

	if(f == 1.0f)
		printf("f is 1.0 \n");
	else
		printf("f is NOT 1.0\n");

	return 0;
}*/

/*int main()
{
	        int a = 1,2;
		        printf("a : %d\n",a);
			        return 0;
}*/

#include <stdio.h>
int main()
{
	int i=43;
	printf("%d\n",printf("%d",printf("%d",i)));
	return 0;
}











