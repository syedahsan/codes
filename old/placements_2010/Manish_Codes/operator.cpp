#include<iostream>
using namespace std;
class Exforsys
{
	private:
		int x;
		int y;

	public:
		Exforsys()                    //Constructor
		{ x=0; y=0; }
		Exforsys(int x1, int y1)
		{ x=x1; y=y1; }

		void getvalue( )             //Member Function for Inputting Values
		{
			cout << " Enter value for x: "; 
			cin >> x;
			cout << "Enter value for y: "; 
			cin>> y;
		}

		void displayvalue( )          //Member Function for Outputting Values
		{
			cout <<"value of x is: " << x <<" value of y is: "<< y << endl;
		}

		Exforsys operator +(Exforsys);
};

Exforsys Exforsys :: operator + (Exforsys e2)
	//Binary operator overloading for + operator defined
{
	int x1 = x+ e2.x;
	int y1 = y+e2.y;
	return Exforsys(x1,y1);
}

int main( )
{
	Exforsys e1,e2,e3;             //Objects e1, e2, e3 created
	cout << "Enter value for Object e1: " << endl;
	e1.getvalue( );
	cout << "Enter value for Object e2: " << endl;;
	e2.getvalue( );
	e3= e1+ e2;                  //Binary Overloaded operator used
	cout << "Value of e1 is: " << e1.displayvalue() << endl;;
	cout << "Value of e2 is: " << e2.displayvalue() << endl;
	cout << "Value of e3 is: " << e3.displayvalue() << endl;
}

