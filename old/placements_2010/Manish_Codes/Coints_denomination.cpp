#include<iostream>
#include<climits>
using namespace std;
int main(){
	int n,k,i,j;
	cin >> k;
	int coins[k+1];
	for(i=0;i<k;i++)
		cin >> coins[i];
	cin >> n;
	int maxcoins[n+1],BC[n+1];
	for(i=0;i<=n;i++)
		maxcoins[i]=INT_MAX;
	maxcoins[0]=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(i>=coins[j])
			{
				if(maxcoins[i-coins[j]]+1 < maxcoins[i])
				{
					maxcoins[i] = maxcoins[i-coins[j]]+1;
					BC[i]=j;
				}
			}
		}
	}
	cout << maxcoins[n] << endl;
	int Finalcoins[k+1];
	for(i=0;i<k;i++) Finalcoins[i]=0;
	while(n>0)
	{
		Finalcoins[BC[n]] += 1;
		n-=coins[BC[n]];
	}
	for(i=0;i<k;i++)
		cout <<  Finalcoins[i] << " ";
}
