#include<iostream>
using namespace std;

class exforsys
{
	public:
		exforsys(void) { x=0; }
		 void f(int n1)
		{
			x= n1*5;
		}

		void output(void) { cout << "X is" <<  x << endl;; }

	private:
		int x;
};

class sample: public exforsys
{
	public:
		sample(void) { s1=0; }

		void f1(int n1)
		{
			s1=n1*10;
		}

		virtual void output(void)
		{
			//exforsys::output();
			cout << "s1" << s1 << endl;
		}

	private:
		int s1;
};

int main(void)
{
	exforsys *s;
	s = new sample();
	s->f(10);
	s->output();
	s->f(20);
	s->output();
}

