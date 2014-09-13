#include <iostream>
using namespace std;
class example
{
	private:
		static int sum;            //Static data
		int x;
	public:
		example()                  //Constructor of the class
		{
			sum=sum+1;
			x= sum;
		}

		~example()                //Destructor of the class
		{
			sum--;
		}

		static virtual void exforsys()       
			//Static function exforsys( ) defined with keyword static
		{
			cout<<"\nResult is: "<< sum ;
		}

		void number()            //Normal member function number( )
		{
			cout<<"\nNumber is: "<<x; 
		}
};


int example::sum;
int main()
{
	example::number();
	//example e1;
	example::exforsys();
	e1.exforsys();
	//Static function exforsys() accessed using class name example and the scope resolution operator ::
	example e2,e3,e4;
	example::exforsys();
	e1.number();
	//Normal member function accessed using object e1 and the dot member access operator.
	e2.number(); 
	e3.number();
	e4.number();
	
}

