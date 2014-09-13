#include<iostream>
#include<cstring>
#include<new>
#include<cstdio>
#include<malloc.h>
using namespace std;

/*class Sample
{
	public:
		int *ptr;
		Sample(int i)
		{
			ptr = new int(i);
		}
		~Sample()
		{
			delete ptr;
		}
		void PrintVal()
		{
			cout << "The value is " << *ptr;
		}
};
void SomeFunc(Sample &x)
{
	cout << "Say i am in someFunc " << endl;
}
int main()
{
	Sample s1= 10;
	SomeFunc(s1);
	s1.PrintVal();
	}*/

/*class base
{
	public:
		int bval;
		base(){ bval=0;}
		};

		class deri:public base
		{
		public:
		int dval;
		deri(){ dval=1;}
		};
		void SomeFunc(base *arr,int size)
		{
		for(int i=0; i<size; i++,arr++)
		cout<<arr->bval;
		cout<<endl;
		}

		int main()
		{
		base BaseArr[5];
		SomeFunc(BaseArr,5);
		deri DeriArr[5];
		SomeFunc(DeriArr,5);
		}*/


/*class base
{
	public:
		virtual void baseFun(){ cout<<"from base"<<endl;}
};
class deri:public base
{
	public:
		void baseFun(){ cout<< "from derived"<<endl;}
};
void SomeFunc(base *baseObj)
{
	baseObj->baseFun();
}
int main()
{
	base baseObject;
	SomeFunc(&baseObject);
	deri deriObject;
	SomeFunc(&deriObject);
	}*/

/*int main()
{
	int a, *pa, &ra;
	pa = &a;
	&ra = a;
	cout <<"a="<<a <<"*pa="<<*pa <<"ra"<<ra ;
}*/



/*class fig2d
{
	int dim1;
	int dim2;

	public:
	fig2d() { dim1=5; dim2=6;}

	virtual void operator<<(ostream & rhs);
};

void fig2d::operator<<(ostream &rhs)
{
	rhs <<this->dim1<<" "<<this->dim2<<" ";
}

class fig3d : public fig2d
{
	int dim3;
	public:
	fig3d() { dim3=7;}
	virtual void operator<<(ostream &rhs);
};
void fig3d::operator<<(ostream &rhs)
{
	fig2d::operator <<(rhs);
	rhs<<this->dim3;
}


int main()
{
	fig2d obj1;
	fig3d obj2;

	obj1 << cout;
	obj2 << cout;
}*/

/*class opOverload{
	public:
		bool operator==(opOverload temp);
};

bool opOverload::operator==(opOverload temp){
	if(*this  == temp ){
		cout<<"The both are same objects\n";
	//	return true;
	}
	else{
		cout<<"The both are different\n";
	//	return false;
	}
}

int main(){
opOverload a1, a2;
a1==a2;
}*/


/*class complex{
	double re;
	double im;
	public:
	complex() : re(1),im(0.5) {}
	bool operator==(complex &rhs);
	operator int(){}
};

	*bool complex::operator == (complex &rhs){
		if((this->re == rhs.re) && (this->im == rhs.im))
			return true;
		else
			return false;
	}

int main(){
	complex  c1;
	cout<<  c1;
}
*/

/*class complex{
	double re;
	double im;
	public:
	complex() : re(0),im(0) {}
	complex(double n) { re=n,im=n;};
	complex(int m,int n) { re=m,im=n;}
	void print() { cout<<re; cout<<im;}	
};

int main(){
	complex c3;
	double i=5;
	c3 = i;
	c3.print();
}
*/

/*class base
{  
	public : 
		 void out() 
		{ 
			cout<<"base ";  
		}  
};
	class deri{ 
		public : void out() 
			 { 
				 cout<<"deri "; 
			 }   
	};
int main()
{ 	deri dp[3];
	base *bp = (base*)dp;
	for (int i=0; i<3;i++)
		(bp++)->out();
}*/

/*class Shape {
	public:
		Shape() { };
		void draw() {
			cout << "Prafull" << endl;
		}
};

class Circle : public Shape {
	public:
		int m_iRadius;
		Circle(int iRadius){ m_iRadius = iRadius; }
		 void draw() {
		       cout << "Manish" << endl;	
		}
		int GetRadius(){ return m_iRadius; }
};

void funcx(Shape *shape) {
       shape->draw();
       //cout << (Circle)shape->GetRadius() << endl;
}

int main()
{
	Circle circle(2);
	Shape *s=&circle;
	s->draw();
	funcx(&circle);
}
*/
/*class sample;

class test
{
	public :
		 void fun ( test,sample ) ;
} ;

class sample
{
	public :
		 void fun ( test, sample ) ;

} ;


void fun ( test t,sample s)
{
	// code
}
int main( )
{
	test t;
	sample s;
	fun (t, s);
}
*/

/*class circle
{
	private:
		int radius;
	public:
		circle(int r=0)
		{
			cout << r << endl;
			radius = r;
		}
};

class rectangle
{
	private:
		int length;
		int breadth;
	public:
		rectangle(int l, int b)
		{
			length = l;
			breadth = b;
		}
		operator circle()
		{
			return circle(length);
		}
};

int main()
{
	rectangle r(20,10);
	circle c;
	c = r;
}*/


/*class date
{
	private :
		int day ;
		int month ;
		int year ;
	public :
		date ( int d = 0, int m = 0, int y = 0 )
		{
			day = d ;
			month = m ;
			year = y ;
		}
		// copy constructor
		date ( date &d )
		{
			day = d.day ;
			month = d.month ;
			year = d.year ;
		}
		// an overloaded assignment operator
		date operator = ( date d )
		{
			day = d.day ;
			month = d.month ;
			year = d.year ;
			return d ;
		}
		void display( )
		{
			cout << day << "/" << month << "/" << year ;
		}
} ;

int main( )
{
	date d1 ( 25, 9, 1979 ) ;
	date d2 = d1 ;
	date d3 ;
	d3 = d2 ;
	d3.display( ) ;
}
*/

