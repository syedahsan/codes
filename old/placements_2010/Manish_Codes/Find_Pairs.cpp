#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Find_Pairs(vector<int> array, int n, int sum)
{
	sort(array.begin(),array.end());
	int start = 0;
	int end = n-1;
	while(start <= end)
	{
		if(array[start] + array[end] > sum)
	           end --;
	        else if(array[start] + array[end] < sum)
		   start++;
		else 
		{
			cout << array[start] << " " << array[end] << endl;
			start++;
			end--;
		}		
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> array(n,0);
	for(int i=0;i<n;i++) 
		cin >> array[i];
	int sum;
	cin >> sum;
	Find_Pairs(array,n,sum);
}
