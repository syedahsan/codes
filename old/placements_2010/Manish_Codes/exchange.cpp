#include<iostream>
#include<algorithm>
using namespace std;

typedef union array {
	int num;
	char str;
}intchar;

void exchange(intchar *input, int start, int mid, int end)
{
	for(int i=0;i<mid-start;i++)
	{
		intchar temp;
	        temp = input[start+i];
		input[start+i]=input[mid+i];
		input[mid+i]=temp;
	}

	if(end - start == 2) return;
	exchange(input,start - (mid - start)/2,start,mid - (mid -start)/2);
	exchange(input,mid + (end-mid)/2,end,end + (end - mid)/2);
}

int main(void)
{
	int data;
	char str;
	int n;
	cin >> n;
	intchar input[2*n];
	for(int i=0;i<n;i++)
	{
		cin >> data;
		input[i].num = data;
	}
	for(int i=0;i<n;i++)
	{
		cin  >> str;
		input[n+i].str = str;
	}
	if(n %2 == 1)
	{
		for(int i =1;i<n;i++)
			swap(input[i],input[n+i-1]);
		exchange(input,n/2+1,n,(3*n)/2);     
	}
	else 
		exchange(input,n/2,n,(3*n)/2);
	for(int i=0;i<2*n;i++)
	{
		if(i%2==0)
			cout<< input[i].num<< " ";
		else
			cout<< input[i].str<< " ";
	}
	cout << endl;
}

