#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n;

	cout<<"enter no. of elements\n";

	cin >> n;

	int a[n];
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=0;
	}
	b[n-1]=1;
	int max_j,max=0;
	for(int i=n-2;i>=0;i--)
	{
		max_j = 0;
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				if(b[j] > max_j)
					max_j = b[j];
			}
		}
		b[i]=max_j+1;
		if(b[i]>max)
			max = b[i];
	}

	cout<<max<<endl;
}

