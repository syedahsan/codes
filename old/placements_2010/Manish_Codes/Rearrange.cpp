#include<iostream>

using namespace std;

union array {
	int num;
	char st;
};

int main(void)
{
	int n,num;
	char s;
	cin >> n;
	union array arr[2*n];
	for(int i=0;i<n;i++)
	{
		cin >> num;
		arr[i].num = num;
	}
	for(int i=n;i<2*n;i++)
	{
		cin >> s;
		arr[i].st = s;
	}
	union array temp = arr[0];
	cout << temp.num << endl;
}
