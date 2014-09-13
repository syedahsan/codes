#include<iostream>
#include<malloc.h>
using namespace std;

char *itoa(int n)
{
	char *destString = (char*)malloc(30);
	char *finalString = destString;
	while(n > 0)
	{
		int digit = n%2;
		n/=2;
		*destString = (char)(digit + '0');
		destString++;
	}
	destString = '\0';
	return finalString;
}

int main(void)
{
	int n;
	cin >> n;
	char *destString;
	destString = itoa(n);
	cout << destString << endl;
}
