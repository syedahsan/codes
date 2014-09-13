/*#include <stdio.h>
main()
{
	char str[] ="abcdef";
	printf("str is %s",str);
	str = "DESIS";
	printf("str is %s",str);
}*/
/*#include <stdio.h>
main()
{
	int i = 10;
	printf(" %d %d %d \n", ++i, i++, ++i);
}
*/

/*#include <stdio.h>
void fun(int, int*);
main()
{
	int j,i;
	int * intptr;
	printf("enter an integer\n");
	scanf("%d",&i);
	intptr = &j;
	j = i;
	printf("i and j are %d %d \n",i,j);
	fun(j,intptr);
	printf("i is:%d",i);
	printf("\n j is:%d",j);
}
void fun(int k, int *iptr)
{
	k++;
	(*iptr)++;
	return;
}*/

/*main()
{
	int x;
	x = printf("%d ",x=printf("%d ",100));
	printf("%d\n",x);
}
*/

/*#include <stdio.h>
main()
{
	int i;
	char c;
	for (i=0;i<5;i++){
		scanf("%d",&c);
		printf("%d",i);
	}
}
*/

/*#include<stdio.h>

main()
{
	auto int i = 0;
	printf("%d\n",i);

	{
		int i = 2;
		printf("%d\n",i);
		{
			i+=1;
			printf("%d\n",i);
		}
		printf("%d\n",i);
	}
	printf("%d\n",i);
	printf("%d\n",reset());
	printf("%d\n",ret10());
	printf("%d\n",reset());
	printf("%d\n",ret10());
}


int reset()
{
	int j = 0;
	return(j);
}

int ret10()
{
	static int i = 10;
	i+=1;
	return(i);
}*/

/*#include <stdio.h>
#include<string.h>
main()
{
	struct emp1
	{
		char *name;
		int age;
	};
	struct emp2
	{
		char *cp;
		struct emp1 e1;
	}e2 = {"ghi",{"jkl",123}};

	struct emp1 e3 = {"rwer",2341};
	printf("\n%s %d\n",e3.name,e3.age);
	printf("\n%s %s %d\n",e2.cp,e2.e1.name,e2.e1.age);
}
*/
/*
#include <stdio.h>
struct xyz
{
	int xyz ;
}
;

main()
{
	union xyz
	{
		int xyz;
	}
	;
}*/

/*#include<stdio.h> 

struct foo 
{ 
	char c; 
	long l; 
	char *p; 
}; 

union bar 
{ 
	char c; 
	long l; 
	char *p; 
}; 

int main(int argc,char *argv[]) 
{ 
	struct foo myfoo; 
	union bar mybar; 

	myfoo.c = 1; 
	myfoo.l = 2L; 
	myfoo.p = "This is myfoo"; 

	mybar.c = 1; 
	mybar.l = 2L; 
	mybar.p = "This is mybar"; 

	printf("myfoo: %d %ld %s\n",myfoo.c,myfoo.l,myfoo.p); 
	printf("mybar: %d %ld %s\n",mybar.c,mybar.l,mybar.p); 

	return 0; 
} 
*/
/*#include<stdio.h>
main()
{
	char s[] = "Bouquets and Brickbats";
	printf("\n%c, ",*(&s[2]));
	printf("%s, ",s+5);
	printf("\n%s",s);
	printf("\n%c",*(s+2));
}
*/

/*#include <stdio.h>
struct s
{
	char *st;
	struct s *sptr;
};
main()
{
	int i;
	struct s *p[3];
	static struct s a[]={
		{"abcd",a+1},
		{"pqrs",a+2},
		{"stuv",a}
	};
	for( i=0;i<3;i++ )
		p[i] = a[i].sptr;
	swap(*p,a);
	printf("%s %s %s \n",p[0]->st,(*p)->st, (*p)->sptr->st);
}

swap(p1,p2)
	struct s *p1,*p2;
{
	char *temp;
	temp = p1->st;
	p1->st = p2->st;
	p2->st = temp;
}
*/

