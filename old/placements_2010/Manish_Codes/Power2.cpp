#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	int i;
	cin >> i;
	//if(((~i+1) & i) == i)
	//if((i & (i-1)) == 0)
	if((double)((int)(log(i)*1.0/log(3))) == (log(i)*1.0/log(3)))
	       cout << "Power of 2 it is !!!" << endl;
	else cout << "Not a Power of two !!"<< endl;	
}
