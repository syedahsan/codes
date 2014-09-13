#include<iostream> 
using namespace std;
class exforsys
{
	private:
		int a,b;
	public:
		void test()
		{
			a=100;
			b=200;
		}
		friend int compute(exforsys e1);

			//Friend Function Declaration with keyword friend and with the object of class exforsys to which it is friend passed to it
};

int compute(exforsys e1)
{
	//Friend Function Definition which has access to private data
	return int(e1.a+e1.b)-5;
}

main()
{
	exforsys e;
	e.test();
	cout<<"The result is:"<<  compute(e) << endl;
		//Calling of Friend Function with object as argument.
}
