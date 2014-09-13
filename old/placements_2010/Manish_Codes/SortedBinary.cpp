#include<iostream>
using namespace std;

int BinarySearch(int *a, int start, int end, int key)
{
	int mid = (start+end)/2;
	if(a[mid] == key)
	{
		if(a[mid-1] != key) return mid; 
		else mid = BinarySearch(a,start,mid-1,key);
	}
	else if(a[mid] > key)
		mid = BinarySearch(a,start,mid-1,key);
	else
		mid = BinarySearch(a,mid+1,end,key);
}

int main(void)
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int key;
	cin >> key;
	cout << BinarySearch(a,0,n,key) << endl;
}
