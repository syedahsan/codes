#include<iostream>
using namespace std;

int main(void)
{
	int n;
	int number = 0;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		number = number ^ a[i];
	cout << number << endl;
}