/*#include <stdio.h>
Swap( int *x , int *y)
{
	int tmp = *x ;
	*x = *y ;
	*y = tmp;
}
main()
{
	int a = 1, b = 2;
	Swap(&a, &b);
	printf("%d %d\n", a, b);
}*/

/*#include <stdio.h>
main()
{
	int i;
	scanf("%d",&i);
	switch(i) {
		printf("\nHello");
		case 1: printf("\none");
			break;
		case 2: printf("\ntwo");
			break;
	}
}*/

/*#include<stdio.h>
main()
{
	 int x;
	  x = 3;
	   f(x);
	    printf("MAIN");

}

f(int n)
{
	 printf("F");
	  if (n != 0)
		    f(n-1);
}
*/

/*#include <stdio.h>
main()
{
	 int ptr[] = {1,2,23,6,5,6};
	  char str[] = {'a','b','c','d','e','f','g','h'};

	   printf("pointer differences are %d, %d",&ptr[3], &ptr[0]);
}*/

/*#include <stdio.h>
main()
{
	 char a,b,c;
	  scanf("%c %c %c",&a,&b,&c);
	   printf("%c %c %c ", a, b, c);
	    }
*/

/*#include <stdio.h>
#define PRINT(int) printf( "int = %d ", int)
main()
{
	int x=03,y=02,z=01;
	PRINT (x | y & ~z);
	PRINT (x & y && z);
	PRINT (x ^ (y & ~z));
}*/

/*#include <stdio.h>
main()
{
	int a = 10000;
	char b='c';
	int i,j;

	printf("%d,%d",printf("%d\n",a),printf("%c\n",b));
}
*/

/*#include <stdio.h>
#define PR(a)   printf("%d\t",(int) (a));
#define PRINT(a,b,c) PR(a);PR(b);PR(c);
#define MAX(a,b) (a<b?b:a)
main(){
	int x = 1,y = 2;
	PRINT(MAX(x++,y),x,y);
	PRINT(MAX(x++,y),x,y);
}*/
/*
#include <stdio.h>
main()
{
	 unsigned int i=1;
	  for(;i>=0;i--)  printf("hello: %u\n",i);
}*/

/*#include <stdio.h>
main()
{
	 struct ist{
		   int x;
		     int y;
	 };

	  struct list{
		    int x;
		      struct ist next;
		       }head;
	    head.x = 100;
	      head.next.x=10;
	        printf("%d %d", head.x,head.next.x);
}
*/
/*#include<stdio.h>
main()
{
	typedef union
	{
		struct
		{
			char c1,c2;
		} s;
		long j;
		float x;
	} U;

	U example;
	example.s.c1 = 'a';
	example.s.c2 = 'b';
	example.j = 5;
	printf("%c %c %d", example.s.c1, example.s.c2, example.j);
}
*/
/*
#include <stdio.h>
main()
{
	 struct s1
		  {       char *str;
			    struct s1 *ptr;
			     };
	  static struct s1 arr[] = { {"Hyderabad",arr+1},{"Bangalore",arr+2},
		  {"Delhi",arr}};
	   struct s1 *p[3];
	    int i;

	     for(i=0;i<=2;i++)
		       p[i] = arr[i].ptr;

	      printf("%s\n",(*p)->str);
	       printf("%s\n",(++*p)->str);
	        printf("%s\n",((*p)++)->str);
}
*/

/*#include <stdio.h>
main()
{
	char input[] = "SSSWILTECH1\1\1";
	int i, c;
	for ( i=2; (c=input[i])!='\0'; i++){
		switch(c){
			case 'a': putchar ('i'); continue;
			case '1': break;
			case 1: while (( c = input[++i]) != '\1' && c!= '\0');
			case 9: putchar('S');
			case 'E': case 'L': continue;
			default: putchar(c);continue;
		}
		putchar(' ');
	}
	putchar('\n');
}
*/

