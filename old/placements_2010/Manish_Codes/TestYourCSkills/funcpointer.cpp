#include<iostream>
using namespace std;
int main(void)
{
	extern int fun();
	int(*p)() = fun;
	(*p)();
}
void fun()
{
	cout << "LD Rocks" << endl;
}
