#include<iostream>
#include<cstdio>
using namespace std;

int Partition(int * const array, int p, int r)
{
	int x = array[r];
	int i = p-1;
	for(int j = p; j < r;j++)
	{
		if(array[j] <= x)
		{
			i = i + 1;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	int temp = array[i+1];
	array[i+1] = array[r];
	array[r] = temp;
	cout << i+1 << endl;
	return i+1; 
}

void Quicksort(int * const array, int p, int r)
{
	if(p < r)
	{
		int q = Partition(array,p,r);
		cout << q << endl;
		Quicksort(array,p,q-1);
		Quicksort(array,q+1,r);
	}
}

int main()
{
	int array[10];
	for(int i=0;i<10;i++)
		cin >> array[i];
	Quicksort(array,0,9);
	for(int i=0;i<10;i++)
		cout << array[i] << " ";
	cout << endl;
}