/*#include <stdio.h>
main()
{
	int i, n, m, b, x[25];
	int f1(int, int, int j[25]);
	for(i=0;i<25;i++) x[i] = i;
	i=0; m = 24;
	b=f1(i, m, x);
	printf("res %d\n",b);
}

int f1( int p, int q, int a[25])
{
	int m1,m2;
	if (q==0)
		return(a[p]);
	else
	{ 
		m1 = f1 (p, q/2, a);
		m2 = f1(p+q/2+1,q/2,a);
		if(m1<m2)
			return (m2);
		else
			return(m1);
	}
}
*/

/*#include <stdio.h>
main()
{
	unsigned int m[] = { 0x01,0x02, 0x04, 0x08,0x10, 0x20, 0x40, 0x80};
	unsigned int n,i;
	printf("%d",m[7]);
	scanf("%d",&n);
	for(i=0;i<=7;i++)
	{  if (n& m[i])
		printf("\nyes");
		else
			printf("\nno");
	}
}*/

/*#include <stdio.h>
main()
{
	int a,b=2,c;
	int *pointer;
	c = 3;
	pointer = &c;
	a = c pointer;
	b = c  assigning 3 to b;
	printf("a = %d; b = %d", a,b);
}*/

/*#include <stdio.h>
main()
{
	 int i ;
	  i = 1;
	   i= i+2*i++;
	    printf("i is now %d",i);
}*/

/*#include <stdio.h>
#define MAX(x,y) (x) >(y)?(x):(y)
main()

{
	 int i=10,j=5,k=0;
	  k=  MAX(i++,++j);
	   printf("%d..%d..%d",i,j,k);
}
*/
/*#include<stdio.h>
main()
{
	 const int i = 100;
	  int p = 200;
	   i = p;
	   //i=100;
	    printf("%d\n",i);

}*/

/*static int count;
void f(int n)
{
	int i;
	for(i =1;i<=n;i++)
		f(n-i);
	count++;
}
main()
{

	f(5);
	printf("%d",count);
}
*/

/*#include <stdio.h>
void test(int , int *);
main()
{
	 int * iptr, j, k = 2;
	  iptr = &j;
	   j = k;
	    printf( "%d %d ", k, j);
	     test(j, iptr);
	      printf("%d %d\n", k, j);
}
void test(int l, int *p)
{
	 l++;
	  (*p)++;
}*/

/*#include <stdio.h>
main()
{
	 char a= 'A';
	  if( (a=='Z')||( (a='L')&&( a=='A')))
		    a=a;
	   printf("%c",a);
	    printf(" Nothing ");
}
*/

/*#include <stdio.h>
int myfunc(char *str)
{
	 char *ptr =str;
	  while(*ptr++);
	   return ptr-str-1;
}
main()
{
	 printf("%d", myfunc("DESIS"));
}
*/

/*#include <stdio.h>
main(int sizeofargv, char *argv[])
{
	 while(sizeofargv)
		   printf("%s ",argv[--sizeofargv]);
}
*/

/*#include <stdio.h>
main()
{
	 int x,y=1,z;
	  if(x=z=y); x = 3;
	   printf("%d %d %d\n",x,y,z);
	    while (y<4) x+=++y;
	     printf("%d %d\n",x,y);
}
*/

/*#include <stdio.h>
main()
{
	union {
		long l_e;
		float f_e;
	} u;

	long l_v;
	float f_v;
	l_v = u.l_e = 10;
	printf("%f ", (float)l_v);
	printf("%f ", u.f_e);
	f_v = u.f_e = 3.555;
	printf("%d ", (long)f_v);
	printf("%d ", u.l_e);
}
*/

/*#include <stdio.h>
main()
{
	 char a[5] = "abcd";
	  int b = 3;

	   printf("%c\n",a[b]);
	    printf("%c\n",b[a]);
}
*/

/*#include <stdio.h>
#define PRINTIFLESS(x,y) if((x) < (y)) printf("First is smaller");else
main()
{
	 int i = 2, k =1;
	  if(i>0 && k>0) PRINTIFLESS(i,k);
	   else  printf("Numbers not greater than 0\n");

}
*/

