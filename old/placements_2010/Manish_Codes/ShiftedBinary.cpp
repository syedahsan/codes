#include<iostream>
#include<malloc.h>
using namespace std;

int BinarySearch(int *a, int start, int end,int key)
{
	int mid = (start + end)/2;
	if(start > end) return -1;
	if(a[mid] == key) return mid;
	if(a[start] < a[mid])
	{
		if(a[mid] >= key && a[start] <= key)
			BinarySearch(a,start,mid-1,key);
		else if(a[mid] >= key && a[start] > key)
			BinarySearch(a,mid+1,end,key);
		else if(a[mid] < key)
			BinarySearch(a,mid+1,end,key);
	}
	else
	{
		if(a[end] >= key && a[mid] <=key)
			BinarySearch(a,mid+1,end,key);
		else if(a[end] >= key && a[mid] > key)
			BinarySearch(a,start,mid-1,key);
		else if(a[end] < key)
			BinarySearch(a,start,mid-1,key);
	}
}

int main(void)
{
	int n;
	cin >> n;
	int *a = (int*) malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> a[i];
	int key;
	cin >> key;
	cout << BinarySearch(a,0,n-1,key);
}

