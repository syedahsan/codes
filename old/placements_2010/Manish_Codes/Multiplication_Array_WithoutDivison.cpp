#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int n,product;
	cin >> n;
	vector<int> input(n);
	vector<int> output(n);
	for(int i=0;i<n;i++)
	   cin >> input[i];
	output[0] = 1;
	for(int i=0,product = 1;i<n-1;i++)
	{
		product*= input[i];
		output[i+1] = product;
	}
	for(int i=n-1,product = 1;i>0;i--)
	{
		product*= input[i];
		output[i-1]*= product;
	}
	for(int i=0;i<n;i++)
		cout << output[i] << " ";
	cout << endl;
}

