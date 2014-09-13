#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> coins(n);
	for(int i=0;i<n;i++)
		cin >> coins[i];
	int sum;
	cin >> sum;
	vector<int> maxCoins(sum+1,INT_MAX);
	vector<int> BC(sum+1);
	vector<int> FinalCoins(n,0);
	maxCoins[0] = 0;
	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i >= coins[j])
			{
				if(maxCoins[i-coins[j]]+1 < maxCoins[i])
				{
					maxCoins[i] = maxCoins[i-coins[j]]+1;
					BC[i] = j;
				}

			}
		}
	}
	cout << maxCoins[sum] << endl;
	while(sum > 0)
	{
		FinalCoins[BC[sum]]+=1;
		sum-=coins[BC[sum]];
	}
	for(int i=0;i<n;i++)
		cout << FinalCoins[i] << " ";
	cout << endl;
}