/*#include <stdio.h>
#include<malloc.h>
main()
{
	int *iptr,*dptr, i;
	dptr = malloc(sizeof(i));
	iptr =&i ;
	*iptr = 10;
	//free(iptr);
	*dptr = 20;
	dptr = iptr;
	free(dptr);
	printf("%d,%d,%d",*dptr,*iptr,i);
}*/

/*#include <stdio.h>
main()
{
	char ch = 'A';
	while(ch <='F'){
		switch(ch){
			case 'A':case 'B':case 'C': case 'D': ch++; continue;
			case 'E': case 'F': ch++;
		}
		putchar(ch);
	}
}
*/

/*#include <stdio.h>

f(int x,int *y)
{
	x=*(y)+=2;
}

main()
{
	static int a[5] = {2,4,6,8,10};
	int i,b=5;
	for(i=0; i< 5;i++){
		f(a[i],&b);
		printf("%d %d\n",a[i],b);
	}
}*/

/*#include <stdio.h>
main()
{
	FILE *fp1,*fp2;
	fp1 = fopen("one","w");
	fp2 = fopen("one","w");
	fputc('A',fp1);
	fputc('B',fp2);
	fclose(fp1);
	fclose(fp2);
}
*/

/*#include <stdio.h>
main()
{
	int a = 0xff;
	if(a<<4>>12)
		printf("Right");
	else
		printf("Wrong");
}*/

/*#include <stdio.h>
main()
{
	 enum _tag{ left=10, right, front=100, back};
	  printf("left is %d, right is %d, front is %d, back is %d",left,right,front,back);
}*/

/*#include <stdio.h>
main()
{
	 char *arr = "This is to test";
	  printf("\n%c %c ",*(arr), *(arr++));

}*/
/*#include<stdio.h>
main()
{
	 int I =-3, j=2, k = 0,m;
	  m = ++I && ++j && ++k;
	   printf("\n%d %d %d %d", I, j, k, m);
}
*/
/*#include <stdio.h>
#define PR(a)   printf("a = %d\t",(int) (a));
#define PRINT(a)  PR(a); putchar('\n');
#define FUDGE(k)        k + 3.14

main()
{
	 int x = 2;
	  PRINT( x * FUDGE(2));
}*/

/*#include <stdio.h>
main()
{
	int i = 3,j;
	j = add(++i);
	printf("i = %d *p= %d\n", i, j);
}

add(ii)
	int ii;
{
	ii++;
	printf("ii = %d\n", ii);
}*/

/*#include <stdio.h>
#define DEBUG(args) (printf("DEBUG: "), printf args)

main()
{
	int n = 0,i = 0 ;
	printf("%d\n", n);
	if(n != 0) DEBUG(("n is %d\n", n));
	DEBUG(("%d",i));

}
*/

/*#include <stdio.h>
main()
{
	printf("hello");
	fork();
}*/

/*#include <stdio.h>
#include<malloc.h>
#include<string.h>
main()
{
	char *s2, *s1 ;
	//      s1 = malloc(sizeof(char) * 1000);
	s1 = "Hello, ";
	//      s2 = malloc(sizeof(char) * 10);
	s2 = "world!";
	strcat(s1, s2);
	printf("%s", s2);
}*/

/*#include <stdio.h>
#include<string.h>
main()
{
	char *s1 = "alpha", *s2 = "alpha";
	if(!strcmp(s1,s2)) printf("yes\n");
}*/

/*#include <stdio.h>
#define DEBUG(args) (printf("DEBUG: "), printf args)

main()
{
	        int n = 10;
		        if(n != 0) DEBUG(("n is %d\n", n));

}*/

/*#include <stdio.h>
struct
{
	int left,y;
}a;
main()
{
	int i;
	printf("%5d\n",a.left);
}
*/

/*#include <stdio.h>
main()
{
	char c1,c2,c3;
	c1 = getc(stdin);
	putc(c1,stdout);
	putc("\n",stdout);	
	//      c2 = getche();
	//      putc(c2,stdout);
	c3 = getchar();
	putc(c3,stdout);
}*/

