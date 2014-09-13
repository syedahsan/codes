#include<iostream>
using namespace std;
int main(void)
{
	extern int fun (float);
	int a;
	a = fun(3.14);
	cout << a << endl;
}

int fun(float aa)
{
	return int(aa);
}
