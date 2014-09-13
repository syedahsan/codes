#include<iostream>
#include<cstdio>
main()
{
	/*int *p,*q,r; 
	int values[30]; 
	p=&values[0]; 
	q=values+29; 
	r=++q-p; 
	std:: cout << r << std::endl;*/

	static int i =5; 
	float sum=0.0; 
	do 
	{ 
		sum+=(1/i); 
	}while(0<i--); 
	printf("sum of the series is %f",sum); 
}
