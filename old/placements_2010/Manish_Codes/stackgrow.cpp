#include<iostream>
using namespace std;

void stack(int *local)
{
	int local2;
	if(local > &local2)
		cout << "Stack is growing downwards" << endl;
	else
		cout << "Stack is growing upwards" << endl;

}

int main(void)
{
	int local;
	stack(&local);
}
