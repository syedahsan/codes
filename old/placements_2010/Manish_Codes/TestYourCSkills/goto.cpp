#include<iostream>
using namespace std;
int main(void)
{
	int i = 1;
	while(i <= 5)
	{
		cout << i << " ";
		if(i < 2)
			goto here;
	}
here:
	cout << "LD Rocks" << endl;
}