/*#include<stdio.h>

struct test{
	int f;
};

struct test* f(struct test * (*fPtr)() )
{
	struct test *ptr = (struct test*) malloc(sizeof(struct test));
	return ptr;
}
main()
{
	printf("%d\n",f(f)->f);
}*/

/*#include <stdio.h>
void print_in_reverse( char *str )
{
	if( *str == '\0' )
		return;

	print_in_reverse(str+1);

	printf( "%c" , *str );
}
main()
{
	print_in_reverse( "char *str" );
}
*/

/*#include <stdio.h>
#include<math.h>
#define sqrt(x) (( x < 0) ? sqrt(-x) : sqrt(x))
main()
{
	int y;
	y = sqrt(-9);
	printf("%d",y);

}*/

/*#include <stdio.h>
#define MAXI 100
main(){
	int done,i,x=6;
	done=i=0;
	for(i = 0; (i< MAXI) && (x/=2)>1; i++)
		done++;
	printf("%d %d\n",i,done);
}
*/

/*
#include <stdio.h>
main()
{

	char    as[] = "\0/";
	printf("%c%c%c",as[0],as[1],as[2]);

	int     i = 0;
	do{
		switch( as[i++]){
			case '\\' : printf("A");
				    break;
			case 0   : printf("B");
				   break;
			default : printf("C");
				  break;
		}
	}
	while(i<3);
}
*/

/*#include <stdio.h>
main()
{
	struct emp
	{       char name[20];
		float age;
		float sal;
	};
	struct emp e = {"Tiger"};
	printf("\n%f",e.age);
}*/

/*#include <stdio.h>
main()
{
	char str[] = "Taj is 2 miles away";
	int i;
	for(i=0;i<19;++i)
		if(isalpha(str[i]))printf("%c",toupper(str[i]));
	char  *p = "tuns";
	p++;
	printf("%s\n",p);
}
*/
/*#include <stdio.h>
#define abs(x) x>0?x:-x
#define mabs(x) (((x)>=0)?(x):-(x))
int kabs(int);
main()
{
	printf("\n%d   %d",abs(10)+1,abs(-10)+1);
	printf("\n%d   %d",mabs(10)+1,mabs(-10)+1);
	printf("\n%d   %d\n",kabs(10)+1,kabs(-10)+1);
}
int kabs(int n)
{
	return(n>0? n: -n);

}*/

/*#include <stdio.h>
main()
{
	union
	{
		int a;
		int b;
		double  d;
	}c;
	c.a=10;
	c.d = 1.00000;
	printf("test %d\n",c.a);
}
*/

/*#include <stdio.h>
main()
{
	int a;

	a = (1,2,3,4,5,1,45,012,1230);

	printf("%d", a);
}*/

/*#include <stdio.h>
main()
{
	int a=10,b;
	b=a>=5?100:200;
	printf("%d\n",a);
}
*/
/*#include<stdio.h>
#define DESHAWCURRENTDEBUGLEVEL 0
void main(void)
{
	int i = 10 ;
	int j = 15 ;

#ifdef DESHAWCURRENTDEBUGLEVEL
	printf("%d\n",i);
#else
	printf("%d\n",j);
#endif
}
*/
/*#include<stdio.h>
main()
{
	int i;
	char c;
	for (i=0;i<5;i++){
		scanf("%d",&c);
		printf("%d",i);
	}
}
*/

/*#include<stdlib.h>
#include<ctype.h>
main()
{
	int *p, *c, i;
	i = 5;
	p = malloc(sizeof(i));
	printf("\n%d",*p);
	*p = 10;
	printf("\n%d  %d",i,*p);
	c = calloc(2,i);
	printf("\n%d\n",*c);
}
*/
/*#include <stdio.h>
main()
{
	char *pk;
	const char* p;
	const char c = 'a';
	char c1='b';
	p=&c1;
	pk = &c;
	printf("%c %c",*pk,*p);
}
*/