/*
class base
{
	protected :
		int i ;
	public :
		base ( int ii = 0 )
		{
			i = ii ;
			show( ) ;
		}
		virtual void show( )
		{
			cout << "base's show( )" << endl ;
		}
} ;
class derived : public base
{
	private :
		int j ;
	public :
		derived ( int ii, int jj = 0 ) : base ( ii )
	{
		j = jj ;
		show( ) ;
	}
		void show( )
		{
			cout << "derived's show( )" << endl ;
		}
} ;
int main( )
{
	derived dobj ( 20, 5 ) ;
}

 */

/*class sample
{
	private :
		char *str ;
	public :
		sample ( char *s )
		{
			str = new char[strlen(s) + 1];
			strcpy ( str, s ) ;
		}
		~sample( )
		{
			delete str ;
		}
} ;
int main( )
{
	sample s1 ( "abc" ) ;
}
*/
/*#pragma pack ( 1 )
class user
{
	int i ;
	float f ;
	char c ;
	public :
	void displaydata( )
	{
		cout << endl << i << endl << f << endl << c ;
	}
} ;
int main( )
{
	cout << sizeof ( user ) ;
	user u1 ;
	cout << endl << sizeof ( u1 ) ;
	u1.displaydata( ) ;
}
*/

/*int main( )
{
	int i = 65000 ;
	int *iptr = reinterpret_cast ( i ) ;
	cout << endl << iptr ;
	iptr++ ;
	cout << endl << iptr ;
	i = reinterpret_cast ( iptr ) ;
	cout << endl << i ;
	i++ ;
	cout << endl << i ;
}
*/

/*int main( )
{
	const int a = 0 ;
	//int *ptr = &a ; //one way
	int *ptr = const_cast_ ( &a ) ; //better way
}*/

/*class b
{
	public :
		int i ;
	public :
		void fun( )
		{
			i = 0 ;
		}
} ;
class d1 : virtual  public b
{
	public :
		void fun( )
		{
			i = 1 ;
		}
} ;
class d2 : virtual  public b
{
	public :
		void fun( )
		{
			i = 2 ;
		}
} ;
class multiple : public d1, public d2
{
	public :
		void fun( )
		{
			i = 10 ;
		}
} ;
int main( )
{
	multiple d ;
	d.fun( ) ;
	cout << d.i ;
}

*/

/*class sample
{
	int i ;

	public :
	sample ( )
	{
		i = 10 ;
	}
	operator int( )
	{
		return this -> i ;
	}
} ;
int main( )
{
	sample s ;
	int i ;
	i = s + 10 ;
	cout << i ;
}
*/

/*class emp
{
	private :
		int i ;
	public :
		emp( )
		{
			i = 10 ;
		}
} ;
int main( )
{
	emp *p = new emp ;
	int *pi = (int*) p ;
	cout << *pi ;
	*pi = 20 ;
	cout << *pi ;
}*/

/*int flag = 0;


void operator delete(void* p, int i)
{
	flag = 1;
}

void* operator new(size_t s, int i)
{
	return new char[s];
}

class A {
	public:
		A() {throw -37;}
};

int main()
{
	try {
		A* p = new (1234) A;
	}
	catch (int i) {
	}
	if (flag == 0)
		cout << "manu" << endl;
	else
		cout << "loku" << endl;
}

*/

/*class A {
	private:
		int i;
	public:
		A()
		{
			i = 6;
		}
		virtual ~A()
		{
			cout << "Manish" << endl;
		}
};

class B: public A {
	private:
		int j;
	public:
		B()
		{
			j = 8;
		}
		~B()
		{
			cout << "Lokesh" << endl;
		}
};

int main(void)
{
	A *a = new B();
	a->~B();
}*/

/*class A {
	public:
		A()
		{
			cout << "Kavita" << endl;
		}
		virtual ~A()
		{
			cout << "Manish" << endl;
		}
};
class B :public A {
	int *p;
	public:
		B()
		{
			cout << "Anita" << endl;
		}
		~B()
		{
			cout << "Lokesh" << endl;
		}
};

int main()
{
	A *b = new B;
	delete b;
}
		
*/

/*class base
{
	public:
		~base(){}
};

class derived:public base
{
	int *p;
	public: 
	~derived()
	{
		delete p;
	}
};

main()
{ 
	base *b = new derived;
	delete b;
}*/

/*int main()
{
	char example[100] ="Strings are good";
	memcpy(example+11,example+8,4);
	cout << example << endl;
}*/

/*class abc
{
	public :
		int main()
		{
			cout<<" Its main function "<< endl;
			return 5;
		}
};
int main(int c, char **v)
{
	abc a;
	if(c<1)
	{
		cout<<" Error can not accept it ";
	}
	cout<<" its in main program " << a.main() << endl;
}*/

/*int main()
{
	char i;
	scanf("%c",&i);
	printf("%d\n",i);
}*/

/*int main()
{
	return 0;
}*/

/*int manish(int a)
{
	return a;
}

main()
{
	char *p,*q;
	manish(10);
	p=(char *)malloc(25);
	q=(char*) malloc(25);
	strcpy(p,"amazon" );
	strcpy(q,"hyd");
	strcat(p,q);
	printf("%s",p);
}*/

class a{};
main()
{
	cout << >;
}
