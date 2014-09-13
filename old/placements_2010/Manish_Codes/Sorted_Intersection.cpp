#include<iostream>
#include<vector>
using namespace std;

void FindIntersection(vector<int> a, vector<int> b, int n, int m)
{
	int Index_A=0,Index_B=0;
	int temp =0;
	while(Index_A <= n  || Index_B <= m) 
	{
		if(a[Index_A] > b[Index_B])
			Index_B++;
		else if(a[Index_A] < b[Index_B])
			Index_A++;
		else
		{
			temp = a[Index_A];
			cout << temp << " ";
			Index_A++;
			Index_B++;
		}
		while(temp == a[Index_A] && temp == b[Index_B])
		{
			Index_A++;
			Index_B++;
		}

	}
}

int main(void)
{
	int n,m;
	cin >> n;
	cin >> m;
	vector<int> array1(n);
	vector<int>array2(n);
	for(int i=0;i<n;i++)
		cin >> array1[i];
	for(int i=0;i<m;i++)
		cin >> array2[i];
	FindIntersection(array1,array2,n-1,m-1);
	cout << endl;
}
