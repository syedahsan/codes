#include<iostream>
#include<vector>
using namespace std;

int BinarySearchToFindStart(vector<int> array, int start, int end)
{
	int mid = (start + end)/2;
	if(start == mid) return end;
	if(array[start] > array[mid])
		return BinarySearchToFindStart(array,start,mid);
	else if(array[mid] > array[end])
		return BinarySearchToFindStart(array,mid,end);
	else if((array[start] == array[mid]) && (array[mid] == array[end]))
	{
		if(BinarySearchToFindStart(array,start,mid) != array[start])
			return BinarySearchToFindStart(array,mid,end);
		else
			return BinarySearchToFindStart(array,start,mid);             
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> array(n,0);
	for(int i=0; i<n;i++)
		cin >> array[i];
	cout << BinarySearchToFindStart(array,0,n-1) << endl;;
}