/*#include <stdio.h>
int *NEXT( int  i)
{
	int *ipt;
	ipt = &i;
	ipt++;
	return ipt;
}

main ()
{
	int j;
	printf("%d",(NEXT(j)));
}
*/
/*
#include <stdio.h>
main()
{
	struct test
	{
		char c;
		long int i[2];
		char m;
	} t1;
	printf("%d %d\n",sizeof(t1), sizeof(t1.c));
}
*/
/*#include <stdio.h>
main()
{
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%d\n", a+++++b);
	printf("%d %d\n",a,b);
}
*/
/*
#include <stdio.h>
funct(char* str)
{
	printf("%s\n",str);
}

main()
{
	static  int  ii = 1;
	int jj = 5;
	ii+=++jj;
	funct( 7+ "Campus Interview" );
}
*/
/*
#include <stdio.h>
funct(str,k)
{
	printf("%d %d\n",str,k);
}

main()
{
	funct(10,7);
}
*/
/*#include<stdio.h>
int main()
{
	char a = 2,c=1024;
	printf("%d",c);
	return(0);
}*/

/*#include<stdio.h>
main()
{
	int i=4;
	printf("%d %d %d",++i,i++,++i*++i);
}
*/

/*#include<stdio.h>
#include<stdlib.h>
main()
{
	        int*ptr=(int*)malloc(sizeof(int));
		        *ptr=4;
			        printf("%d",(*ptr)+++*ptr++);
}
*/

/*#include<stdio.h>
main()
{
	int a=1,b=3,c,d;
	c=(a,b);
	d=a,b,c;
	printf("%d %d",c,d);
	printf("%d\n%d",++b,++b*++b);
}
*/

/*#include<stdio.h>
main()
{
	char c='6';
	int d=6;
	printf("%d %d %d",d,d+=c>'0'&&c<='7',c++);
}
*/
/*#include<stdio.h>
main()
{
	int a=4,b=2;
	a=b<<a + b>>2;
	printf("%d\n",a);
	b=b<<a;
	printf("%d %d",a,b);
}*/

/*#include<stdio.h>
main()
{
	int i=98765;
	printf("%d\n",printf("%d",printf("%d",i)));
}
*/

/*#include<stdio.h>
main()
{
	char c;
	while(c=getchar()!='a')printf("%d",c);
}*/

/*#include<stdio.h>
main()
{
	        int *i=65;
		        printf(" %p\n",i);
}
*/
/*#include<stdio.h>
#include<stdlib.h>
main()
{
	        int *ptr=(int*)malloc(sizeof(int));
		        *ptr=4;
			        printf("%d",(*ptr)+++*ptr++);
}*/
/*#include<stdio.h>
int main()
{
	int a=1;
	switch(a)
	{   int b=20;
		case 1: printf("b is %d\n",b);
			break;
		default:printf("b is %d\n",b);
			break;
	}
	return 0;
}*/
/*#include<stdio.h>
#include<string.h>
int s(char*A[20],char*B[20])
{
	        char *a,*b;
		        a=A,b=B;
			        while(*a++!=*b++);
				        *a=*b='\0';
				        return strlen(A);
}

int main()
{
	        char A[20]="somestring",B[20]="debugthecbug";
		        printf("%d %s %s\n",s(&A,&B),A,B);
			        return 0;
}
*/

/*#include<stdio.h>
#include<stdlib.h>
void weird(int*a)
{
	a=(int*)malloc(sizeof(int));
}
main()
{
	int*a;
	weird(a);
	*a=6;
	printf("%d\n",*a);
}
*/

/*#include <stdio.h>
main()
{
	int a=4,b=10;
	printf("%d %d %d %d\n",a,a^=b=b^=a=a^=b,b,printf("%d %d %d\n",
				b,a,a^=b=b^=a=a^=b));
}*/
#include<stdio.h>
int fun1();
int fun2()
{
	static int c=1;
	return fun1()+c--;
}
int fun1()
{
	static int c=20;
	return --c;
}


int main()
{
	int i=0;
	while(i<fun2())
		printf("%d ",i++);
	return 0;
}
