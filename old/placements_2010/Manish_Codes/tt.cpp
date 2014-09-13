#include<iostream>
using namespace std;

void F1(...){
	int *x = new (int);
	*x = 10; 
	void F2();
	delete x;
	cout << *x << endl;
}

int main(void)
{
	F1(5);

}

