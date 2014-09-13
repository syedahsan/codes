#include<stdio.h> 
main() 
{ 
	int *i = 10 , *j=20; 
	i=((int)i*(int)j);
       printf("%d\n",i);	
/*	int oldvar=80,newvar=-80; 
	int swap(int,int); 
	swap(oldvar,newvar); 
	printf("numbers are %d\t%d",newvar ,oldvar);*/ 
} 
int swap(int olval,int neval) 
{ 
	int temval=olval; 
	olval=neval; 
	neval=temval; 
} 
