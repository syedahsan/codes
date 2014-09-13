#include<stdio.h>
/*#define AND && 
#define ARRANGE (a>25 AND a<50) 
main() 
{
	int a = 30; 
	if (ARRANGE) 
		printf("within range"); 
	else 
		printf("out of range"); 
}*/

/*#define AREA(x)(3.14*x*x) 
main() 
{float r1=6.25,r2=2.5,a; 
	a=AREA(r1); 
	printf("\n Area of the circle is %f", a); 
	a=AREA(r2); 
	printf("\n Area of the circle is %f", a); 
} */


#define MAX(x,y) ((x)>(y)?(x):y) 
main() 
{ 
	int x=5,y=5; 
	printf("maximum is %d",MAX(++x,++y)); 
} 
