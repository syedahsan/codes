#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int *medianarray = (int *)malloc(sizeof(int)*5);
int i;

void insertionsort(int *const array, int count, int jump)
{
	for(int j= count +1 ;j<count+jump;j++)
	{
		int key = array[j];
		int k = j-1;
		while(array[k] > key && k >= count)
		{
			array[k+1] = array[k];
			k--;
		}
		array[k+1] = key;
	}

}

void median(int *const array, int p, int r)
{
	if(r > 5)
	{
		int count =0;
		int number;
		if(r%5 !=0)
			number = r/5 + 1;
		else number = r/5;
		medianarray = (int *)malloc(sizeof(int)*number);
		int remainder;
		int jump = 5;
		for(i=0;i<number;i++)
		{
			if(i == number-1)
			{
				remainder = r%5;
				if(remainder !=0) jump = remainder;
			}
			insertionsort(array,count,jump);
			int index = ((2 * count) + 1 + jump)/2;
			medianarray[i] = array[index-1];
			count+=jump;
		}
		median(medianarray,0,number);
	}
	else
	{
		insertionsort(medianarray,0,i);
		
	}
}

int partition(int *const array,int p, int r)
{
	int mom =  medianarray[i/2]; //medianarray[(int)ceil(i/2)];
	cout << "Mom : " << mom << endl;
	int l = p-1;
	for(int k=p;k<r;k++)
	{
		if(array[k] == mom)
		{
			int temp = array[k];
			array[k] = array[r-1];
			array[r-1] = temp;
			break;
		}
	}
	for(int j=p;j<r;j++)
	{
		if(array[j] <= mom)
		{
			l = l + 1;
			int temp = array[j];
			array[j] = array[l];
			array[l] = temp;
		}
	}
	int temp = array[r-1];
	array[r-1] = array[l+1];
	array[l+1] = temp;
	return l+1;
}

int select(int *const array, int p, int r, int value)
{
	median(array,p,r);
	int partioned = partition(array,p,r);
	cout << "Partioned : " << partioned << endl; 
	if(partioned == value)
		return partioned;
	else if(partioned <  value)
		select(array,partioned+1,r,value-partioned);
	else
		select(array,p,partioned-1,value);
}

int main()
{
	int array[10];
	int value;
	cin >> value;
	for(int k=0;k<10;k++)
		cin >> array[k];
	int index =  select(array,0,10,value);
	cout << array[index];
	cout << endl;
}

