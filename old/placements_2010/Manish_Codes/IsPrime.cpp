#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n)
{
	bool flag = true;
	int temp = sqrt(n);
	if(n <= 3)
	{
		flag = false;
	}
	else if( n % 2 == 0)
	{
		flag = false;
	}
	else
	{
		for(int i = 3; i<= temp; i+=2)
		{
			if(n % i == 0)
			{
				flag = false;
				break;
			}
		}
	}
	return flag;
}

int main(void)
{
	int n;
	cin >> n;
	cout << isPrime(n) << endl;
}
