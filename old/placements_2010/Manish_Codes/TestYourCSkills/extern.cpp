#include<iostream>
using namespace std;


int main(void)
{
	extern int i;
	cout << i << endl;
}
int i = 20;
