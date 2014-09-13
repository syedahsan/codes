#include<iostream>
using namespace std;

int *pointer(int p)
{
	int *a;
	a = &p;
	return a;

}

int main(void)
{
	int p = 100;
	int *a;
	a = pointer(p);
	cout << a << " " << *a << endl;

}
