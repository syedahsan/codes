#include<iostream>
using namespace std;

int main(void)
{
	union a
	{
		int i;
		char ch[2];
	};
	union a z;
	z.i = 2;
	z.ch[0] = '2';
	cout << z.ch[0] << " " << z.ch[1] << endl;	
}

